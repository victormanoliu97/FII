#include <iostream>
#include "Composite.h"

int main()
{
	UIButton *my_button = new UIButton(NULL, true, "Salut");

	my_button->SetAttributes(0, 1, 10, 10);

	my_button->SetState(false);

	my_button->Paint();

	
	UILabel *my_label = new UILabel(NULL, "Salut2", 2, 3);
	my_label->Paint();


	UIPanel* my_panel = new UIPanel(NULL, 100, 100);


}