/*
Course: CS315 Algorithms JWJ CS UK
Author: Lauren Bassett
12156078
Project: PA1
Algorithm: Merge Sort
Compilation: g++ pa1f19.cpp
Run: ./a.out < Tests/b#in > bb#.out

NOTE!!! I can't figure out how to best find the Lc distance without
rounding errors for smaller values. 
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

//I left all of my failed attempts commented out so I could retrace my thought process.

/* 
Referenced:
http://www.cplusplus.com/doc/tutorial/files/
http://www.cplusplus.com/reference/istream/istream/get/
http://www.cplusplus.com/reference/vector/vector/vector/
https://www.geeksforgeeks.org/sum-manhattan-distances-pairs-points/
https://mukeshiiitm.wordpress.com/2008/05/27/find-the-farthest-pair-of-points/
http://www.cplusplus.com/reference/iomanip/setprecision/
https://www.programiz.com/cpp-programming/library-function/cmath/sqrt
http://www.cplusplus.com/forum/general/240920/
*/

using namespace std;
//declaring the functions for later;
long long Merge(long long array[], long long placeholder[], int LeftValue, int Median, int RightValue);
long long MSort(long long array[], int LeftValue, int RightValue, long long size);
//int SumArray(long long arr[], int n); <- Thought I could cut corners by summing the arrays seperatley and adding them together, nope. 

long long Merge(long long arr[], long long placeholder[],int LeftValue, int Median, int RightValue) {
	int i = LeftValue;
	int j = Median;
	int k = LeftValue; //so we know when we end
	long long NumOfSwaps = 0;

	//So all of this is wrong, but this was my original attempt at MergeSort
	//int TempLeft[n1];
	//int TempRight[n2]; <- I thought I could create the dummy arrays locally
	//for (i = 0; i < n1; i++)
		//TempLeft[i] = arr[LeftValue + i];
	//for (j = LeftValue; j < n2; j++)
		//TempRight[j] = arr[Median + 1 + j];

	//i = 0; j = 0; k = LeftValue;
	//while (i < n1 && j < n2) {
		//if (TempLeft[i] <= TempRight[j]) {
			//arr[k] = TempLeft[i];
			//i++;
	//	}
		//else {
			//arr[k] = TempRight[j];
			//j++;
		//}
		//k++;
//	}

	//while (i < n1) {
		//arr[k] = TempLeft[i];
		//i++;
		//k++;
	//}
	//while (j < n2) {
		//arr[k] = TempRight[j];
		//j++;
		//k++;
//	}

	while ((i <= Median - 1) && (j <= RightValue)) { //this is the sorting part. 
		if (arr[i] <= arr[j]) {
			placeholder[k++] = arr[i++];
		}
		else {
			placeholder[k++] = arr[j++];
			NumOfSwaps = NumOfSwaps + Median -i;
		}
	}
	while (i <= Median - 1) {
		placeholder[k++] = arr[i++];
	}
	while (j <= RightValue) { 
		placeholder[k++] = arr[j++];
	}
	for (i = LeftValue; i <= RightValue; i++) {
		arr[i] = placeholder[i];
	}
	return NumOfSwaps;
}


	long long MSort(long long arr[], int LeftValue, int RightValue, long long size) {
		long long NumOfSwaps = 0;
		long long *Placeholder = new long long[size];
		int MedianValue = (RightValue + LeftValue) / 2;
		if (RightValue > LeftValue) {
			
			NumOfSwaps = MSort(arr, LeftValue, MedianValue,size);
			NumOfSwaps += MSort(arr, MedianValue + 1, RightValue, size);
			NumOfSwaps += Merge(arr, Placeholder, LeftValue, MedianValue+1, RightValue);
		}
		return NumOfSwaps;
	}

	//int SumArray(long long arr[], int n) {
		//in n-dimensions is called L1 and distance is defined as 
		//sum of abs values between xi-yi.
	//	int NumOfSwaps = MSort(arr, arr[0], arr[n - 1]);
		
	//	int result = 0, sum = 0;
	//	for (int i = 0; i < n; i++) {
		//	result += (arr[i] * i - sum);
			//sum += arr[i];
		//}
		//return result;
