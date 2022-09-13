#include<iostream>
using namespace std;
#include"MinHeap.h"
#include"MaxHeap.h"

int main()
{
	MaxHeap<int> m;
	m.insert(5);
	m.insert(3);
	m.insert(4);
	m.insert(5);
	m.insert(90);
	m.insert(1);
	m.insert(5);
	m.insert(85);
	m.insert(62);
	m.insert(7);
	m.insert(5);
	m.insert(-49);
	m.insert(5);
	for (int i = 0; i < 13; i++)
	{
		cout << " " << m.getMax();
		m.removeMax();
	}
	return 0;
}