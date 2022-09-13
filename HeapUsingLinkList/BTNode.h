#ifndef BT_NODE_H
#define BT_NODE_H

template <typename T>
class BTNode
{
public:
	T info;
	BTNode<T>* left;
	BTNode<T>* right;
	BTNode();
	BTNode(T val);
};
#endif // !BT_NODE_H


