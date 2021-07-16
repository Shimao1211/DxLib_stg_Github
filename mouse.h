//

//#

//
#include "game.h"
#include "shape.h"

//#

//
#define MOUSE_BUTTON_CODE 129	//

//#

//
struct MOUSE
{
	int InputValue = 0;	//
	int WheelValue = 0;	//
	iPOINT Point;						//
	iPOINT OldPoint;					//
	int OldButton[MOUSE_BUTTON_CODE];	//
	int Button[MOUSE_BUTTON_CODE];		//
};

//#

//
extern MOUSE mouse;

//#
//extern

extern VOID MouseUpdate(VOID);								//
extern BOOL MouseDown(int MOUSE_INPUT_);					//
extern BOOL MouseUp(int MOUSE_INPUT_);						//
extern BOOL MouseDownKeep(int MOUSE_INPUT_, int MilliTime);	//
extern BOOL MouseClick(int MOUSE_INPUT_);					//
extern VOID MouseDraw(VOID);								//
extern BOOL MouseMaruClick(MARU rect, int MOUSE_INPUT_);	//
