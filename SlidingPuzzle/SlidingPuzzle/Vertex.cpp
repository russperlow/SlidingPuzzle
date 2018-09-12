#include "stdafx.h"
#include "Vertex.h"


Vertex::Vertex()
{
}

Vertex::Vertex(int _value)
{
	this->value = _value;
}

Vertex::~Vertex()
{
}

/*
	* Returns the number value of this vertex
*/
int Vertex::GetValue()
{
	return value;
}

/*
	************************************** ONLY USED FOR TESTING SHOULD BE REMOVED **************************************
*/
void Vertex::SetValue(int _value)
{
	this->value = _value;
}