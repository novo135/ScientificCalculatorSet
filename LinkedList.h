#include "Node.cpp"
#include <iostream>
#include <string>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class LinkedList
{
public:
	LinkedList();
	LinkedList(std::string data);
	virtual ~LinkedList();

	void printList(void);
	void addLink(std::string data);
	void addNthLink(std::string data, unsigned int position);
	void setCursor(int desitnation);
	void searchFordata(std::string lookingForThis);			// sets cursor to node which matches data
	void findFirstOf(std::string needle);					// sets cursor to first istance of a node with data specified
	int getSize(void);
	Node* publicCursor(void);

private:
	Node* head;
	Node* tail;
	Node* cursor;
	int cursorIndex;
	int size;

};

#endif // !LINKED_LIST_H

