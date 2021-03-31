#pragma once

#include <iostream>

#include "RayMarcherConstants.h"


template <typename T>
class Queue{

	private:

	T* circularArray;

	int front	= 0;
	int back	= -1;

	int count	= 0;
	int size;

	public:

	Queue(int size_);
	Queue(void):	Queue(0)	{ size = Constants::RADIUS_QUEUE_SIZE; }
	~Queue(void);

	void enque(T val);
	void deque(void);

	/* getters */
	inline int getSize(void)	const { return size; }
	inline int getCount(void)	const { return count; }

	inline T getFront(void) 	const { return circularArray[front]; }
	inline T getBack(void) 		const { return circularArray[back]; }

	inline bool isEmpty(void)	const { return (count == 0); }
	inline bool isFull(void)	const { return (count == size); }
	
	inline T fromFront(int indx)	const { return circularArray[(front + indx) % size]; }
	inline T fromLast(int indx)	const { return circularArray[(back - indx) % size]; }

	/* operators */
	
	template <typename U>
	friend std::ostream& operator <<(std::ostream& os, const Queue<U>& queue);
};



template <typename U>
std::ostream& operator <<(std::ostream& os, const Queue<U>& queue){

	os << "{";

	for (int i = 0; i < queue.count - 1; i++){
		
		os << queue.circularArray[(queue.front + i) % queue.size] << ", ";
	}
	os << queue.circularArray[queue.back] << "}";

	return os;
}



template class Queue<float>;
