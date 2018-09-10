#include "stdafx.h"
#include "Vertex.h"


Vertex::Vertex()
{
}

Vertex::Vertex(int _x, int _y, int _value)
{
	this->x = _x;
	this->y = _y;
	this->value = _value;
}


Vertex::~Vertex()
{
}

int Vertex::GetX()
{
	return x;
}

int Vertex::GetY()
{
	return y;
}

int Vertex::GetValue()
{
	return value;
}
