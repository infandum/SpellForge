using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Events;

namespace SpellForge
{
    public class SpellEventManager : MonoBehaviour
    {
        #region Data members
        private Dictionary<string, UnityEvent> _eventDictionary;

#if UNITY_EDITOR
        [SerializeField, ReadOnly]
        private List<string> _eventList;
#endif

        [SerializeField]
        private static bool _createOnLoad = true;
        [SerializeField]
        private static bool _dontDestroyOnLoad = true;

        #region Properties
        private static SpellEventManager _instance;

        public static SpellEventManager Instance
        {
            get
            {
                if (!_instance)
                {
                    _instance = FindObjectOfType(typeof(SpellEventManager)) as SpellEventManager;

                    if (!_instance)
                    {
                        SafeDebug.Log("SpellEventManager.Instance >> No SpellEventManager found!");
                        if (_createOnLoad)
                        {
                            SafeDebug.Log("SpellEventManager.Instance >> SpellEventManager Created!");
                            GameObject obj = new GameObject();
                            obj.name = "SpellEventManager";
                            _instance = obj.AddComponent<SpellEventManager>();
                        }
                    }
                    else
                    {
                        _instance.Init();
                    }
                }

                return _instance;
            }
        }
        #endregion

        #endregion

        #region Unity Methods
        private void OnValidate()
        {
#if UNITY_EDITOR
            _eventList.Clear();
            _eventList = null;
#endif
        }

        private void Awake()
        {
            CheckInstance();
        }

        #endregion

        #region Private Methods
        private bool CheckInstance()
        {
            if (Instance == null)
            {
                _instance = this;
                return true;
            }
            else if (Instance == this)
            {
                return true;
            }

            Destroy(this);
            SafeDebug.Log($"SpellEventManager.CheckInstance() >> SpellEventManager already instanced! removing duplicate Destroy({this}) || {this.name};");

            return false;
        }

        private void Init()
        {
            if (_eventDictionary == null)
            {
                _eventDictionary = new Dictionary<string, UnityEvent>();

#if UNITY_EDITOR
                _eventList = new List<string>();
#endif
            }

            if (_dontDestroyOnLoad)
            {
                SafeDebug.Log($"SpellEventManager.CheckInstance() >> DontDestroyOnLoad({this})");
                DontDestroyOnLoad(this);
            }
        }

        #endregion

        #region Public Methods
        public static void StartEventListener(string eventName, UnityAction listener)
        {
            eventName = eventName.ToLowerInvariant();
            if (Instance._eventDictionary.TryGetValue(eventName, out UnityEvent thisEvent))
            {
                thisEvent.AddListener(listener);

            }
            else
            {
                thisEvent = new UnityEvent();
                thisEvent.AddListener(listener);
                Instance._eventDictionary.Add(eventName, thisEvent);

#if UNITY_EDITOR
                Instance._eventList.Add(eventName);
#endif

            }
        }

        public static void StopEventListener(string eventName, UnityAction listener)
        {
            eventName = eventName.ToLowerInvariant();

            if (_instance == null) return;

            if (Instance._eventDictionary.TryGetValue(eventName, out UnityEvent thisEvent))
            {
                thisEvent.RemoveListener(listener);
#if UNITY_EDITOR
                Instance._eventList.Add(eventName);
#endif
            }
        }

        public static void TriggerEvent(string eventName)
        {
            eventName = eventName.ToLowerInvariant();

            if (Instance._eventDictionary.TryGetValue(eventName, out UnityEvent thisEvent))
            {
                thisEvent.Invoke();
            }
        }

        #endregion

    }
}

