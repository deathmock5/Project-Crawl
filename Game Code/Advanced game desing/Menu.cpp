#include "Menu.h"


Menu::Menu(void)
{
	
	buttons = 0;
	
}


Menu::~Menu(void)
{

}

void Menu::draw()
{
	for(int i = 0;i < (int)images.size();i++)
	{
		cout << "Drawing " << images[i] << " at: " << imagexpos[i] << "," << imageypos[i] << endl;
		if(images[i] != NULL)
		{
			al_draw_bitmap(images[i],imagexpos[i],imageypos[i],0);
		}
	}
	for(int i = 0;i < buttons;i++)
	{
		if(btnisdown[i])
		{
			al_draw_bitmap(btnimagesdown[i],btnxpos[i],btnypos[i],0);
		}
		else
		{
			al_draw_bitmap(btnimages[i],btnxpos[i],btnypos[i],0);
		}
		//cout << "Drawn at: " << btnxpos[i] << "," << btnypos[i] << endl;
	}
	
}

string Menu::hasScrolledOverOption(float x,float y)
{
	for(int i = 0;i < buttons;i++)
	{
		if(x < btnxpos[i] + al_get_bitmap_width(btnimages[i]) &&
		x > btnxpos[i] &&
		y < btnypos[i] + al_get_bitmap_height(btnimages[i]) &&
		y > btnypos[i])
		{
			btnisdown[i] = true;
			return btnactions[i];
		}
		else
		{
			btnisdown[i] = false;
			//cout << "not inrange pos" << x << "," << y << endl;
		}
	}
	return "null";
}

void Menu::acitonClick(string action)
{
	//determine which one is clicked
	if(action != "null")
	{
		if(action == "bla")
		{

		}
	}
}

void Menu::addButton(float x, float y, ALLEGRO_BITMAP *imageup,ALLEGRO_BITMAP *imagedown,string action)
{
	btnactions.push_back(action);
	btnimages.push_back(imageup);
	btnimagesdown.push_back(imagedown);
	btnxpos.push_back(x);
	btnypos.push_back(y);
	btnisdown.push_back(false);
	buttons++;
}

void Menu::addImage(float x, float y, ALLEGRO_BITMAP *image)
{
	imagexpos.push_back(x);
	imageypos.push_back(y);
	images.push_back(image);
	//register.
}
