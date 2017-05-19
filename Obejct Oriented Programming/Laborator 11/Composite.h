#include <iostream>
#include <vector>
#include <string>

using namespace std;

class UIControl 
{

protected:

	int X, Y, Width, Height; // coordonatele controlului

	UIControl *Parent; // Parintele controlului (NULL inseamna ca nu are parinte)

public:

	virtual void Paint() = 0; // functie care deseneaza controlul

	virtual int GetX() = 0;

	virtual int GetY() = 0;

};



class UIButton : public UIControl
{
private:

	const static int activeBackground = 1;

	const static int inactiveBackground = 2;

	const static int activeForeground = 3;

	const static int inactiveForeground = 4;

	bool State;

	string Text;

public:
	UIButton(UIControl* parent, bool state, string text);

	void SetAttributes(int x, int y, int width, int height);

	UIControl* GetParent();

	virtual void Paint();

	virtual int GetX();

	virtual int GetY();

	void SetState(bool value);

	bool GetState();
};



class UILabel : public UIControl
{
private:
	const static int background = 5;

	const static int foreground = 6;

	string Text;


public:
	UILabel(UIControl* parent, string text, int x, int y);

	virtual void Paint();

	virtual int GetX();

	virtual int GetY();

	UIControl* GetParent();
};




class UIPanel : public UIControl
{
private:
	vector<UIControl*> Controls;

public:
	UIPanel(UIControl* parent, int x, int y);

	void AddControl(UIControl* control);

	virtual void Paint();

	virtual int GetX();

	virtual int GetY();

	UIControl* GetParent();
};
