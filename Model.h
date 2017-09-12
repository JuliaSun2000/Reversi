#ifndef MODEL_H_
#define MODEL_H_

// User include
#include "chessConst.h"

// Forward declaration
class Control;

class Model {
public:
	/**
	* Constructor
	* @param aControl reference to control
	*
	*/
	Model(Control* aControl);
	/**
	* Destructor
	* @param none
	*
	*/
	virtual ~Model();
	/**
	* Get the cell value
	* @param aX the x coordinate
	* @param aY the y coordinate
	*
	* @return the value of cell
	*
	*/
	int getChess(int aX, int aY);
	/**
	* Check if there is a valid chess
	* @param aX the x coordinate
	* @param aY the y coordinate
	*
	* @return true if there is, false if not
	*
	*/
	bool checkValidChess(int aX, int aY);
	
	/**
	* get the length of the chess with different color at given direction
	* @aDirection the enumeration of given direction
	* @param aX the x coordinate
	* @param aY the y coordinate
	*
	* @return 0 if not a valid check coordinate, otherwise return the length of
	* opponent chess
	*
	*/
	int getOpponentLength(DirectionEnum aDirection, int aX, int aY, int aChessColor);
	/**
	* try to chess
	* @param aX the x coordinate
	* @param aY the y coordinate
	*
	* @return true if succeed, false if not
	*/
	bool tryChess(int aX, int aY);
	/**
	* Move to next turn
	* @param none
	*
	* @return none
	*/
	void moveToNextTurn();
	/**
	* Check if there is any valid chess for current player
	* @param none
	*
	* @return true if there is, false if not
	*/
	bool checkIfChessable();

	/**
	* Get the current Turn
	* @param none
	*
	* @return the value of current player
	*/
	int getTurn() const;
private:
	/**
	* setChess
	* @param aX the x coordinate
	* @param aY the y coordinate
	*
	* @return none
	*/
	void setChess(int aX, int aY);
	/**
	* Check if there is any neighbor around, used to boost the execution speed of checkIfCheessable
	* @param aX the x coordinate
	* @param aY the y coordinate
	**
	* @return true if there is, false if not
	*/
	bool checkIfHaveNeighbor(int aX, int aY);
private:
	// Own Board size
	static const int CBoardSize = 8;
	// Not Own Reference to control
	Control* iControl;
	// Own current player
	int iBlackTurn;
	// Own Chess board
	int iBoard[CBoardSize][CBoardSize];
	// Own offset of coordinate of each direction
	Direction iDirection[CBoardSize + 1];

};

#endif /* MODEL_H_ */
