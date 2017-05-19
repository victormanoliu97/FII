#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include "Composite.h"

using namespace std;

void Print(int x, int y, int foreground, int background, const char* Text)

{

	COORD c;

	c.X = x;

	c.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (foreground & 0x0F) + ((background & 0x0F) << 4));

	printf("%s", Text);

}

UIButton::UIButton(UIControl* parent, bool state, string text)
{
	Parent = parent;

	State = state;

	Text = text;
}

UIControl* UIButton::GetParent()
{
	return Parent;
}

void UIButton::Paint()
{
	int background;

	int foreground;

	if (GetState())
	{
		background = activeBackground;
		foreground = activeForeground;
	}
	else
	{
		background = inactiveBackground;
		foreground = inactiveForeground;
	}

	if (GetParent() != NULL)
	{
		X = X + GetParent()->GetX();

		Y = Y + GetParent()->GetY();
	}

	int skips = (Width - Text.size()) / 2;

	int remainder;

	if ((Width - Text.size()) % 2 == 0)
	{
		remainder = skips;
	}
	else
	{
		remainder = skips + 1;
	}

	string filler = "";

	for (int i = 0; i < Height; i++)
	{
		filler = filler + " ";
	}

	bool pressed = false;

	for (int i = 0; i < Width; i++)
	{
		if (Width / 2 == i && !pressed)
		{
			string temporar = "";

			for (int j = 0; j < skips; j++)
			{
				temporar = temporar + " ";
			}

			temporar = temporar + Text;

			for (int j = 0; j < remainder; j++)
			{
				temporar = temporar + " ";
			}

			Print(X, Y + i, background, foreground, temporar.c_str());

			pressed = true;
		}
		else
		{
			Print(X, Y + i, background, foreground, filler.c_str());
		}
	}
}


void UIButton::SetAttributes(int x, int y, int width, int height)
{
	X = x;
	Y = y;
	Width = width;
	Height = height;
}

int UIButton::GetX()
{
	return X;
}

int UIButton::GetY()
{
	return Y;
}

void UIButton::SetState(bool state)
{
	State = state;
}

bool UIButton::GetState()
{
	return State;
}


// Label

UILabel::UILabel(UIControl* parent, string text, int x, int y)
{
	Parent = parent;
	Text = text;
	X = x;
	Y = y;
}

UIControl* UILabel::GetParent()
{
	return Parent;
}

void UILabel::Paint()
{
	if (GetParent() != NULL)
	{
		X = X + GetParent()->GetX();

		Y = Y + GetParent()->GetY();
	}

	Print(X, Y, foreground, background, Text.c_str());
}

int UILabel::GetX()
{
	return X;
}

int UILabel::GetY()
{
	return Y;
}


// Panel

UIPanel::UIPanel(UIControl* parent, int x, int y)
{
	Parent = parent;
	X = x;
	Y = y;
}

UIControl* UIPanel::GetParent()
{
	return Parent;
}


void UIPanel::AddControl(UIControl* controls)
{
	Controls.push_back(controls);
}

void UIPanel::Paint()
{
	for (auto it = Controls.begin(); it != Controls.end(); it++)
	{
		(*it)->Paint();
	}
}

int UIPanel::GetX()
{
	return X;
}

int UIPanel::GetY()
{
	return Y;
}
