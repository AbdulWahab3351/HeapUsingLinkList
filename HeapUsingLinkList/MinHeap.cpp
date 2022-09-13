#include "MinHeap.h"
#include <iostream>
#include <string>
using std::cout;
using std::string;

template <typename T>
MinHeap<T>::~MinHeap()
{
	if (!root)
		return;
	destructor(root);
	root = nullptr;
	nodesCount = 0;
}
template <typename T>
void MinHeap<T>:: destructor(BTNode<T>* ptr)
{
	if (ptr->left)
		destructor(ptr->left);
	if (ptr->right)
		destructor(ptr->right);
	delete ptr;
}
template <typename T>
MinHeap<T>::MinHeap()
{
	root = nullptr;
	nodesCount = 0;
}
template <typename T>
void MinHeap<T>::preOrder()
{
	if (!root)
		return;
	cout << root->info << ' ';
	if (root->left)
		descendantsDisplay(root->left);
	if (root->right)
		descendantsDisplay(root->right);
}
template <typename T>
void MinHeap<T>::descendantsDisplay(BTNode<T>* ptr)
{
	cout << ptr->info << ' ';
	if (ptr->left)
		descendantsDisplay(ptr->left);
	if (ptr->right)
		descendantsDisplay(ptr->right);
}

template <typename T>
BTNode<T>* MinHeap<T>:: insertHelper(Stack<bool>& st, BTNode<T>* ptr, T val)
{
	if (st.isEmpty())
	{
		if (ptr->left)
		{
			ptr->right = new BTNode<T>(val);
			if (ptr->info > ptr->right->info)
				swap(ptr->right->info, ptr->info);
		}
		else
		{
			ptr->left = new BTNode<T>(val);
			if (ptr->info > ptr->left->info)
				swap(ptr->left->info, ptr->info);
		}
		return ptr;
	}
	bool index = st.pop();
	BTNode<T>* temp;
	if (index)
		temp = insertHelper(st, ptr->right, val);
	else
		temp = insertHelper(st, ptr->left, val);
	if (ptr->info > temp->info)
		swap(temp->info, ptr->info);
	return ptr;
}
template <typename T>
void MinHeap<T>:: insert(T val)
{
	if (!root)
	{
		root = new BTNode<T>(val);
		nodesCount++;
		return;
	}
	Stack<bool>st;
	int temp = nodesCount + 1;
	temp /= 2;
	while (temp != 0)
	{
		st.push(temp % 2);
		temp /= 2;
	}
	st.pop();
	insertHelper(st, root, val);
	nodesCount++;
}
template<typename T>
void MinHeap<T>::swap(T& temp1, T& temp2)
{
	T temp = temp1;
	temp1 = temp2;
	temp2 = temp;
}
template <typename T>
void MinHeap<T>::removeMin()
{
	if (!root)
		return;
	else if (!root->left && !root->right)
	{
		delete root;
		root = nullptr;
		nodesCount = 0;
		return;
	}
	Stack<bool>st;
	int temp = nodesCount--;
	temp /= 2;
	while (temp != 0)
	{
		st.push(temp % 2);
		temp /= 2;
	}
	st.pop();
	BTNode<T>* ptr = root;
	while (!st.isEmpty())
	{
		bool temp = st.pop();
		ptr = (temp ? ptr->right : ptr->left);
	}
	if (ptr->right)
	{
		root->info = ptr->right->info;
		delete ptr->right;
		ptr->right = nullptr;
	}
	else
	{
		root->info = ptr->left->info;
		delete ptr->left;
		ptr->left = nullptr;
	}
	BTNode<T>* cur = root;
	while (cur->left)
	{
		BTNode<T>* minIndex;
		minIndex = (cur->right ? getMinChild(cur->left, cur->right) : cur->left);
		if (minIndex->info < cur->info)
		{
			swap(minIndex->info, cur->info);
			cur = minIndex;
		}
		else
			return;
	}
}

template <typename T>
BTNode<T>* MinHeap<T>:: getMinChild(BTNode<T>* left, BTNode<T>* right)
{
	return (left->info < right->info ? left : right);
}
template <typename T>
T MinHeap<T>:: getMin()
{
	if (!root)
		throw string("Heap is empty\n");
	return root->info;
}