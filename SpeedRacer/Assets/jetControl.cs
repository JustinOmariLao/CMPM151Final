using System.Collections;
using System.Collections.Generic;
using UnityEngine;


namespace KartGame.KartSystems
{
    public class jetControl : MonoBehaviour
    {
        public float sped;
        private Hv_JetEngine_AudioLib pd;
        // Start is called before the first frame update
        ArcadeKart arcadeKart;

        void Awake()
        {
            arcadeKart = GetComponentInParent<ArcadeKart>();
        }

        void Start()
        {
            sped = 0;
          
            pd = GetComponent<Hv_JetEngine_AudioLib>();
        }

        // Update is called once per frame
        void Update()
        {
            sped = arcadeKart.LocalSpeed() *0.75F;
            sped = Mathf.Clamp(sped, 0, 1);
            pd.SetFloatParameter(Hv_JetEngine_AudioLib.Parameter.Sped, sped);
        }
    }
}
