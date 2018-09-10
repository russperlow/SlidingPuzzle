#pragma once
class Vertex
{
public:
	Vertex();
	Vertex(int, int, int);
	~Vertex();
	int GetX();
	int GetY();
	int GetValue();
private:
	int x;
	int y;
	int value;
};

