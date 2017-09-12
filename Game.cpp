#include "Game.h"
#include "Control.h"
#include "View.h"
#include "Model.h"
#include <iostream>

//----------------------------------------------
// Game::Game
//
//
//-----------------------------------------------
Game::Game()
{
	iControl = new Control();
	iView = new View(iControl);
	iModel = new Model(iControl);
	iControl->setView(iView);
	iControl->setModel(iModel);
}

//----------------------------------------------
// Game::~Game
//
//
//-----------------------------------------------
Game::~Game()
{
	delete iModel;
	delete iView;
	delete iControl;

}

//----------------------------------------------
// Game::play
//
//
//-----------------------------------------------
void Game::play()
{
	iView->show();
}