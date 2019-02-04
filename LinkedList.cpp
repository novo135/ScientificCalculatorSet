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
			temp = head->next;
			delete head;
			head = temp;
			--size;
		
		} while (head != NULL);
		delete temp;
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

void LinkedList::modifyLink(int indexNum, std::string newData)
{
	/// @ to do
}

void LinkedList::deleteNthLink(int indexNum)
{
	/// @ to do

}

void LinkedList::popHead()
{
	if (head != NULL)
	{
		Node* temp = head->next;
		delete head;
		head = temp;
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

int LinkedList::searchForData(std::string lookingForThis)
{
	int i = 0;
	if (head != NULL)
	{
		do
		{
			cursor = head->next;
			if (cursor->data == lookingForThis &&
				cursor->data.size() == lookingForThis.size()) 
			{
				break;
			}
			++i;

		} while (head != NULL);
	}
	return i;
}

int LinkedList::findLastOfData(std::string needle)
{
	int i = 0;
	if (tail != NULL)
	{
		cursorIndex = size;
		cursor = tail;
		do
		{
			++i;
			--cursorIndex;
			cursor = cursor->prev;
			if (cursor->data == needle && 
				cursor->data.size() == needle.size()) 
			{
				break;
			}

		} while (tail != NULL);
	}
	return size - i;
}

int LinkedList::findFirstOfData(std::string needle)
{
	int i = 0;
	if (head != NULL)
	{
		cursorIndex = 0;
		cursor = head;
		do
		{
			++i;
			++cursorIndex;
			cursor = cursor->next;
			if (cursor->data == needle && 
				cursor->data.size() == needle.size())
			{
				break;
			}

		} while (head != NULL);
	}
	return i;
}

int LinkedList::getSize()
{
	return size;
}

Node* LinkedList::publicCursor(void)
{
	if (cursor != NULL) {
		return cursor;
	}
	else {
		return nullptr;
	}
}

std::string LinkedList::iterator(unsigned int input)
{
	if (input != cursorIndex + 1)
	{
		setCursor(input);
	}
	else
	{
		++cursorIndex;
		cursor = cursor->next;
	}
	Node* temp = cursor;

	if (temp != NULL) {
		return temp->data;
	}
	else {
		return nullptr;
	}
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