//	}


int main() {
	//initialize everything
	double L1Distance = 0;
	double L2Distance = 0;
	double LcDistance = 0; 
	double LcNumr = 0; double LcDenomX = 0; double LcDenomY = 0;
	double LnDistance = 0;
	double LiDistance = 0;
	long long int lengthofarray = 0;
	double numberofswaps = 0;

	//First line in, get N permutations:
	cin >> lengthofarray;

	//Now that we have the size, we can dynamically allocate array 
	//to accomodate the size. 
	//Found here: https://www.learncpp.com/cpp-tutorial/6-9a-dynamically-allocating-arrays/
	//We are going to use that for all the arrays.
	long long* xVector = new long long[lengthofarray];
	long long* yVector = new long long[lengthofarray];
	
	//Now we populate the arrays from the stream 
	for (int i = 0; i < lengthofarray; i++) //Get the first x values
		cin >> xVector[i];
	for (int i = 0; i < lengthofarray; i++) //Get the rest 
		cin >> yVector[i];

	//leaving this code here, I used this to test
	//long long xVector[] = {7,2,3,1,4,6,5};
	//long long yVector[] = {4,2,3,5,1,6,7}; 


	//Do I need these?
	//int SumOfX = SumArray(xVector, lengthofarray);
	//int SumOfY = SumArray(yVector, lengthofarray);
	//cout << SumOfX << SumOfY <<endl;
	//Third line, lines n+2 through 2*n+ contain b

	//L1Distance = abs(SumOfX - SumOfY);

	//int SumXSq = SumOfX * SumOfX;
	//int SumYSq = SumOfY * SumOfY;
	//L2Distance = sqrt(SumXSq - SumYSq);
	
	
	//LnDistance = 

	for (int i = 0; i < lengthofarray; i++) {
		int absVal = abs(xVector[i] - yVector[i]);
		if (absVal > LnDistance)
			LnDistance = absVal; //this is how we check for the max distance
		L1Distance += absVal;
		L2Distance += pow(absVal,2); //doesn't matter, a square is a square, this saves us a step
		LcNumr += (xVector[i] * yVector[i]);
		LcDenomX += pow(xVector[i], 2); // * xVector[i]);
		LcDenomY += pow(yVector[i], 2); // * yVector[i]);
	}

	L2Distance = sqrt(L2Distance); //square the sum
	LcDistance = LcNumr / ((sqrt(LcDenomX)) * (sqrt(LcDenomY))); //crazy math
	//LiDistance = MSort(xVector, xVector[0], xVector[lengthofarray-1], lengthofarray); //sort for swaps
	
	//Look at you go Lauren! Woohoo! 
	//One last thing, gotta count the inversions! 
	long long* YInvertMe = new long long[lengthofarray];
	//long long* xVector = new long long[lengthofarray];
	for (int i = 0; i < lengthofarray; i++) {
		YInvertMe[yVector[i] - 1] = i++;
	}

	long long* XInvertMe = new long long[lengthofarray];
	
	for (int i = 0; i < lengthofarray; i++) {
		XInvertMe[i] = YInvertMe[xVector[i]-1];
	}

	LiDistance = MSort(XInvertMe, XInvertMe[0], (lengthofarray - 1), lengthofarray+1);

	//print statements 
	cout << "Author: leb6078" << endl;
	cout << "L1 distance: " << setprecision(4) << setw(6) << L1Distance << endl;
	cout << "L2 Distance: " << setprecision(4) << setw(6) << L2Distance << endl;
	cout << "Lc Distance: " << setprecision(4) << setw(6) << LcDistance << endl;
	cout << "Ln Distance: " << setprecision(4) << setw(6) <<LnDistance << endl;
	cout << "Li Distance: " << setprecision(4) << setw(6) << LiDistance << endl;
	fflush(stdin);
	return 0;
}
