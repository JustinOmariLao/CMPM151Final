using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MenuUI : MonoBehaviour
{
    public GameObject playButton;
    public GameObject controlButton;
    public GameObject optionButton;
    public GameObject quitButton;
    public GameObject res1920Button;
    public GameObject res2560Button;
    public GameObject backButton;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void optionMenu() {
        playButton.SetActive(!playButton.activeSelf);
        controlButton.SetActive(!controlButton.activeSelf);
        optionButton.SetActive(!optionButton.activeSelf);
        quitButton.SetActive(!quitButton.activeSelf);

        res1920Button.SetActive(!res1920Button.activeSelf);
        res2560Button.SetActive(!res2560Button.activeSelf);
        backButton.SetActive(!backButton.activeSelf);
    }

    public void resChange(int resolution) {
        if (resolution == 1920) {
            Screen.SetResolution(1920, 1080, FullScreenMode.FullScreenWindow);
        }
        if (resolution == 2560) {
            Screen.SetResolution(2560, 1440, FullScreenMode.FullScreenWindow);
        }
    }
    
    public void quitGame() {
        Application.Quit();
    }
}
