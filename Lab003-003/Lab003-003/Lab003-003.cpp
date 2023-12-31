#include "stdafx.h"
#include <iostream>

using namespace std;

#define NUM_ROW 4
#define NUM_COLUMN 4
#define NUM_DEPTH 3

double findMinMax(double value[NUM_ROW][NUM_COLUMN][NUM_DEPTH], double &minValue, double &maxValue);
double findAvg(double value[NUM_ROW][NUM_COLUMN][NUM_DEPTH], double &avg);
double MaxDiff(double value[NUM_ROW][NUM_COLUMN][NUM_DEPTH]);

int main()
{
	double minVal, maxVal, avg;
	//double maxD[4][4][3];
	
	double value[NUM_ROW][NUM_COLUMN][NUM_DEPTH] =
	{
		{ { 1.1, 1.2, 1.3 },{ 1.4, 1.5, 1.6 },{ 1.7, 1.8, 1.9 },{ 2.0, 2.1, 2.2 } },
		{ { 2.1, 2.2, 2.3 },{ 2.4, 2.5, 2.6 },{ 2.7, 2.8, 2.9 },{ 3.0, 3.1, 3.2 } },
		{ { 3.1, 3.2, 3.3 },{ 3.4, 3.5, 3.6 },{ 3.7, 3.8, 3.9 },{ 4.0, 4.1, 4.2 } },
		{ { 4.1, 4.2, 4.3 },{ 4.4, 2.5, 2.6 },{ 2.7, 2.8, 2.9 },{ 3.0, 3.1, 3.2 } }
	};

	findMinMax(value, minVal, maxVal);
	findAvg(value, avg);
	MaxDiff(value);

	system("pause");
	return 0;
}

double findMinMax(double value[NUM_ROW][NUM_COLUMN][NUM_DEPTH], double &minValue, double &maxValue)
{

	minValue = value[0][0][0];
	maxValue = value[0][0][0];

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 3; k++)
			{
				if (value[i][j][k] < minValue)
				{
					minValue = value[i][j][k];
				}
				else if (value[i][j][k] > maxValue)
				{
					maxValue = value[i][j][k];

				}
			}

	cout << "Max: " << maxValue << endl;
	cout << "Min: " << minValue << endl;

	return 0;
}

double findAvg(double value[NUM_ROW][NUM_COLUMN][NUM_DEPTH], double &avg)
{
	double sum = 0;
	double count = 0;
	
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 3; k++)
			{
				sum += value[i][j][k];
				count++;
			}

	avg = sum / count;

	cout << "Average: " << avg << endl;

	return 0;
}

double MaxDiff(double value[NUM_ROW][NUM_COLUMN][NUM_DEPTH])
{
	double Diff;
	double maxDiff = 0, diff_x, diff_y, diff_z;
	int maxX = 0, maxY = 0, maxZ = 0;
	

	for (int i = 0; i < NUM_ROW - 2; i++)
	{
		for (int j = 0; j < NUM_COLUMN - 2; j++)
		{
			for (int k = 0; k < NUM_DEPTH - 2; k++)
			{
				diff_x = value[i][j][k] - value[i + 1][j][k];
				diff_y = value[i][j][k] - value[i][j + 1][k];
				diff_z = value[i][j][k] - value[i][j][k + 1];
				
				if (diff_x > maxDiff)
				{
					maxDiff = diff_x;
					maxX = i;
					maxY = j;
					maxZ = k;
				}
				if (diff_y > maxDiff)
				{
					maxDiff = diff_y;
					maxX = i;
					maxY = j;
					maxZ = k;
				}
				if (diff_z > maxDiff)
				{
					maxDiff = diff_z;
					maxX = i;
					maxY = j;
					maxZ = k;
				}

			}
		}
	}
	
	cout << "Maximum Difference: " << maxDiff << endl << "Location: (" << maxX << ", " << maxY << ", " << maxZ << ")" << endl;

	return 0;
}