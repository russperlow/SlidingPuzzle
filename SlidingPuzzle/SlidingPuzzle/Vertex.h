#pragma once
class Vertex
{
public:
	Vertex();
	Vertex(int);
	~Vertex();
	int GetValue();

	void SetValue(int); // ************************************** ONLY USED FOR TESTING SHOULD BE REMOVED **************************************
private:
	int value;

	// AStar Variables
	int G;
	int H;
	vector<Vertex*> path;
};

