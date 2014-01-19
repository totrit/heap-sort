/*
 * HeapSorter.cpp
 *
 *  Created on: Jan 19, 2014
 *      Author: totrit
 */

#include "HeapSorter.h"
#include <assert.h>
#include <iostream>
using namespace std;

HeapSorter::HeapSorter(bool asc, int maxHeapSize) {
	asc_ = asc;
	maxHeapSize_ = maxHeapSize;
}

HeapSorter::~HeapSorter() {
	// TODO Auto-generated destructor stub
}

void HeapSorter::push(int e) {
	elements_.push_back(e);
	up(elements_.size() - 1);

	//trim the last
	if (maxHeapSize() != -1 && elements_.size() > (unsigned)maxHeapSize()) {
		elements_.pop_back();
	}
}

int HeapSorter::pop() {
	int ret = elements_[0];
	elements_[0] = elements_.back();
	elements_.pop_back();
	down(0);
	if (!elements_.empty())
		cout << "after pop, top element is: " << elements_.at(0) << endl;
	return ret;
}

int HeapSorter::size() {
	return elements_.size();
}

/**
 * return the father's ID
 * ceil(n/2) - 1
 */
int HeapSorter::father(int elementID) {
	if (elementID == 0) {
		return -1;
	} else {
		return (int)((((float)elementID) / 2) + 0.5) - 1;
	}
}

/**
 * return the children of the element
 * 2*n + 1 and 2*n + 2
 */
int HeapSorter::children(int elementID, int (&store)[2]) {
	int ret = 0;
	if (elements_.size() > 2 * elementID + 1) {
		store[0] = 2 * elementID + 1;
		ret ++;
	}
	if (elements_.size() > 2 * elementID + 2) {
		store[1] = 2 * elementID + 2;
		ret ++;
	}
	return ret;
}

void HeapSorter::swap(int elementA_ID, int elementB_ID) {
	assert(elementA_ID >= 0 && (unsigned)elementA_ID < elements_.size());
	assert(elementB_ID >= 0 && (unsigned)elementB_ID < elements_.size());
	int tmp = elements_[elementA_ID];
	elements_[elementA_ID] = elements_[elementB_ID];
	elements_[elementB_ID] = tmp;
}

void HeapSorter::up(int elementID) {
	if (elementID == 0) {
		// return
	} else {
		int fatherID = father(elementID);
		if (asc_ && elements_[elementID] < elements_[fatherID] ||
				!asc_ && elements_[elementID] > elements_[fatherID]) {
			swap(elementID, fatherID);
			up(fatherID);
		} else {
			// return
		}
	}
}

void HeapSorter::down(int elementID) {
	int childrenStore[2];
	int childrenNum = children(elementID, childrenStore);
	cout << "children of " << elementID << " is: " << childrenStore[0] << ", " << childrenStore[1] << ", total: " << childrenNum << endl;
	if (childrenNum == 0) {
		return;
	} else {
		int childChosen = -1;
		if (childrenNum == 1) {
			childChosen = childrenStore[0];
		} else {
			childChosen = childrenStore[0];
			if (asc_ && elements_[childrenStore[0]] > elements_[childrenStore[1]] ||
					!asc_ && elements_[childrenStore[0]] < elements_[childrenStore[1]]) {
				childChosen = childrenStore[1];
			}
		}
		if (asc_ && elements_[elementID] > elements_[childChosen] ||
				!asc_ && elements_[elementID] < elements_[childChosen]) {
			swap(elementID, childChosen);
			down(childChosen);
		}
	}
}
