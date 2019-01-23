#pragma once

#ifndef _HELPER_H__
#define _HELPER_H__


class Helper
{
public:
	Helper();
	virtual ~Helper();

	void pack(int* bufferToBePacked, int* thingsINeed, int size);
	int input_buffer[256];

private:

	
};

#endif // _HELPER_H__

