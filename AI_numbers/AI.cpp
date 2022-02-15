#define _CRT_SECURE_NO_WARNINGS
#include "AI.h"
#include <cstdlib>
void Network::ReadPicture()
{	
	unsigned char temp;
	for (int i = 0; i < 28*28; i++)
	{
		fscanf(filePictures, "%c", &temp);
		initial[i] = (float)temp / 255;
	}
	fscanf(fileLabels, "%c", &rightValue);
}
Network::Network()
{
	filePictures = fopen("../images/train-images.idx3-ubyte", "rb");
	fseek(filePictures, 16, SEEK_SET);
	fileLabels = fopen("../images/train-labels.idx1-ubyte", "rb");
	fseek(fileLabels, 8, SEEK_SET);
	InitializeWeights();
}

Network::~Network()
{
	fclose(filePictures);
}

void Network::ShowArr()
{
	for (size_t i = 0; i < 28; i++)
	{
		for (int j = 0; j < 28; j++)
		{
			printf("%4.2f%s", initial[28 * i + j], " ");
		}
		printf("\n");
	}
}
void Network::InitializeWeights()
{
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		shift_result[i] = (float)(rand() % 301 - 150) / 100;
	}
	for (int i = 0; i < 16; i++)
	{		
		shift_first[i] = (float)(rand() % 301 - 150) / 100;
		shift_second[i] = (float)(rand() % 301 - 150) / 100;		
	}
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			first_second[i][j]= (float)(rand() % 301 - 150) / 100;
		}
		for (int j = 0; j < 784; j++)
		{
			initial_first[i][j] = (float)(rand() % 301 - 150) / 100;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			second_result[i][j] = (float)(rand() % 301 - 150) / 100;
		}
		
	}
}

float Network::Sigmoid(float a[], float w[], float b,int count)
{
	float result = 0;

	for (int i = 0; i < count; i++)
	{
		result += a[i] * w[i];
	}
	result += b;
	return 1 / (1 + exp(-1 * result));
}

void Network::MakeLayers()
{
	//fill first layer
	for (int i = 0; i < 16; i++)
	{
		first[i] = Sigmoid(initial, initial_first[i], shift_first[i],784);
	}
	//fill second layer
	for (int i = 0; i < 16; i++)
	{
		second[i] = Sigmoid(first, first_second[i], shift_second[i],16);
	}
	//fill result
	for (int i = 0; i < 10; i++)
	{
		result[i] = Sigmoid(second, second_result[i], shift_result[i],16);
	}
}

int Network::GetResult()
{
	int maxIndex = 0;
	float maxValue = result[0];
	for (int i = 1; i < 10; i++)
	{
		if (result[i] > maxValue)
		{
			maxValue = result[i];
			maxIndex = i;
		}
	}
	return maxIndex;
}

float Network::GetError()
{
	float error = 0;
	for (int i = 0; i < rightValue; i++)
	{
		error += result[i] * result[i];
	}
	error += (1 - result[rightValue]) * (1 - result[rightValue]);
	for (int i = rightValue+1; i < 10; i++)
	{
		error += result[i] * result[i];
	}
	return error;
}

float Direvation(float first, float second)
{

	return 0;
}

void Network::Study()
{
	for (int i = 0; i < rightValue; i++)
	{
		// decree
	}
	//incree
	for (int i = rightValue+1; i < 10; i++)
	{
		// decree
	}
}