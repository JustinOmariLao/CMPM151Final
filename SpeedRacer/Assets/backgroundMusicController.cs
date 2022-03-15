using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class backgroundMusicController : MonoBehaviour
{
    private Hv_musicMaster_AudioLib pd;
    // Start is called before the first frame update
    void Start()
    {
        pd = GetComponent<Hv_musicMaster_AudioLib>();
        pd.SendEvent(Hv_musicMaster_AudioLib.Event.Start);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
