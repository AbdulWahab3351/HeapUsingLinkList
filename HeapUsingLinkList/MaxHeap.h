#ifndef MAX_HEAP_H
#define MAX_HEAP_H
#include"BTNode.h"
#include"Stack.h"

template <typename T>
class MaxHeap
{
	BTNode<T>* root;
	int nodesCount;

	void swap(T& temp1, T& temp2);
	void descendantsDisplay(BTNode<T>* ptr);
	void destructor(BTNode<T>* ptr);
	BTNode<T>* insertHelper(Stack<bool>& st, BTNode<T>* ptr, T val);
	BTNode<T>* getMaxChild(BTNode<T>* left, BTNode<T>* right);
public:

	MaxHeap();
	~MaxHeap();
	void insert(T val);
	T getMax();
	void removeMax();
	void preOrder();
};
#endif // !MAX_HEAP_H


