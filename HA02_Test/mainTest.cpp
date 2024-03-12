/*

// sort algorithm example
#include <iostream>     // cout
#include <algorithm>    // sort
#include <vector>       // vector
//#include "TestQuickSort.h"

using namespace std;  

// um absteigend zu sortieren
bool vergleiche(int i, int j) { return (i > j); }


// CPP program for implementation of QuickSelect 
//#include <bits/stdc++.h> 
//using namespace std;

// Standard partition process of QuickSort(). 
// It considers the last element as pivot 
// and moves all smaller element to left of 
// it and greater elements to right 
int partition(int arr[], int l, int r)
{
	int x = arr[r];
	int i = l-1;// ursprünglich nur l
	for (int j = l; j <= r - 1; j++) {
		if (arr[j] <= x) {
			i++;
			swap(arr[i], arr[j]);
			//i++; // davor wars hier
		}
	}
	//swap(arr[i], arr[r]);
	swap(arr[i+1], arr[r]);
	
	return i+1; // davor nur i
}

// This function returns k'th smallest  
// element in arr[l..r] using QuickSort  
// based method.  ASSUMPTION: ALL ELEMENTS 
// IN ARR[] ARE DISTINCT 
int kthSmallest(int arr[], int l, int r, int k)
{
	// If k is smaller than number of  
	// elements in array 
	if (k > 0 && k <= r - l + 1) {

		// Partition the array around last  
		// element and get position of pivot  
		// element in sorted array 
		int index = partition(arr, l, r);

		// If position is same as k 
		if (index - l == k - 1)
			return arr[index];

		// If position is more, recur  
		// for left subarray 
		if (index - l > k - 1)
			return kthSmallest(arr, l, index - 1, k);

		// Else recur for right subarray 
		return kthSmallest(arr, index + 1, r,
			k - index + l - 1);
	}

	// If k is more than number of  
	// elements in array 
	return INT_MAX;
}




int main() {

	int arr[] = { 10, 4, 5, 8, 6, 11, 26 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 3;
	cout << "K-th smallest element is  "
		<< kthSmallest(arr, 0, n - 1, k);


	/*
	// es ist moeglich ein Array zu sortieren
	int myints[] = { 32,71,12,45,26,80,53,33 };
	cout << "1. myints: ";
	for (size_t i = 0; i < 8; ++i)
		cout << myints[i] << " ";
	cout << endl; // endl entspricht '\n'

	// aufsteigend sortieren - standardmaessig
	sort(myints, myints + 8);

	// abseigend -> TESTEN!
	// sort(myints, myints + 8, vergleiche);
	cout << "2. myints: ";
	for (size_t i = 0; i != 8; ++i)
		cout << myints[i] << " ";
	cout << endl << endl;

	// Verwendung des STL-Containers vector
	// irgendwelche Zahlen einfach in ein vector speichern
	int newints[] = { 32,71,12,45,26,80,53,33 };
	vector<int> myvector(newints, newints + 8);  // Anfangs- und Endadresse von newints
	// man kann auch vector mit push_back(rand() % etwas) auffuellen
	cout << "1. myvector: ";
	for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		cout << ' ' << *it;
	cout << endl << endl;


	// standardmaessig wird aufsteigend sortiert
	// nur die ersten 4 Elemente sortieren
	sort(myvector.begin(), myvector.begin() + 4);
	// vector ausgeben
	cout << "2. myvector: ";
	for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		cout << ' ' << *it;
	cout << endl << endl;  // endl entspricht '\n'

	// alles sortieren
	sort(myvector.begin(), myvector.end());
	// vector ausgeben
	cout << "3. myvector: ";
	for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		cout << ' ' << *it;
	cout << endl << endl;

	// vector zufaellig umordnen, falls Warnung kommt -> nicht schlimm
	random_shuffle(myvector.begin(), myvector.end());
	// vector ausgeben
	cout << "4. myvector: ";
	for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		cout << ' ' << *it;
	cout << endl << endl;

	// Absteigend sortieren
	sort(myvector.begin(), myvector.end(), vergleiche);
	// vector ausgeben
	cout << "5. myvector: ";
	for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		cout << ' ' << *it;
	cout << endl << endl;

	// Ein Teil aufsteigend sortieren
	


	system("pause");
	return 0;
}

*/