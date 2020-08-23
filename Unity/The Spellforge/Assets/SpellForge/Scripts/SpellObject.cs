using System.Collections;
using System.Collections.Generic;
using System.ComponentModel.Design;
using UnityEngine;
using UnityEngine.Events;

namespace SpellForge
{
    public enum SpellState : uint
    {
        IDLE = 0,
        START,
        CHARGE_UP,
        CHARGE_HOLD,
        CAST,
        OVERCHARGED,
        COOLDOWN,
        END,
    }

    public class SpellObject : MonoBehaviour
    {
        
        public Transform testTarget;
        public enum SpellType : uint
        {
            Hitscan,
            Target_Self,
            Target_Other,
            Area,
            Projectile,
            Projectile_Targeted,
            Projectile_Area,
        }

        public enum SpellDeliveryEnum : uint
        {
            Hitscan,
            Projectile,
            Seeker,
            Area,
        }

        private SpellState _spellState = SpellState.IDLE;
        public SpellState SpellState { get => _spellState; set => _spellState = value; }

        //Target
        //Event
        //Stats
        //
        #region Unity Methods
        void OnEnable()
        {

            //SpellEventManager.StartEventListener("test", Activate);
        }

        void OnDisable()
        {
            //SpellEventManager.StopEventListener("test", Activate);
        }

        void Awake()
        {

        }

        void Start()
        {

        }

        void Update()
        {
            if (Input.GetKeyDown("q"))
            {
                SpellEventManager.TriggerEvent("Activate");
            }

            if (Input.GetKeyDown("r"))
            {
                SpellEventManager.TriggerEvent("Init");
            }


            float step = 10 * Time.deltaTime; // calculate distance to move
            transform.position = Vector3.MoveTowards(transform.position, testTarget.position, step);
        }

        #endregion

        private void Activate()
        {
            //SafeDebug.Log("SpellObject >> Activate!");

        }
    }
}

