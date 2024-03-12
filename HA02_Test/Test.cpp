
/*
// sort algorithm example
#include <iostream>     // cout
#include <algorithm>    // sort
#include <vector>       // vector
#include "TestQuickSort.h"

using namespace std;  // um std:: nicht dauernd eintippen zu muessen






// hier: left = 1 aber immer! zudem zählt man OHNE die Null also natürliche zahlen ohne null
template<typename T>
int zerlege (T* array[], size_t left, size_t right) {

	int x = array[right];
	int i = left - 1;
	size_t j;
	for (j = left; j < right - 1; j++) {
		if (array[j] <= x) {
			i = i + 1;

			T temp = array[i]; //#
			array[i] = array[j];	//#
			array[j] = temp; // # == swap also vertauschungsprozess
		}
	}
	T temp = array[i+1]; //#
	array[i+1] = array[j];	//#
	array[j] = temp; // # == swap also vertauschungsprozess

	return i+1; // output: i+=1
}


template<typename T>
T* MedianBest(T array[]) {

	return 0;
}


template<typename T>
void QuickSortAlgo(T* array[], size_t left, size_t right) {


	if (left < right) {
		int i ;
		i = zerlege(left, right);

		
		QuickSortAlgo(left, i - 1);
		QuickSortAlgo(i + 1, right);

		MedianBest(T * array[]);
	}

}
*/