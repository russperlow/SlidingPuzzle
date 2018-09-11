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
	void AddToHillCount(int);
	void ResetHillCount();
private:
	int x;
	int y;
	int value;
	int G;
	int H;
	int hillCount;
	Vertex* pathNode = nullptr;
};

