#pragma once

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

	/*
		add to list
	*/
	void pushBack(std::string data);								// push back data
	void addNthLink(std::string data, unsigned int position);	// add data at any point

	/*
		delete / modify list
	*/
	void modifyLink(int indexNum, std::string newData);			// does not delete any links just changes string value
	void deleteNthLink(int indexNum);							// remove desired link
	void popHead(void);											// remove first link

	/*
		iterators / data tools
	*/
	int findLastOfData(std::string needle);						// sets cursor to last instance of a node with data specified
	int findFirstOfData(std::string needle);					// set cursor to first instance of node w/ input data
	int getSize(void);
	void printList(void);										// debugging / testing only
	Node* publicCursor(void);									// global cursor
	std::string iterator(unsigned int input);					// use in foor loop


private:
	void setCursor(int desitnation);
	Node* head;
	Node* tail;
	Node* cursor;
	int cursorIndex;
	int size;
};

#endif // !LINKED_LIST_H

