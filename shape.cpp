//

//#

#include "game.h"
#include "shape.h"
#include "math.h"

//#

//#

/// <summary>
/// 
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns></returns>
BOOL CheckCollRectToRect(RECT a, RECT b)
{
	if (a.left < b.right &&
		a.top < b.bottom &&
		a.right > b.left &&
		a.bottom > b.top
		)
	{
		return TRUE;	//
	}

	return FALSE;		//
}

/// <summary>
/// 
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns></returns>
BOOL CheckColliPointToRect(iPOINT pt, RECT r)
{
	if (
		pt.x > r.left && pt.x < r.right		//
		&& pt.y > r.top && pt.y < r.bottom	//
		)
	{
		return TRUE;	//
	}

	return FALSE;		//
}

/// <summary>
/// 
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns></returns>
BOOL CheckColliPointToMaru(iPOINT pt, MARU m)
{
	//
	
	//
	float a = pt.x - m.center.x;	//
	float b = pt.y - m.center.y;	//
	float c = sqrtf(a * a + b * b);	//

	//
	if (c <= m.radius)
	{
		return TRUE;	//
	}

	return FALSE;		//
}

/// <summary>
/// 
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns></returns>
BOOL CheckColliMaruToMaru(MARU maru1, MARU maru2)
{
	//

	//
	float a = maru1.center.x - maru2.center.x;	//
	float b = maru1.center.y - maru2.center.y;	//
	float c = sqrtf(a * a + b * b);	//

	//
	if (c <= maru1.radius + maru2.radius)
	{
		return TRUE;	//
	}

	return FALSE;		//
}

/// <summary>
/// 
/// </summary>
/// <param name="left"></param>
/// <param name="top"></param>
/// <param name="right"></param>
/// <param name="bottom"></param>
/// <returns></returns>
RECT GetRect(int left, int top, int right, int bottom)
{
	//
	RECT rect = { left ,top ,right ,bottom };

	//
	return rect;
}


VOID DrawRect(RECT r, unsigned int color, bool b)
{
	//
	DrawBox(r.left, r.top, r.right, r.bottom, color, b);
	return;
}

VOID DrawMaru(MARU c, unsigned int color, bool b, int thick)
{
	//
	DrawCircle(c.center.x, c.center.y, c.radius, color, b, thick);
	return;
}