// User include
#include "Model.h"
#include "Control.h"
#include "chessConst.h"
#include <stdio.h>
#include <iostream>

//----------------------------------------------
// Model::Model
//
//
//-----------------------------------------------
Model::Model(Control* aControl)
	:iControl(aControl), iBlackTurn(1)
{
	for (int i = 0; i< CBoardSize; i++)
	{
		for (int j = 0; j< CBoardSize; j++)
		{
			if ((i == CBoardSize / 2 || i == CBoardSize / 2 - 1) &&
				(j == CBoardSize / 2 || j == CBoardSize / 2 - 1))
			{
				if (i == j)
				{
					iBoard[i][j] = EWhite;
				}
				else
				{
					iBoard[i][j] = EBlack;
				}
			}
			else
			{
				iBoard[i][j] = EEmpty;
			}
		}
	}
	//define the coordinate of 8 directions
	iDirection[ENorthWest].offsetX = -1;        iDirection[ENorthWest].offsetY = -1;
	iDirection[ENorth].offsetX = -1;			iDirection[ENorth].offsetY = 0;
	iDirection[ENorthEast].offsetX = -1;		iDirection[ENorthEast].offsetY = 1;
	iDirection[EWest].offsetX = 0;				iDirection[EWest].offsetY = -1;
	iDirection[EEast].offsetX = 0;				iDirection[EEast].offsetY = 1;
	iDirection[ESouthWest].offsetX = 1;			iDirection[ESouthWest].offsetY = -1;
	iDirection[ESouth].offsetX = 1;				iDirection[ESouth].offsetY = 0;
	iDirection[ESouthEast].offsetX = 1;			iDirection[ESouthEast].offsetY = 1;

}

//----------------------------------------------
// Model::~Model
//
//
//-----------------------------------------------
Model::~Model() {
}

//----------------------------------------------
// Model::getChess
//
//
//-----------------------------------------------
int Model::getChess(int aX, int aY)
{
	if (aX< 0 || aX>CBoardSize - 1 || aY < 0 || aY > CBoardSize - 1)
	{
		return EUndef;
	}
	else
	{
		return iBoard[aX][aY];
	}
}

//----------------------------------------------
// Model::getLength
//
//
//-----------------------------------------------
int Model::getOpponentLength(DirectionEnum aDirection, int aX, int aY, int aChessColor)
{
	int length = 0;
	bool found = false;
	int tempX = aX + iDirection[aDirection].offsetX;
	int tempY = aY + iDirection[aDirection].offsetY;
	while (getChess(tempX, tempY)>-1)  //EWhite = 0, EBlack = 1
	{
		if (aChessColor == getChess(tempX, tempY)) //If the neighbor chess has the same color
		{
			found = true;
			break;
		}
		else  
		{
			length++;   //Opponent' length +1
			tempX += iDirection[aDirection].offsetX;   //Go along the direction and get the coordinate
			tempY += iDirection[aDirection].offsetY;
		}
	}
	if (!found)
	{
		length = 0;
	}
	return length;
}

//----------------------------------------------
// Model::checkValidChess
//
//
//-----------------------------------------------
bool Model::checkValidChess(int aX, int aY)  //chack the chess is valid or not
{
	if (getChess(aX, aY) != EEmpty)  //If the square is not empty
	{
		return false;
	}
	for (int i = ENorthWest; i <= ESouthEast; i++)  //Traverse all 8 directions
	{
		if (getOpponentLength(static_cast<DirectionEnum>(i), aX, aY, iBlackTurn)) //If has opponents at certain direction
		{
			return true;
		}
	}
	return false;
}


//----------------------------------------------
// Model::tryChess
//
//
//-----------------------------------------------
bool Model::tryChess(int aX, int aY)
{
	if (checkValidChess(aX, aY))
	{
		setChess(aX, aY);
		moveToNextTurn();
		return true;
	}
	return false;
}

//----------------------------------------------
// Model::moveToNextTurn
//
//
//-----------------------------------------------
void Model::moveToNextTurn()
{
	if (iBlackTurn == 1)   //if now is black, then next round change to white
		iBlackTurn = 0;
	else
		iBlackTurn = 1;
	
	iControl->update();
}

//----------------------------------------------
// Model::setChess
//
//
//-----------------------------------------------
void Model::setChess(int aX, int aY) 
{
	for (int i = ENorthWest; i <= ESouthEast; i++)
	{
		int length = getOpponentLength(static_cast<DirectionEnum>(i), aX, aY, iBlackTurn); //the number of the opponent
		for (int j = 1; j <= length; j++)
		{
			int tX = j*(iDirection[i].offsetX);
			int tY = j*(iDirection[i].offsetY);
			iBoard[aX + tX][aY + tY] = iBlackTurn;  //change to his own color
		}
	}
	iBoard[aX][aY] = iBlackTurn; //set the chess
}

//----------------------------------------------
// Model::checkIfChessable
//
//
//-----------------------------------------------
bool Model::checkIfChessable()
{
	for (int i = 0; i<CBoardSize; i++)  //traverse all the chess board
	{
		for (int j = 0; j<CBoardSize; j++)
		{

			if (!checkIfHaveNeighbor(i, j)) //If the chess does not have neighbor
			{
				continue;
			}
			else  
			{
			   if (checkValidChess(i, j)) 
			  {
				return true;
			  }
		    }
		}
	}
	return false;
}

//----------------------------------------------
// Model::checkIfHaveNeighbor
//
//
//-----------------------------------------------
bool Model::checkIfHaveNeighbor(int aX, int aY)
{
	for (int i = ENorthWest; i <= ESouthEast; i++)
	{
		if (getChess(aX + iDirection[i].offsetX, aY + iDirection[i].offsetY)>EEmpty)  //check whether has chess at the giving direction
		{
			return true; 
		}
	}
	return false;
}
//----------------------------------------------
// Model::getTurn
//
//
//-----------------------------------------------
int Model::getTurn() const
{
	return iBlackTurn;
}