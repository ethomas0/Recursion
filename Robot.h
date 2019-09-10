#ifndef ROBOT_H
#define ROBOT_H
#include "Board.h"
#include <string>
#include <iostream>
#include <cmath>



class Robot
{

public:
	Robot();
	Robot(int steps, int x1, int y1, int x2, int y2);
	~Robot();

	void FindPath(const Board &var);


private:
	void searchPath(const Board &board, const int x, const int y, const string steps, vector<int> &xPath, vector<int> &yPath);// recursive call
	bool isBlocked(const Board &board, const int &x, const int &y); // checks if the move is blocked
	bool reachedLimit(const string &path, const string &direction); // checks if MaxStepsDir has been reached
	bool inBounds(const Board &b, const int &x, const int &y); // checks if its within the board's bounds
	bool isRepeated(const string &path);
	bool goingCircles(const vector<int> &xP, const vector<int> &yP, const int &x, const int &y);
	int xRobot;
	int yRobot;
	int xTreasure;
	int yTreasure;
	int maxStepsDir;
	int pathCount;
	int shortestLength;
	vector<string> allPaths;
	const string NORTH = "N";
	const string EAST = "E";
	const string SOUTH = "S";
	const string WEST = "W";

};





#endif ROBOT_H

