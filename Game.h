#ifndef GAME_H_
#define GAME_H_

// Forward declaration
class View;
class Model;
class Control;

class Game {
public:
	/**
	* Constructor
	* @param none
	*
	*/
	Game();
	/**
	* Destructor
	* @param none
	*
	*/
	virtual ~Game();
	/**
	* Play the game
	* @param none
	*
	* @return none
	*/
	void play();

private:
	// Own the handle of Control
	Control* iControl;
	// Own the handle of View
	View* iView;
	// Own the handle of Model
	Model* iModel;
};

#endif /* GAME_H_ */

