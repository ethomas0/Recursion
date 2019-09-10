#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <iostream>

using namespace std;

class Board
{
	public:
		Board();
		Board(int x, int y, vector<int> restrictions);
		
		
		~Board();
		

		int getX()const;
		int getY()const;
		int getXBlockedCoord(const int &index)const; //returns indexed X blocked coordnite
		int getYBlockedCoord(const int &index)const; // returns indexed Y blocked coordnite 	
		int blockedSize()const; // returns size of blocked vectors
		
		


	private:
		int x;
		int y;
		vector<int> blockedXCoord;
		vector<int> blockedYCoord;
		void setRestrictions(vector<int> var);

	
		

		

};


#endif

