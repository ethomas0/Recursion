#include "Robot.h"

Robot::Robot()
{
	xRobot = yRobot = maxStepsDir = pathCount = shortestLength = 0;
	


}

Robot::Robot(int steps, int x1, int y1, int x2, int y2)
{
	xRobot = x1;
	yRobot = y1;
	maxStepsDir = steps;
	
	xTreasure = x2;
	yTreasure = y2;
	pathCount = 0;
	shortestLength = 0;

}

Robot::~Robot()
{
	
}

void Robot::searchPath(const Board &b, const int x, const int y, const string steps, vector<int> &xPath,  vector<int> &yPath)
{
	if (x == xTreasure && y == yTreasure) // found treasure
	{
		if (isRepeated(steps)) //checking if path has already been stored
		{
			if (pathCount == 0)
			{
				shortestLength = steps.size();
			}
			else
			{
				if (steps.size() < shortestLength)
				{
					shortestLength = steps.size();
				}
			}
			allPaths.push_back(steps);  // adds to vector
			++pathCount;
		}


		return;
	}
	else
	{
		xPath.push_back(x); //mark x-axis spot as visited
		yPath.push_back(y); // mark y-axis spot as visited
		//recursive calls for NORTH,SOUTH, EAST AND WEST
		if (y < yTreasure) //treasure is above 
		{
			if (isBlocked(b, x, y + 1) && reachedLimit(steps, NORTH) && inBounds(b, x, y + 1) && goingCircles(xPath, yPath, x, y+1))//move up
			{
				searchPath(b, x, y + 1, steps + NORTH, xPath, yPath);
			}
			else if (/*x < xTreasure &&*/ isBlocked(b, x + 1, y) && reachedLimit(steps, EAST) && inBounds(b, x + 1, y) && goingCircles(xPath, yPath, x + 1, y)) //can't move up so move to closer along x-axis
			{
				searchPath(b, x + 1, y, steps + EAST, xPath, yPath);
			}
			else if (/*x > xTreasure &&*/ isBlocked(b, x - 1, y) && reachedLimit(steps, WEST) && inBounds(b, x - 1, y) && goingCircles(xPath, yPath, x - 1, y)) ////can't move up so move to closer along x-axis
			{
				searchPath(b, x - 1, y, steps + WEST, xPath, yPath);
			}
			else if (isBlocked(b, x, y - 1) && reachedLimit(steps, SOUTH) && inBounds(b, x, y - 1) && goingCircles(xPath, yPath, x, y - 1)) // only direction can move is down
			{
				searchPath(b, x, y - 1, steps + SOUTH, xPath, yPath);
			}

			if (!isBlocked(b, x, y + 1) && isBlocked(b, x - 1, y) && reachedLimit(steps, WEST) && inBounds(b, x - 1, y) && goingCircles(xPath, yPath, x - 1, y)) // checking other direction
			{
				searchPath(b, x - 1, y, steps + WEST, xPath, yPath);
			}


		}
		if (y > yTreasure ) //treasure is below
		{
			if (isBlocked(b, x, y - 1) && reachedLimit(steps, SOUTH) && inBounds(b, x, y - 1) && goingCircles(xPath, yPath, x, y - 1)) //move down
			{
				searchPath(b, x, y - 1, steps + SOUTH, xPath, yPath);
			}
			else if (/*x < xTreasure &&*/ isBlocked(b, x + 1, y) && reachedLimit(steps, EAST) && inBounds(b, x + 1, y) && goingCircles(xPath, yPath, x + 1, y)) //can't move down so move to closer along x-axis
			{
				searchPath(b, x + 1, y, steps + EAST, xPath, yPath);
			}
			else if (/*x > xTreasure &&*/ isBlocked(b, x - 1, y) && reachedLimit(steps, WEST) && inBounds(b, x - 1, y) && goingCircles(xPath, yPath, x - 1, y)) //can't move down so move to closer along x-axis
			{
				searchPath(b, x - 1, y, steps + WEST, xPath, yPath);
			}
			else if (isBlocked(b, x, y + 1) && reachedLimit(steps, NORTH) && inBounds(b, x, y + 1) && goingCircles(xPath, yPath, x, y + 1)) // only direction is up
			{
				searchPath(b, x, y + 1, steps + NORTH, xPath, yPath);
			}

			if (!isBlocked(b, x, y - 1) && isBlocked(b, x - 1, y) && reachedLimit(steps, WEST) && inBounds(b, x - 1, y) && goingCircles(xPath, yPath, x - 1, y)) // checking other direction
			{
				searchPath(b, x - 1, y, steps + WEST, xPath, yPath);
			}

		}
		if (x < xTreasure) //treasure is to the right
		{
			if (isBlocked(b, x + 1, y) && reachedLimit(steps, EAST) && inBounds(b, x + 1, y) && goingCircles(xPath, yPath, x + 1, y)) //move right
			{
				searchPath(b, x + 1, y, steps + EAST, xPath, yPath);
			}
			else if (/*y < yTreasure &&*/ isBlocked(b, x, y + 1) && reachedLimit(steps, NORTH) && inBounds(b, x, y + 1) && goingCircles(xPath, yPath, x, y + 1)) //can't move right so move closer along y-axis
			{
				searchPath(b, x, y + 1, steps + NORTH, xPath, yPath);
			}
			else if (/*y > yTreasure &&*/ isBlocked(b, x, y - 1) && reachedLimit(steps, SOUTH) && inBounds(b, x, y - 1) && goingCircles(xPath, yPath, x, y - 1))//can't move right so move closer along y-axis
			{
				searchPath(b, x, y - 1, steps + SOUTH, xPath, yPath);
			}
			else if (isBlocked(b, x - 1, y) && reachedLimit(steps, WEST) && inBounds(b, x - 1, y) && goingCircles(xPath, yPath, x - 1, y)) // only direction is  left
			{
				searchPath(b, x - 1, y, steps + WEST, xPath, yPath);
			}

			if (!isBlocked(b, x + 1, y) && isBlocked(b, x, y - 1) && reachedLimit(steps, SOUTH) && inBounds(b, x, y - 1) && goingCircles(xPath, yPath, x, y - 1)) // checking other direction
			{
				searchPath(b, x, y - 1, steps + SOUTH, xPath, yPath);
			}

		}


		if (x > xTreasure) // treasure is to the left
		{
			if (isBlocked(b, x - 1, y) && reachedLimit(steps, WEST) && inBounds(b, x - 1, y) && goingCircles(xPath, yPath, x - 1, y)) //move left
			{
				searchPath(b, x - 1, y, steps + WEST, xPath, yPath);
			}
			else if (y < yTreasure && isBlocked(b, x, y + 1) && reachedLimit(steps, NORTH) && inBounds(b, x, y + 1) && goingCircles(xPath, yPath, x, y + 1)) //can't move left so move closer along y-axis
			{
				searchPath(b, x, y + 1, steps + NORTH, xPath, yPath);
			}
			else if (y > yTreasure && isBlocked(b, x, y - 1) && reachedLimit(steps, SOUTH) && inBounds(b, x, y - 1) && goingCircles(xPath, yPath, x, y - 1))//can't move left so move closer along y-axis
			{
				searchPath(b, x, y - 1, steps + SOUTH, xPath, yPath);
			}
			else if (isBlocked(b, x + 1, y) && reachedLimit(steps, EAST) && inBounds(b, x + 1, y) && goingCircles(xPath, yPath, x+1, y ))// only direction is right
			{
				searchPath(b, x + 1, y, steps + EAST, xPath, yPath);
			}

			if (!isBlocked(b, x - 1, y) && reachedLimit(steps, SOUTH) && inBounds(b, x, y - 1) && goingCircles(xPath, yPath, x, y - 1)) // checking other direction
			{
				searchPath(b, x, y - 1, steps + SOUTH, xPath, yPath);
			}

		}
		xPath.pop_back();//marking x-axis spot as not visited
		yPath.pop_back(); // marking y-axis as not visited
	}
}

