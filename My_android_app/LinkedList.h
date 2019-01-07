#include <iostream>

// descerte class for holding memory addresses and data

class Node
{
public:
	Node(float data);

	Node* prev;
	Node* next;
	float data;
};

Node::Node(float data)
{
	this->prev = NULL;
	this->next = NULL;
	this->data = data;
}






//////////////////
//  next class  //
//////////////////







#ifndef LINKED_LIST_H__
#define LINKED_LIST_H__

class LinkedList
{
public:
	LinkedList();
	LinkedList(float data);
	virtual ~LinkedList();

	Node* head;		// front
	Node* tail;		// rear
	
	void addData(float input);
	void addLink(Node* newNode);


};

#endif // !LINKED_LIST_H__
