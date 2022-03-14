using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// This class inherits from TargetObject and represents a LapObject.
/// </summary>
public class LapObject : TargetObject
{

    [Header("LapObject")]
    [Tooltip("Is this the first/last lap object?")]
    public bool finishLap;
    

    [HideInInspector]
    public bool lapOverNextPass;

    void Start() {
        Register();

    }
    
    void OnEnable()
    {
        lapOverNextPass = false;
    }

    private void OnTriggerEnter(Collider other)
    {
        if (!((layerMask.value & 1 << other.gameObject.layer) > 0 && other.CompareTag("Player")))
            return;

        //AudioUtility.CreateSFX(CollectSound, transform.position, AudioUtility.AudioGroups.Pickup, 0f);
        Objective.OnUnregisterPickup?.Invoke(this);
    }
}