void Robot::FindPath(const Board &var)
{
	
	if (this->xRobot <= var.getX() && this->yRobot <= var.getX() && this->xTreasure <= var.getX() && this->yTreasure <= var.getY())
	{
		vector<int> xPath;
		vector<int> yPath;
		searchPath(var, xRobot, yRobot, "", xPath, yPath);
	}
	
	pathCount = 0;
	for (int i = 0; i < allPaths.size(); i++)
	{
		if (allPaths[i].size() == shortestLength)
		{
			cout << allPaths[i] << endl;
			++pathCount;
		}
		
	}
	cout << "Number of paths: " << pathCount << '\n';
}

bool Robot::isBlocked(const Board &board, const int &x, const int &y)//checks if (x,y) spot is blocked. Returns true if not
{
	for (int i = 0; i < board.blockedSize(); i++)
	{
		if (x == board.getXBlockedCoord(i) && y == board.getYBlockedCoord(i))
		{
			return false;
		}
	}
	return true;
}

bool Robot::reachedLimit(const string &path, const string &direction)// checks to see if MaxStepDir limit has been reached. Returns true if limit has not been reached
{
	int tempIndex(0);
	int tempCounter(0);

	if ( maxStepsDir != 0)
	{
		tempIndex = path.size() - maxStepsDir;

		for (tempIndex; tempIndex < path.size(); tempIndex++)
		{
			if (path[tempIndex] == direction[0])
			{
				tempCounter++;
			}
		}
	}

	if (maxStepsDir != 0 && tempCounter >= maxStepsDir)
	{
		return false;
	}
	else
	{
		return true;
	}

}

bool Robot::inBounds(const Board &b, const int &x, const int &y)//checks to see if spot is still on the board. Returns true if it is
{
	if (x <= b.getX() && y <= b.getY() && x >= 0 && y >= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Robot::isRepeated(const string &path)//checks to see if path is already stored. Returns true if not a repeat
{
	if (allPaths.size() != 0)
	{
		for (int i = 0; i < allPaths.size(); i++)
		{
			if (allPaths[i] == path)
			{
				return false;
			}
		}
	}
	return true;
}

bool Robot::goingCircles(const vector<int> &xP, const vector<int> &yP, const int &x, const int &y)//Checks to see if robot has already visited spot. Returns true if not.
{
	if (xP.size() != 0)
	{
		for (int i = 0; i < xP.size(); i++)
		{
			if (xP[i] == x && yP[i] == y)
			{
				return false;
			}
		}
	}
	return true;
}

