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
        CHARGE_OVER,
        HOLDING,
        CAST,
        ACTIVE,
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

        public enum SpellTimingEnum : uint
        {
            Instant,
            Casting,
            Charging,
        }

        private SpellState _spellState = SpellState.IDLE;
        public SpellState SpellState { get => _spellState; set => _spellState = value; }

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
        }

        #endregion

        private void Activate()
        {
            //SafeDebug.Log("SpellObject >> Activate!");

        }
    }
}

