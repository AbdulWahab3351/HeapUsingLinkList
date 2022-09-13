#include "BTNode.h"
template<typename T>
BTNode<T>::BTNode()
{
	right = left = nullptr;
}
template<typename T>
BTNode<T>::BTNode(T val):info(val)
{
	right = left = nullptr;
}