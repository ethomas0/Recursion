#include "Board.h"

Board::Board()
{
	x = 0;
	y = 0;
}

Board::Board(int x, int y, vector<int> restrictions)
{
	this->x = x;
	this->y = y;
	if (restrictions.size() != 0)
	{
		setRestrictions(restrictions);
	}
}



Board::~Board()
{

}



void Board::setRestrictions(vector<int> var)
{
	for (int i = 0; i < var.size(); i++)
	{
		if (i % 2 == 0)
		{
			blockedXCoord.push_back(var[i]);
		}
		else
		{
			blockedYCoord.push_back(var[i]);
		}
	}
}

int Board::getX() const
{
	return x;
}

int Board::getY() const
{
	return y;
}

int Board::getXBlockedCoord(const int &index) const
{
	if (index < blockedSize())
	{
		return blockedXCoord[index];
	}
	else
	{
		return 0;
	}
}
	


int Board::blockedSize() const
{
	return blockedXCoord.size();
}



int Board::getYBlockedCoord(const int &index) const
{
	if (index < blockedSize())
	{
		return blockedYCoord[index];
	}
	else
	{
		return 0;
	}
}

