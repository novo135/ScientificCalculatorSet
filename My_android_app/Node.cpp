#include <iostream>
#include <string>

#ifndef NODE
#define NODE
// descerte class for holding memory addresses and data

class Node
{
public:
	Node(std::string data)
	{
		this->next = NULL;
		this->prev = NULL;
		this->data = data;
	}

	Node* next;
	Node* prev;
	std::string data;
};

#endif // !NODE