using System.Collections;
using System.Collections.Generic;
using System.ComponentModel.Design;
using UnityEngine;
using UnityEngine.Events;

public class SpellObject : MonoBehaviour
{
    public enum SpellType : uint
    {
        Hitscan,
        Projectile,
        Projectile_Target,
    }
    //Target
    //Event
    //Stats
    //
    #region Unity Methods
    void OnEnable()
    {
       
        SpellEventManager.StartEventListener("test", Activate);
    }

    void OnDisable()
    {
        SpellEventManager.StopEventListener("test", Activate);
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
            SpellEventManager.TriggerEvent("test");
        }

    }

    #endregion

    private void Activate()
    {
        SafeDebug.Log("SpellObject >> Activate!");

    }
}
