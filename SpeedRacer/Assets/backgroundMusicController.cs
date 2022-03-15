using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace KartGame.KartSystems
{
    public class backgroundMusicController : MonoBehaviour
    {
        private Hv_musicMaster_AudioLib pd;
        ArcadeKart arcadeKart;
        private float sped;
        // Start is called before the first frame update
        void Awake()
        {
            arcadeKart = GetComponentInParent<ArcadeKart>();
        }

        void Start()
        {
            pd = GetComponent<Hv_musicMaster_AudioLib>();
            pd.SendEvent(Hv_musicMaster_AudioLib.Event.Start);
            pd.SetFloatParameter(Hv_musicMaster_AudioLib.Parameter.Metro, 0.4F);
            pd.SetFloatParameter(Hv_musicMaster_AudioLib.Parameter.Vamp, 0.4F);
        }

        // Update is called once per frame
        void Update()
        {
            sped = arcadeKart.LocalSpeed();
            if(sped > 0.4 && sped <0.6)
            {
                pd.SetFloatParameter(Hv_musicMaster_AudioLib.Parameter.Metro, sped);
                pd.SetFloatParameter(Hv_musicMaster_AudioLib.Parameter.Vamp, sped);
                pd.SetFloatParameter(Hv_musicMaster_AudioLib.Parameter.Drums, sped-0.4F);
            }
            else if(sped >0.6)
            {
                pd.SetFloatParameter(Hv_musicMaster_AudioLib.Parameter.Metro, sped);
                pd.SetFloatParameter(Hv_musicMaster_AudioLib.Parameter.Vamp, sped);
                pd.SetFloatParameter(Hv_musicMaster_AudioLib.Parameter.Drums, sped - 0.4F);
                pd.SetFloatParameter(Hv_musicMaster_AudioLib.Parameter.Melody, 2*(sped - 0.6F));
            }
            else
            {
                pd.SetFloatParameter(Hv_musicMaster_AudioLib.Parameter.Metro, 0.4F);
                pd.SetFloatParameter(Hv_musicMaster_AudioLib.Parameter.Vamp, 0.4F);
                pd.SetFloatParameter(Hv_musicMaster_AudioLib.Parameter.Drums, 0.0F);
                pd.SetFloatParameter(Hv_musicMaster_AudioLib.Parameter.Melody, 0.0F);
            }
        }
    }
}
