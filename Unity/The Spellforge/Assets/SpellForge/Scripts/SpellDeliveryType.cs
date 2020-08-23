using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;

namespace SpellForge
{
    public abstract class SpellDeliveryType : MonoBehaviour
    {
        [SerializeField, ReadOnly]
        protected SpellObject _spellParent;

        [SerializeField, ReadOnly]
        private SpellState _spellState;
        public SpellState SpellState 
        {
            get 
            { 
                return _spellState = _spellParent.SpellState; 
            }
        }

        protected virtual void OnValidate()
        {
            Setup();
        }

        protected virtual void Awake()
        {
            Setup();
        }

        protected virtual void Start()
        {

        }

        protected virtual void Update()
        {
            _spellState = SpellState;
        }

        protected virtual void Setup()
        {
            TryGetComponent(out _spellParent);
        }

        protected virtual void Activate()
        {

        }

        protected virtual void Delivered()
        {

        }
    }
}
