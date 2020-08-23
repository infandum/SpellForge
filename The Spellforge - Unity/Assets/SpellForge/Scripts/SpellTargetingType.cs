using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace SpellForge
{
    public class SpellTargetingType : MonoBehaviour
    {
        private SpellObject _spellParent;

        public float thrust = 1.0f;
        public Rigidbody rb;

        // Start is called before the first frame update
        void Awake()
        {
            TryGetComponent(out _spellParent);
            TryGetComponent(out rb);
        }

        // Update is called once per frame
        void Update()
        {
            //if (Input.GetKeyDown("q"))
            //{
            //    SpellEventManager.TriggerEvent("test");
            //}

            
        }

        void OnEnable()
        {

            SpellEventManager.StartEventListener("Activate", Activate);
            SpellEventManager.StartEventListener("Init", Init);

        }

        void OnDisable()
        {
            SpellEventManager.StopEventListener("Activate", Activate);
            SpellEventManager.StopEventListener("Init", Init);

        }

        private void Activate()
        {
            SafeDebug.Log("SpellObject >> Activate!");
            rb.isKinematic = false;
            rb.AddForce(transform.forward * thrust);
        }

        private void Init()
        {
            rb.isKinematic = true;
            rb.velocity = Vector3.zero;
        }
    }

}
