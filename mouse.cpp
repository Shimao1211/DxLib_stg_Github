//

//#
#include "game.h"
#include "mouse.h"
#include "FPS.h"

//
MOUSE mouse;

//#

/// <summary>
/// 
/// </summary>
/// <param name=""></param>
VOID MouseUpdate(VOID)
{
	//
	mouse.OldPoint = mouse.Point;

	//
	mouse.OldButton[MOUSE_INPUT_LEFT] = mouse.Button[MOUSE_INPUT_LEFT];
	mouse.OldButton[MOUSE_INPUT_MIDDLE] = mouse.Button[MOUSE_INPUT_MIDDLE];
	mouse.OldButton[MOUSE_INPUT_RIGHT] = mouse.Button[MOUSE_INPUT_RIGHT];

	//
	GetMousePoint(&mouse.Point.x, &mouse.Point.y);

	//マウスの座標が画面外の場合は、画面内に収める
	if (mouse.Point.x < 0) { mouse.Point.x = 0; }
	if (mouse.Point.x > GAME_WIDTH) { mouse.Point.x = GAME_WIDTH; }
	if (mouse.Point.y < 0) { mouse.Point.y = 0; }
	if (mouse.Point.y > GAME_HEIGHT) { mouse.Point.y = GAME_HEIGHT; }

	//
	mouse.InputValue = GetMouseInput();

	//
	if ((mouse.InputValue & MOUSE_INPUT_LEFT) == MOUSE_INPUT_LEFT) { mouse.Button[MOUSE_INPUT_LEFT]++; }	//
	if ((mouse.InputValue & MOUSE_INPUT_LEFT) != MOUSE_INPUT_LEFT) { mouse.Button[MOUSE_INPUT_LEFT] = 0; }	//

	//
	if ((mouse.InputValue & MOUSE_INPUT_MIDDLE) == MOUSE_INPUT_MIDDLE) { mouse.Button[MOUSE_INPUT_MIDDLE]++; }	//
	if ((mouse.InputValue & MOUSE_INPUT_MIDDLE) != MOUSE_INPUT_MIDDLE) { mouse.Button[MOUSE_INPUT_MIDDLE] = 0; }//

	//
	if ((mouse.InputValue & MOUSE_INPUT_RIGHT) == MOUSE_INPUT_RIGHT) { mouse.Button[MOUSE_INPUT_RIGHT]++; }	//
	if ((mouse.InputValue & MOUSE_INPUT_RIGHT) != MOUSE_INPUT_RIGHT) { mouse.Button[MOUSE_INPUT_RIGHT] = 0; }	//

	//
	mouse.WheelValue = GetMouseWheelRotVol();

	return;
}

/// <summary>
/// 
/// </summary>
/// <param name="MOUSE_INPUT"></param>
/// <returns></returns>
BOOL MouseDown(int MOUSE_INPUT_)
{
	//
	if (mouse.Button[MOUSE_INPUT_] != 0)
	{
		return TRUE;	//
	}
	else
	{
		return FALSE;	//
	}
}


BOOL MouseUp(int MOUSE_INPUT_)
{
	//
	if (mouse.OldButton[MOUSE_INPUT_] >= 1	//
		&& mouse.Button[MOUSE_INPUT_] == 0)	//
	{
		return TRUE;	//
	}
	else
	{
		return FALSE;	//
	}
}

BOOL MouseDownKeep(int MOUSE_INPUT_, int milliTime)
{
	float MilliSec = 1000.0f;	//

	//
	//
	int UpdateTime = (milliTime / MilliSec) * fps.Value;

	if (mouse.Button[MOUSE_INPUT_] > UpdateTime)
	{
		return TRUE;	//
	}
	else
	{
		return FALSE;	//
	}
}

BOOL MouseClick(int MOUSE_INPUT_)
{
	if (mouse.OldButton[MOUSE_INPUT_] >= 1	//
		&& mouse.Button[MOUSE_INPUT_] == 0)	//
	{
		return TRUE;	//
	}
	else
	{
		return FALSE;	//
	}
}

VOID MouseDraw(VOID)
{
	if (GAME_DEBUG == TRUE)	//
	{
		//
		DrawFormatString(0, GAME_HEIGHT - 40, GetColor(255, 255, 255), "MOUSE[X:%4d/Y:%4d", mouse.Point.x, mouse.Point.y);
	}

	return;
}

BOOL MouseRectClick(RECT rect, int MOUSE_INPUT_)
{
	//
	if (CheckColliPointToRect(mouse.Point, rect) == TRUE)
		{
			//
			return MouseClick(MOUSE_INPUT_);
		}

		return FALSE;
}

BOOL MouseMaruClick(MARU circle, int MOUSE_INPUT_)
{
	//
	if (CheckColliPointToMaru(mouse.Point, circle) == TRUE)
	{
		//
		return MouseClick(MOUSE_INPUT_);
	}

	return FALSE;
}