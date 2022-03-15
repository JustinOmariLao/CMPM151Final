using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;

public class MenuNavigation : MonoBehaviour
{
    private Hv_LaoSFX_AudioLib pd;
    public Selectable defaultSelection;

    private float timer;

    void Start()
    {
        timer = 0;
        Cursor.lockState = CursorLockMode.None;
        Cursor.visible = true;
        EventSystem.current.SetSelectedGameObject(null);

        pd = GetComponent<Hv_LaoSFX_AudioLib>();
    }

    void Update()
    {
        if (timer >= 0) timer -= Time.deltaTime;
        else
        {
            pd.SetFloatParameter(Hv_LaoSFX_AudioLib.Parameter.Buttonsound, 0);
            if (Input.GetButtonDown("Vertical"))
            {
                pd.SetFloatParameter(Hv_LaoSFX_AudioLib.Parameter.Buttonsound, 1);
                timer = 1F;
                Debug.Log("sound plays");
            }
        }

    }

    void LateUpdate()
    {
        if (EventSystem.current.currentSelectedGameObject == null)
        {
            if (Input.GetButtonDown(GameConstants.k_ButtonNameSubmit)
                || Input.GetAxisRaw(GameConstants.k_AxisNameHorizontal) != 0
                || Input.GetAxisRaw(GameConstants.k_AxisNameVertical) != 0)
            {
                
                    EventSystem.current.SetSelectedGameObject(defaultSelection.gameObject);


                
            }

        }
       
    }
}
