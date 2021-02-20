#include "Pair.h"

Pair::Pair(char _data, int _freq)
{
	data = _data;
	frequency = _freq;
}
Pair::Pair(const Pair& other)
{
	*this = other;
}
void Pair::operator=(const Pair& other)
{
	this->data = other.data;
	this->frequency = other.frequency;
}
