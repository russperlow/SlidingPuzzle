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
	int GetG();
	int GetH();
	int GetF();
	void SetValue(int);
	void SetG(int);
	void SetPathNode(Vertex*);
private:
	int x;
	int y;
	int value;
	int G; // Should be the path length from its current square to the end
	int H; // Should be calculated using manhattan distance
	int hillCount;
	Vertex* pathNode = nullptr;
};

