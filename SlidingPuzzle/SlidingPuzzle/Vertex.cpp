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
	* Estimated cost from start state to current state
*/
int Vertex::GetG()
{
	return G;
}

/*
	* Estimated cost from current state to end state
*/
int Vertex::GetH()
{
	return H;
}

/*
	************************************** ONLY USED FOR TESTING SHOULD BE REMOVED **************************************
*/
void Vertex::SetValue(int _value)
{
	this->value = _value;
}