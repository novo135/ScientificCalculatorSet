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
	cursorIndex = 1;
	size = 1;
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

void LinkedList::pushBack(std::string data)
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
		cursorIndex = 1;
		size = 1;
	}
}

void LinkedList::addNthLink(std::string data, unsigned int position)
{
	Node* temp = new Node(data);
	if (position) {
		setCursor(position );
	}

	if (cursor != NULL)
	{
		temp->next = cursor->next;
		cursor->next = temp;
		cursor->prev = cursor;
		cursor->next->prev = temp;
	}
}

void LinkedList::modifyLink(int indexNum, std::string newData)
{
	if (indexNum) 
	{
		setCursor(indexNum);
		cursor->data = newData;
	}
	else {
		head->data = newData;
	}
}

void LinkedList::deleteNthLink(int indexNum)
{
	if (indexNum) 
	{
		setCursor(indexNum);
		/// @ memory leak here, need to delete node that is skipped
		Node* temp;
		Node* subTemp;
		temp = cursor->next->next;
		if (cursor != NULL &&
			temp != NULL)
		{
			temp->prev = cursor;
			cursor->next = temp;
		}
	}
	else
	{
		popHead();
	}
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
		for (int i = cursorIndex; i < destination; ++i)
		{
			if (cursor->next != NULL)
			{
				cursor = cursor->next;
				cursorIndex = i;
			}
			else {
				break;
			}
		}
	}
	else if (destination < cursorIndex)
	{
		for (int i = destination; i < cursorIndex; ++i)
		{
			if (cursor->prev != NULL) 
			{
				cursor = cursor->prev;
				cursorIndex = i;
			}
			else {
				break;
			}
		}
	}
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
				return size - i;
			}

		} while (cursor != NULL);
	}
	return 0;
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
				return i;
			}

		} while (cursor != NULL);
	}
	return 0;
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
		return NULL;
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