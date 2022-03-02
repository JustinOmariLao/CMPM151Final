using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AudioReactor : MonoBehaviour
{

	private Vector3 originalTran;
	private Vector3 orignalPos;
	private float scale;
	// Start is called before the first frame update
	void Start()
	{
		originalTran = transform.localScale;
		orignalPos = transform.localPosition;
		scale = 1;


	}

	// Update is called once per frame
	void Update()
	{
		int numPartitions = 8;
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
			aveMag[i] = (float)0.5 + aveMag[i] * 100;
			if (aveMag[i] > 100)
			{
				aveMag[i] = 100;
			}
		}
		scale = aveMag[0];

		ScaleAround(orignalPos - new Vector3(0, 2.4F, 0), scale * originalTran);



	}

	void ScaleAround(Vector3 pivot, Vector3 newScale)
	{
		Vector3 A = transform.localPosition;
		Vector3 B = pivot;

		Vector3 C = A - B; // diff from object pivot to desired pivot/origin

		float RS = newScale.x / transform.localScale.x; // relataive scale factor

		// calc final position post-scale
		Vector3 FP = B + C * RS;

		// finally, actually perform the scale/translation
		transform.localScale = newScale;
		transform.localPosition = FP;
	}
}
