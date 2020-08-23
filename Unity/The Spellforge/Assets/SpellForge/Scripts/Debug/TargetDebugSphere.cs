using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TargetDebugSphere : MonoBehaviour
{
    [SerializeField]
    private Color _color = Color.white;

    [SerializeField]
    private float _radius = 1.0f;


    void OnDrawGizmosSelected()
    {
        Gizmos.color = _color;
        Gizmos.DrawSphere(transform.position, _radius);
    }
}
