#include <sstream>

// User include
#include "Control.h"
#include "View.h"
#include "Model.h"
#include "chessConst.h"

//----------------------------------------------
// Control::Control
//
//
//-----------------------------------------------
Control::Control()
	:iNoMoveCount(0), iView(0), iModel(0)
{
	iEvent = new Event();
}

//----------------------------------------------
// Control::~Control
//
//
//-----------------------------------------------
Control::~Control()
{
	delete iEvent;
}

//----------------------------------------------
// Control::setView
//
//
//-----------------------------------------------
void Control::setView(View* aView)
{
	iView = aView;
}

//----------------------------------------------
// Control::setModel
//
//
//-----------------------------------------------
void Control::setModel(Model* aModel)
{
	iModel = aModel;
}

//----------------------------------------------
// Control::getChess
//
//
//-----------------------------------------------
int Control::getChess(int aX, int aY)
{
	return iModel->getChess(aX, aY);
}

//----------------------------------------------
// Control::update
//
//
//-----------------------------------------------
void Control::update()
{
	if (iNoMoveCount >= 2)  //If two player don't have valid chess
	{
		decideWinner();
	}
	else
	{
		if (!iModel->checkIfChessable()) //If this player don't have valid chess
		{
			iNoMoveCount++;
			iEvent->iMsg = "No more Move, Jump turn\n";
			iEvent->iEventType = ENextTurn;
			iView->refresh(iEvent);
			iModel->moveToNextTurn();
		}
		else  
		{
			iNoMoveCount = 0;
			std::stringstream ss;
			if (iModel->getTurn() == 0) //If now is white player
			{
				ss << "\nWhite Player: ";
			}
			else
			{
				ss << "\nBlack Player: ";
			}
			iEvent->iMsg = ss.str() + "Now its your turn\n";
			iEvent->iEventType = EWaitForInput;
			iView->refresh(iEvent);
		}
	}
}

//----------------------------------------------
// Control::decideWinnter
//
//
//-----------------------------------------------
void Control::decideWinner()
{
	int whiteCount = 0;
	int blackCount = 0;
	for (int i = 0; i< CBoardSize; i++)
	{
		for (int j = 0; j<CBoardSize; j++)
		{
			int value = iModel->getChess(i, j);
			{
				if (value < 0)
				{
					continue;
				}
				else
				{
					if (value == static_cast<int>(EWhite))
					{
						whiteCount++;
					}
					else
					{
						blackCount++;
					}
				}
			}
		}
	}
	std::stringstream ss;
	ss << "Scores:\n" << "White Player: " << whiteCount << " vs " << "Black Player: " << blackCount << "\n";
	if (whiteCount > blackCount)
	{
		iEvent->iMsg = "White Wins\n" + ss.str();
	}
	else if (whiteCount == blackCount)
	{
		iEvent->iMsg = "Draw\n" + ss.str();
	}
	else
	{
		iEvent->iMsg = "Black Wins\n" + ss.str();
	}
	iEvent->iEventType = EEnd;
	iView->refresh(iEvent);
}

//----------------------------------------------
// Control::tryChess
//
//
//-----------------------------------------------
bool Control::tryChess(int aX, int aY)
{
	return iModel->tryChess(aX, aY);
}