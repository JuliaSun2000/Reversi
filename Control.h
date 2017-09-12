#ifndef CONTROL_H_
#define CONTROL_H_


// User include
#include "chessConst.h"

// Forward declaration
class View;
class Model;

class Control {
public:
	/**
	* Constructor
	* @param none
	*
	*/
	Control();
	/**
	* Destructor
	* @param none
	*
	*/
	virtual ~Control();
	/**
	* Receive update from model
	* @param none
	*
	* @return none
	*/
	virtual void update();
	/**
	* Set the view handle
	* @param aView the view associated with control
	*
	* @return none
	*
	*/
	void setView(View* aView);
	/**
	* Set the model handle
	* @param aModel the model associated with control
	*
	* @return none
	*/
	void setModel(Model* aModel);
	/**
	* Get the value of the cell
	* @param aX the x coordiante
	* @param aY the y coordinate
	*
	* @return the value of the cell
	*/
	int getChess(int aX, int aY);
	/**
	* try to chess
	* @param aX the x coordinate
	* @param aY the y coordinate
	*
	* @return true if succeed, false if not
	*/
	bool tryChess(int aX, int aY);
private:
	/**
	* Decide who is the winner when game is over
	* @param none
	*
	* @return none
	*/
	void decideWinner();
private:
	// Own Counter to monitor the jumped move
	int iNoMoveCount;
	// Not Own Reference to View
	View* iView;
	// Not Own Reference to Model
	Model* iModel;
	// Own Event passed to View
	Event* iEvent;
	// Own Board Size
	static const int CBoardSize = 8;
};

#endif /* CONTROL_H_ */

