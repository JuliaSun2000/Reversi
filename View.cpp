#include <string>
#include <iostream>
#include <stdio.h>
// User include
#include "View.h"
#include "Control.h"

//----------------------------------------------
// View::View
//
//
//-----------------------------------------------
View::View(Control* aControl)
	:iVisable(false), iControl(aControl)
{
	// Board Element initialization
	boardElement[0] = "©°©¤";
	boardElement[1] = "©Ð©¤";
	boardElement[2] = "©´";
	boardElement[3] = "©À©¤";
	boardElement[4] = "©à©¤";
	boardElement[5] = "©È";
	boardElement[6] = "©¸©¤";
	boardElement[7] = "©Ø©¤";
	boardElement[8] = "©¼";

	// content elment initialization
	chessElement[0] = "  ";
	chessElement[1] = "¡õ";
	chessElement[2] = "¡ö";
}

//----------------------------------------------
// View::~View
//
//
//-----------------------------------------------
View::~View()
{
	// TODO Auto-generated destructor stub
}

//----------------------------------------------
// View::Show
//
//
//-----------------------------------------------
void View::show()
{
		refresh(0);
	
}

//----------------------------------------------
// View::refresh
//
//
//-----------------------------------------------
void View::refresh(Event* aEvent)
{
	if (aEvent == 0)
	{
		draw();
		askInput();
	}
	else
	{
		draw();
		if (aEvent->iMsg.length() > 0)
		{
			std::cout << aEvent->iMsg << std::endl;
		}
		if (aEvent->iEventType == EWaitForInput)
		{
			askInput();
		}
	}
}

//----------------------------------------------
// View::draw
//
//
//-----------------------------------------------
void View::draw()
{
	for (int i = 0; i<CDirectonCount; i++)
	{
		for (int j = 0; j<CDirectonCount; j++)
		{
			std::cout << boardElement[(int)getBoardElementIndex(i, j)];//ex:getBoardElementIndex(i, j)->EMiddleLeft(3);boardElement[3];
		}
		std::cout << std::endl;
		if (i < CDirectonCount - 1)
		{
			for (int j = 0; j < CDirectonCount - 1; j++)
			{
				std::cout << "©¦" << chessElement[iControl->getChess(i, j) + 1];  //-1+1=0; chessElement[0] = "  ";
			}
			std::cout << "©¦" << i << std::endl;
		}
	}
	for (int i = 0; i < CDirectonCount - 1; i++)
	{
		std::cout << "   " << i;
	}
	std::cout << std::endl;
}

void View::askInput()
{
	int tX, tY;
	bool warning = false;
	do
	{
		if (warning)
		{
			std::cout << "Sorry, the coordinate you input seems not valid, please try again" << std::endl;
		}

		std::cout << "Please input the coordinate you want to put your chess:" << std::endl;
		std::cout << "Please input x:" << std::endl;
		std::cin >> tX;
		std::cout << "Please input y:" << std::endl;
		std::cin >> tY;
		warning = true;
	} while (!iControl->tryChess(tX, tY));

}

//----------------------------------------------
// View::setVisible
//
//
//-----------------------------------------------
//void View::setVisible(bool aVisable)
//{
//	iVisable = aVisable;
//}

//----------------------------------------------
// View::getBoardElementIndex
//
//
//-----------------------------------------------
PositionEnum View::getBoardElementIndex(int aX, int aY)
{
	if (aX == 0)
	{
		if (aY == 0)
		{
			return ETopLeft;
		}
		else if (aY == CBoardSize) //y=8
		{
			return ETopRight;
		}
		else
		{
			return ETopMiddle;
		}
	}
	else if (aX == CBoardSize)   //X=8
	{
		if (aY == 0)
		{
			return EBottomLeft;
		}
		else if (aY == CBoardSize)
		{
			return EBottomRight;
		}
		else
		{
			return EBottomMiddle;
		}
	}
	else
	{
		if (aY == 0)
		{
			return EMiddleLeft;
		}
		else if (aY == CBoardSize)
		{
			return EMiddleRight;
		}
		else
		{
			return EMiddleMiddle;
		}
	}
}