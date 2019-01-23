#include "LinkedList.h"
#include <iostream>
#include <string>

LinkedList::LinkedList()
	: cursorIndex(0),
	size(0)
{
	cursor = NULL;
	head = NULL;
	tail = NULL;
}

LinkedList::LinkedList(std::string data)
{
	Node* temp = new Node(data);
	head = temp;
	tail = temp;
	temp->next = NULL;
	temp->prev = NULL;
	cursor = head;
	++size;
}

LinkedList::~LinkedList()
{
	if (head != NULL)
	{
		Node* temp;
		do
		{
			temp = head;
			head = head->next;
			delete temp;
			--size;

		} while (head != NULL);
	}
}

void LinkedList::addLink(std::string data)
{
	Node* temp = new Node(data);
	if (tail != NULL)
	{
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
		++size;
	}
	else
	{
		head = temp;
		tail = head;
		cursor = head;
		cursorIndex = 0;
		size = 1;
	}
}

void LinkedList::addNthLink(std::string data, unsigned int position)
{
	Node* temp = new Node(data);
	if (cursor != NULL)
	{
		temp->next = cursor->next;
		temp->prev = cursor;
		cursor->next = temp;
		if (cursor->next != NULL) 
		{
			temp->next->prev = temp;
		}
	}
}

void LinkedList::setCursor(int destination)
{
	if (destination > cursorIndex)
	{
		int i;
		for (i = destination; i < cursorIndex; ++i)
		{
			if (cursor != NULL) {
				cursor = cursor->prev;
			}
			else {
				break;
			}
		}
		cursorIndex = i;
	}
	else if (destination < cursorIndex)
	{
		int i;
		for (i = destination; i < destination; ++i)
		{
			if (cursor != NULL) {
				cursor = cursor->next;
			}
			else {
				break;
			}
		}
		cursorIndex = i;
	}
}

void LinkedList::searchFordata(std::string lookingForThis)
{


}

void LinkedList::findFirstOf(std::string needle)
{


}

int LinkedList::getSize()
{
	return size;
}

Node* LinkedList::publicCursor(void)
{

	return nullptr;
}

void LinkedList::printList(void)
{
	if (head != NULL && head->next != NULL)
	{
		Node* temp = head;
		do
		{
			std::cout << temp->data << std::endl;
			temp = temp->next;
		} while (temp != NULL);
	}
	else if (head != NULL) {
		std::cout << head->data << std::endl;
	}
}