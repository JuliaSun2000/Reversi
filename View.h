#ifndef VIEW_H_
#define VIEW_H_

// User include
#include "chessConst.h"

// Forward declaration
class Control;

template<typename T>
struct Rect
{
	/**
	* Constructor
	* @templ T template of the type
	* @param aTopLeftX, the x coordinate of top left
	* @param aTopLeftY, the y coordinate of top left
	* @param aBottomRightX, the x coordinate of bottom right
	* @param aBottomRighX, the y coordinate of bottom right
	*
	*/
	Rect(T aTopLeftX, T aTopLeftY, T aBottomRightX, T aBottomRightY)
		:topLeftX(aTopLeftX), topLeftY(aTopLeftY), bottomRightX(aBottomRightX), bottomRightY(aBottomRightY)
	{};

	// own X coordinate of top left point
	T topLeftX;
	// own Y coordinate of top left point
	T topLeftY;
	// own X coordinate of bottom right point
	T bottomRightX;
	// own Y coordinate of bottom right point
	T bottomRightY;
};


class View {
public:
	/**
	* Constructor
	* @param aControl reference to control
	*
	*/
	View(Control * aControl);
	/**
	* Destructor
	* @param none
	*
	*/
	virtual ~View();
	/**
	* Set the visibility of View
	* @param aVisable true for visible
	*
	* @return none
	*/
	void setVisible(bool aVisable);
	/**
	* draw the view
	* @param none
	*
	* @return none
	*/
	virtual void draw();
	/**
	* Refresh the view
	* @aEvent reference to event
	*
	* @return none
	*/
	virtual void refresh(Event* aEvent);
	/**
	* set  geometry of the view, future usage
	* @param aRect the size of the view
	*
	* @return none
	*/
	void setGeometry(Rect<double> aRect);
	/**
	* set  geometry of the view, future usage
	* @param aRect the size of the view
	*
	* @return none
	*/
	void setGeometry(int aTopLeftX, int aTopLeftY, int aBottomRightX, int aBootmRightY);
	/**
	* try to chess
	* @param aX the x coordinate
	* @param aY the y coordinate
	*
	* @return true if succeed, false if not
	*/
	bool tryChess(int aX, int aY);
	/**
	* Show the view, view must be set visible
	* @param none
	*
	* @return none
	*/
	virtual void show();
private:
	/**
	* Internal function, get the value of the cell
	* @param aX the x coordiante
	* @param aY the y coordinate
	*
	* @return the value of the cell
	*/
	int getValue(int aX, int aY);
	/**
	* Internal function, get the index of board elements to draw the board
	* @param aX the x coordinate
	* @param aY the y coordinate
	*
	* @return the index of the board element
	*/
	PositionEnum getBoardElementIndex(int aX, int aY);
	/**
	* Request input from user
	* @param none
	*
	* @return none
	*/
	void askInput();
private:
	// Own value of Direction
	static const int CDirectonCount = 9;
	// Own value of Size of View
	static const int CBoardSize = 8;
	// Own visibility of view
	bool iVisable;
	// Not own, reference to control
	Control *iControl;
	// Own the board element used to draw the board
	std::string boardElement[CDirectonCount + 1];
	// Own the content of cell used to draw the chess
	std::string chessElement[3];
};

#endif /* VIEW_H_ */
