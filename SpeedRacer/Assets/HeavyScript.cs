using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class HeavyScript : MonoBehaviour
    {
    private bool checkpointing;
    private bool lapping;



 

    private Hv_LaoSFX_AudioLib pd;
    


        // Start is called before the first frame update
    void Start()
    {
        checkpointing = false;
        lapping = false;


        pd = GetComponent<Hv_LaoSFX_AudioLib>();
        
    }

    // Update is called once per frame
    void Update()
    {
    }

    void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("checkpoint") && !checkpointing)
        {
            checkpointing = true;
            pd.SendEvent(Hv_LaoSFX_AudioLib.Event.Checkpointsound);
            Debug.Log("checkpoint Sound");
        }
        if (other.CompareTag("lap") && !lapping)
        {
            lapping = true;
            pd.SendEvent(Hv_LaoSFX_AudioLib.Event.Lapsound);
            Debug.Log("Lap Sound");
        }
    }

    void OnTriggerExit(Collider other)
    {
        if (other.CompareTag("checkpoint"))
            checkpointing = false;
        if (other.CompareTag("lap"))
            lapping = false;
    }
}