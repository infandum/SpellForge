using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace SpellForge
{
    public class SpellSeekerDelivery : SpellDeliveryType
    {
        [SerializeField]
        protected Vector2 _minMaxSpeed = new Vector2(1.0f, 10.0f);

        [SerializeField]
        protected float _acceleration = 0.0f;

        [SerializeField, ReadOnly]
        protected float _currentSpeed = 0.0f;
        

        protected override void OnValidate()
        {
            base.OnValidate();
        }

        protected override void Awake()
        {
            base.Awake();
        }

        protected override void Start()
        {
            base.Start();
        }

        protected override void Update()
        {
            base.Update();

            switch (SpellState)
            {
                case SpellState.IDLE:
                    break;
                case SpellState.START:
                    break;
                case SpellState.CHARGE_UP:
                    break;
                case SpellState.CHARGE_OVER:
                    break;
                case SpellState.HOLDING:
                    break;
                case SpellState.CAST:

                    float step = _currentSpeed * Time.deltaTime; // calculate distance to move
                    transform.position = Vector3.MoveTowards(transform.position, _targetTransform.position, step);

                    _currentSpeed = _currentSpeed + (_acceleration * Time.deltaTime);

                    break;
                case SpellState.ACTIVE:
                    break;
                case SpellState.OVERCHARGED:
                    break;
                case SpellState.COOLDOWN:
                    break;
                case SpellState.END:
                    break;
                default:
                    break;
            }
        }

        protected override void Setup()
        {
            base.Setup();

            if(_acceleration > 0.0f)
            {
                _currentSpeed = _minMaxSpeed.x;
            }
            else if(_acceleration < 0.0f)
            {
                _currentSpeed = _minMaxSpeed.y;
            }
            else
            {
                _currentSpeed = _minMaxSpeed.y;
            }
        }

        protected override void Activate()
        {
            base.Activate();
        }

        protected override void Delivered()
        {
            base.Delivered();
        }
    }
}
