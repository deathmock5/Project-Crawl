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
		//cout << "Drawing " << images[i] << " at: " << imagexpos[i] << "," << imageypos[i] << endl;
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

void Menu::acitonClick()
{
	//determine which one is clicked
	if(curenthoverdoption != "null")//if it issent null
	{
		for(int i = 0;i < (int)btnactions.size();i++)//look pthrough our list of avalible actions
		{
			if(btnactions[i] == curenthoverdoption)//if we have a match... which we should. activate it
			{
				if(buttonactionpointers[i] != NULL)
				{
					(*buttonactionpointers[i])();//alright, now call the vector of function pointers to call the function
					//then pray.
				}
				else
				{
					cout << "null";
				}
			}
		}
	}
}

void Menu::addButton(float x, float y, ALLEGRO_BITMAP *imageup,ALLEGRO_BITMAP *imagedown,string action,void (*function)())
{
	btnactions.push_back(action);
	buttonactionpointers.push_back(function);
	btnimages.push_back(imageup);
	btnimagesdown.push_back(imagedown);
	btnxpos.push_back(x);
	btnypos.push_back(y);
	btnisdown.push_back(false);
	buttons++;
}
void Menu::addText(float x,float y,string uniqueName,string* text)
{
	for(short i = 0;i < (short)textuniqueID.size();i++)
	{

	}
}

void Menu::addImage(float x, float y, ALLEGRO_BITMAP *image)
{
	imagexpos.push_back(x);
	imageypos.push_back(y);
	images.push_back(image);
	//register.
}

void Menu::removeButton(string buttonaction)
{
	//TODO: Look through list of buttons till you find the right one, then delete all entries of its position.
}
void Menu::mouseLocation(int x,int y)
{
	curenthoverdoption = hasScrolledOverOption((int)x,(int)y);
	if(curenthoverdoption != "null")
	{

	}
}