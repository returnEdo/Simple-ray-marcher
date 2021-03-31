#include "Queue.h"

#include <cmath>
#include <cassert>

template <typename T>
Queue<T>::Queue(int size_):
	size(abs(size_)),
	circularArray(new T[size])	{}

template <typename T>
Queue<T>::~Queue(void){

	delete [] circularArray;
}


template <typename T>
void Queue<T>::enque(T val){
	/* notice the automatic dequeing */

	if (isFull())	{ deque(); }

	back = (back + 1) % size;
	circularArray[back] = val;

	count++;
}


template <typename T>
void Queue<T>::deque(void){

	assert(not isEmpty());
	
	front = (front + 1) % size;
	
	count--;
}


