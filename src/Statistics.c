#include <math.h>

double Statistics_sum(double arr[], int length) {
	int i = 0;
	double sum = 0;
	for (i = 0; i < length; i++) {
		sum = sum + arr[i];
	}
	return sum;
}
double Statistics_average(double sum, int length) {
	return sum / length;
}
double Statistics_variance(double arr[], int length, double average) {
	double tempArr[length];
	int i = 0;
	for (i = 0; i < length; i++) {
		tempArr[i] = (arr[i] - average) * (arr[i] - average);
	}
	return Statistics_sum(tempArr, length) / length;
}
double Statistics_sampleVariance(double arr[], int length, double average) {
	double tempArr[length];
	int i = 0;
	for (i = 0; i < length; i++) {
		tempArr[i] = (arr[i] - average) * (arr[i] - average);
	}
	return Statistics_sum(tempArr, length) / (length - 1);
}

double Statistics_kOrderDistance(double arr[], int length, int k) {
	double temp[length];
	int i = 0;
	for (i = 0; i < length; i++) {
		temp[i] = pow(arr[i], k);
	}
	return Statistics_sum(temp, length) / length;
}

double Statistics_kOrderConterDistance(double arr[], int length, double average,
		int k) {
	double temp[length];
	int i = 0;
	for (i = 0; i < length; i++) {
		temp[i] = pow(arr[i] - average, k);
	}
	return Statistics_sum(temp, length) / length;
}

