using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class checkpointreactor : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
		int numPartitions = 4;
		float[] aveMag = new float[numPartitions];
		float partitionIndx = 0;
		int numDisplayedBins = 512 / 2; //NOTE: we only display half the spectral data because the max displayable frequency is Nyquist (at half the num of bins)

		for (int i = 0; i < numDisplayedBins; i++)
		{
			if (i < numDisplayedBins * (partitionIndx + 1) / numPartitions)
			{
				aveMag[(int)partitionIndx] += AudioSpecData.spectrumData[i] / (512 / numPartitions);
			}
			else
			{
				partitionIndx++;
				i--;
			}
		}

		//scale and bound the average magnitude.
		for (int i = 0; i < numPartitions; i++)
		{
			aveMag[i] = (float)0.5 + aveMag[i] * 1;
			if (aveMag[i] > 2)
			{
				aveMag[i] = 1;
			}
		}

		gameObject.GetComponent<MeshRenderer>().material.color =  new Color(aveMag[0], aveMag[1], aveMag[2], 1);

	}
}
