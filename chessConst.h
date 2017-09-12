#ifndef CHESSCONST_H_
#define CHESSCONST_H_

// System include
#include <string>

enum DirectionEnum {
	ENorthWest, //(-1,-1)
	ENorth,     //(-1,0)
	ENorthEast, //(-1,1)
	EWest,      //(0,-1)
	EEast,      // (0,1)
	ESouthWest, // (1,-1)
	ESouth,     // (1,0)
	ESouthEast  // (1,1)
};

enum BoardValueEnum {
	EUndef = -2,
	EEmpty = -1,
	EWhite = 0,
	EBlack = 1
};

struct Direction
{
	int offsetX;
	int offsetY;
};

enum EventEnum
{
	EWaitForInput,
	ENextTurn,
	EEnd
};

struct Event
{
	std::string iMsg;
	EventEnum iEventType;
};

enum PositionEnum
{
	ETopLeft = 0,
	ETopMiddle,
	ETopRight,
	EMiddleLeft,
	EMiddleMiddle,
	EMiddleRight,
	EBottomLeft,
	EBottomMiddle,
	EBottomRight
};
#endif /* CHESSCONST_H_ */

