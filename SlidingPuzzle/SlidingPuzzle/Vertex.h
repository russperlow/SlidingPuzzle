#pragma once
class Vertex
{
public:
	Vertex();
	Vertex(int);
	~Vertex();
	int GetValue();

	// AStar Methods
	int GetH();
	int GetG();


	void SetValue(int); // ************************************** ONLY USED FOR TESTING SHOULD BE REMOVED **************************************
private:
	int value;

	// AStar Variables
	int G;
	int H;
	vector<Vertex*> path;
};

