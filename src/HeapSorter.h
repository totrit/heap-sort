/*
 * HeapSorter.h
 *
 *  Created on: Jan 19, 2014
 *      Author: totrit
 */

#ifndef HEAPSORTER_H_
#define HEAPSORTER_H_
#include <vector>
using namespace std;

class HeapSorter {

public:
	HeapSorter(bool asc, int maxHeapSize = -1);
	virtual ~HeapSorter();

	void push(int e);
	int pop();
	int size();

private:
	void up(int elementID);
	void down(int elementID);
	int father(int elementID);
	int children(int elementID, int (&p)[2]);

	void swap(int elementA_ID, int elementB_ID);
	inline int maxHeapSize() { return maxHeapSize_; }

	vector<int> elements_;
	int maxHeapSize_;
	bool asc_;
};

#endif /* HEAPSORTER_H_ */
