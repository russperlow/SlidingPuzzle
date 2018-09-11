#include "stdafx.h"
#include "Vertex.h"


Vertex::Vertex()
{
}

Vertex::Vertex(int _x, int _y, int _value)
{
	this->startX = _x;
	this->startY = _y;
	this->value = _value;
}

Vertex::~Vertex()
{
}

int Vertex::GetValue()
{
	return value;
}

/*
	* Cost from starting state to current state
*/
int Vertex::GetG(int currentX, int currentY)
{
	int xDist = currentX - startX;
	int yDist = currentY - startY;

	G = xDist + yDist;

	return G;
}

/*
	* Estimated cost from current state to end state
*/
int Vertex::GetH()
{
	return H;
}

int Vertex::GetF()
{
	return G + H;
}

void Vertex::SetValue(int _value)
{
	this->value = _value;
}

void Vertex::SetG(int _G)
{
	G = _G;
}

void Vertex::SetPathNode(Vertex* _pathNode)
{
	pathNode = _pathNode;
}

//int Vertex::GetX()
//{
//	return x;
//}
//
//int Vertex::GetY()
//{
//	return y;
//}

