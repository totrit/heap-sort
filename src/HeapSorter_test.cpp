/*
 * HeapSorter_test.cpp
 *
 *  Created on: Jan 19, 2014
 *      Author: totrit
 */
#include "HeapSorter.h"

#include <assert.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int elements[] = {35, 34, 4, 6, 23, 66, 42, 37, 11, 42, 177, 32, 46, 16, 22, 64};
	const int elementNum = sizeof(elements) / sizeof(int);
	HeapSorter *pHeapSorter = new HeapSorter(true);
	for (int i = 0; i < elementNum; i ++) {
		pHeapSorter->push(elements[i]);
	}
	// test
	vector<int> forSort(elements, elements + elementNum);
	sort(forSort.begin(), forSort.end());
	int checkPoint = 0;
	while (pHeapSorter->size() != 0) {
		int poped = pHeapSorter->pop();
		cout << poped << endl;
		assert(poped == forSort[checkPoint ++]);
	}
	return 0;
}

