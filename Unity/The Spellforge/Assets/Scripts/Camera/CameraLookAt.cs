using System.Collections;
using System.Collections.Generic;
using UnityEngine;

#if UNITY_EDITOR
[ExecuteInEditMode]
#endif
public class CameraLookAt : MonoBehaviour
{
    [SerializeField]
    private bool _allowEditorUpdate = false;

    [SerializeField]
    private Camera _camera;
    public Camera Camera { get => _camera; private set => _camera = value; }

    [SerializeField]
    private Transform _target;
    public Transform Target 
    {
        get 
        {
            return _target;
        }
        set
        {
            _target = value;
        }
    }


    private void OnValidate()
    {
        if(_camera == null)
        {
            TryGetComponent(out _camera);
            
            if (_camera == null)
            {
                foreach (Transform child in transform)
                {
                    child.TryGetComponent(out _camera);
                    if (_camera != null)
                        break;
                }
            }
        }

        if (_target == null || !_allowEditorUpdate || _camera == null)
            return;

        transform.LookAt(_target);
        _camera.transform.LookAt(_target);
    }

    void Update()
    {

#if UNITY_EDITOR
        if (!_allowEditorUpdate)
            return;
#endif

        if (_target == null || _camera == null)
            return;

        
        transform.LookAt(_target);
        _camera.transform.LookAt(_target);
    }

    //void OnDrawGizmosSelected()
    //{
    //    Gizmos.color = Color.white;
    //    //Gizmos.DrawFrustum(_camera.transform.position, _camera.fieldOfView, _camera.farClipPlane, _camera.nearClipPlane, _camera.aspect);
    //}
}
