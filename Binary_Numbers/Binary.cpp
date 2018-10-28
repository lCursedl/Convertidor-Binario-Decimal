#include "stdafx.h"
#include "Binary.h"

CBinary::CBinary()
{}

CBinary::CBinary(int bin, int number)
{
	i_digit = bin;
	i_number = number;
}

void CBinary::SetBin(int i)
{
	i_digit = i;
}

void CBinary::SetNumb(int i)
{
	i_number = i;
}

int CBinary::GetBin()
{
	return i_digit;
}

int CBinary::GetNumb()
{
	return i_number;
}

CBinary::~CBinary()
{
	i_digit = 0;
	i_number = 0;
}