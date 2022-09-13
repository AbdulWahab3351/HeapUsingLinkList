#ifndef Stack_H
#define Stack_H
#include"Node.h"

template<typename T>
class Stack
{
	Node<T>* head;
public:
	Stack();
	bool isEmpty();
	void push(T h);
	T pop();
	T stackTop();
	~Stack();
	Stack(const Stack<T>& ref);
	Stack<T>& operator=(const Stack<T>& ref);
};

#endif // !LSLL_H


