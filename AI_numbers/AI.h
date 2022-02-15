#pragma once
#include <iostream>

class Network
{
public:
	Network();
	~Network();
	float initial[784] = {};
	float first[16] = {};
	float second[16] = {};
	float result[10] = {};
	float initial_first[16][784] = {};
	float first_second[16][16] = {};
	float second_result[10][16] = {};
	float shift_first[16] = {};
	float shift_second[16] = {};
	float shift_result[10] = {};
	void ReadPicture();
	void ShowArr();
	float Sigmoid(float a[], float w[], float b,int count);
	void MakeLayers();
	int GetResult();
	void Study();

private:
	FILE* filePictures, * fileLabels;
	void InitializeWeights();
	float GetError();
	int rightValue;
	float Direvation(float first, float second);

};

