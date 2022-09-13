#ifndef MIN_HEAP_H
#define MIN_HEAP_H
#include"BTNode.h"
#include "Stack.h"

template <typename T>
class MinHeap
{
	BTNode<T>* root;
	int nodesCount;

	void swap(T& temp1, T& temp2);
	void descendantsDisplay(BTNode<T>* ptr);
	void destructor(BTNode<T>* ptr);
	BTNode<T>* insertHelper(Stack<bool>& st, BTNode<T>* ptr, T val);
	BTNode<T>* getMinChild(BTNode<T>* left, BTNode<T>* right);
public:

	MinHeap();
	~MinHeap();
	void insert(T val);
	T getMin();
	void removeMin();
	void preOrder();
};
#endif // !MIN_HEAP_H


