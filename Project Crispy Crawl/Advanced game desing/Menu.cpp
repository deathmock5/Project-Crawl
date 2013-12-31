#include "Menu.h"


Menu::Menu(void) : GameObject(CLASSTYPE_MENU)
{
	whiteArial24= al_load_font("arial.ttf", 24, 0);
	aDialogIsShown = false;
	isactive = false;
}

Menu::~Menu(void)
{

}

void Menu::draw()
{
	//Images
	for(int i = 0;i < (int)images.size();i++)
	{
		if(images[i] != NULL)
		{
			al_draw_bitmap(images[i],imagexpos[i],imageypos[i],0);
		}
	}
	//Buttons
	for(int i = 0;i < (int)btnactions.size();i++)
	{
		if(btnisdown[i])
		{
			al_draw_bitmap(btnimagesdown[i],btnxpos[i],btnypos[i],0);
		}
		else
		{
			al_draw_bitmap(btnimages[i],btnxpos[i],btnypos[i],0);
		}
	}
	//text
	for(int i = 0;i < (int)textvars.size();i++)
	{
		//std::string s
		char *a=new char[textvars[i].size()+1];
		a[textvars[i].size()]=0;
		memcpy(a,textvars[i].c_str(),textvars[i].size());
		al_draw_text(whiteArial24,al_map_rgb(255,255,255),numberbounds[i].getX(),numberbounds[i].getY(),ALLEGRO_ALIGN_LEFT,a);
	}
	//number
	for(int i = 0;i < (int)numberbounds.size();i++)
	{
		char str[20];
		int val = numbervars[i];
		_itoa_s(val,str,20);
		al_draw_text(whiteArial24,al_map_rgb(0,0,0),numberbounds[i].getX(),numberbounds[i].getY(),ALLEGRO_ALIGN_LEFT,str);
	}
	//dialogs
	if(aDialogIsShown)
	{
		al_draw_filled_rectangle(0,SCREEN_HEIGHT - 128.0f,SCREEN_WIDTH,SCREEN_HEIGHT,al_map_rgba(0,0,0,128));
		al_draw_bitmap(dialogImages[0],16.0f,SCREEN_HEIGHT - 112.0f,0);
		char *a=new char[dialogtexts[0].size()+1];
		a[dialogtexts[0].size()]=0;
		memcpy(a,dialogtexts[0].c_str(),dialogtexts[0].size());
		al_draw_text(whiteArial24,al_map_rgb(255,255,255),128,SCREEN_HEIGHT - 112.0f,0,a);
	}
	//gauge
	for(int i = 0;i < (int)gaugenames.size();i++)
	{
		//xpos ypos
		//vector<ALLEGRO_BITMAP*> gaugeimages;
		/*vector<string> gaugenames;
		vector<Bounds> gaugepositions;
		vector<int> gaugevalues;
		vector<int> gaugemaxes;
		vector<GAUGETYPES> gaugetypes;*/
		if(gaugetypes[i] == GAUGE_FILL)
			{
				//fill bar
				int amount = ((double)gaugevalues[i] * 0.01) * (double)gaugemaxes[i];
				al_draw_scaled_bitmap(gaugeimages[i],0,0,
					gaugepositions[i].getW(),
					gaugepositions[i].getH(),
					gaugepositions[i].getX(),
					gaugepositions[i].getY(),
					amount,
					gaugepositions[i].getH(),
					0);
			}
			else if(gaugetypes[i] == GAUGE_LAYER)
			{
				//overlay objects.
				int precentage;
				if(gaugevalues[i] > 0)
				{precentage = gaugepositions[i].getW() / gaugevalues[i];}
				for(int g = 0;g < gaugevalues[i];g++)
				{
					al_draw_bitmap(gaugeimages[i],gaugepositions[i].getX() + (precentage * g) ,gaugepositions[i].getY(),0);
				}
			}
	}
}

string Menu::hasScrolledOverOption(float x,float y)
{
	for(int i = 0;i < (int)btnactions.size();i++)
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
	if(aDialogIsShown)
	{
		dialogImages.erase(dialogImages.begin() + 0);
		dialogtexts.erase(dialogtexts.begin() + 0);
		if(dialogtexts.size() ==0)
		{
			aDialogIsShown = false;
		}
	}
}
void Menu::sendMessage(string data)
{
	if(isactive)
	{
		//logHelperMessage(INFO,2,"Got: ",data.c_str());
		if(data.substr(0,5) == "DIALO")
		{
			//add a new dialog;
			ALLEGRO_BITMAP* faceimg = load_image(myconcat(2,"Images\\Faces\\",data.substr(6,data.find(",") - 6).c_str()));
			string text = data.substr(data.find(",") + 1);
			addDialog(faceimg,text);

			showDialog();
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
}
void Menu::addImage(float x, float y, ALLEGRO_BITMAP *image)
{
	imagexpos.push_back(x);
	imageypos.push_back(y);
	images.push_back(image);
	//register.
}
void Menu::addText(Bounds varbounds,string uniqueName,string text)
{
	
		//TODO: make sure theres no duplicates
		textvars.push_back(text);
		textuniqueID.push_back(uniqueName);
		textbounds.push_back(varbounds);
}
void Menu::addNumber(Bounds varpos,string varuniqueid,int varvaluepointer)
{
	//TODO: determine if its the same.
	numberbounds.push_back(varpos);
	numberuniqueids.push_back(varuniqueid);
	numbervars.push_back(varvaluepointer);
}
void Menu::addGauge(ALLEGRO_BITMAP* image,Bounds pos,GAUGETYPES mytype,int max,string name)
{
	gaugeimages.push_back(image);
	gaugepositions.push_back(pos);
	gaugetypes.push_back(mytype);
	gaugevalues.push_back(0);
	gaugemaxes.push_back(max);
	gaugenames.push_back(name);
}
void Menu::addDialog(ALLEGRO_BITMAP* bg,string text)
{
	dialogImages.push_back(bg);
	dialogtexts.push_back(text);
}

void Menu::showDialog()
{
	aDialogIsShown = true;
}
void Menu::closeDialog()
{
	aDialogIsShown = false;
	//TODO: del the dialog
}
bool Menu::dialogActive()
{
	return aDialogIsShown;
}
void Menu::updateGaugeValue(string key,int newvalue)
{
	for(int i = 0;i < (int)gaugenames.size();i++)
	{
		if(gaugenames[i] == key)
		{
			gaugevalues[i] = newvalue;
		}
	}
}
void Menu::removeButton(string buttonaction)
{
	for(int i = 0; i < (int)btnactions.size(); i++)
	{
		if(buttonaction == btnactions[i])
		{
			//Match. KILL!
			btnactions.erase(btnactions.begin() + i);
			buttonactionpointers.erase(buttonactionpointers.begin() + i);
			btnimages.erase(btnimages.begin() + i);
			btnimagesdown.erase(btnimagesdown.begin() + i);
			btnxpos.erase(btnxpos.begin() + i);
			btnypos.erase(btnypos.begin() + i);
			btnisdown.erase(btnisdown.begin() + i);
		}
	}
}
void Menu::mouseLocation(int x,int y)
{
	curenthoverdoption = hasScrolledOverOption((int)x,(int)y);
	if(curenthoverdoption != "null")
	{
		
	}
}

void Menu::setClickSound(string sample)
{
	//TODO: clicksound
}
void Menu::setBgs(string sample)
{
	menubgs = sample;
}
void Menu::playBgs()
{
	//al_play_sample(bgs,0.5f,0,1,ALLEGRO_PLAYMODE_LOOP,&bgs_id);
	getGameRefrence()->sendMessageToAllObjects(myconcat(2,"BGM_PLAY_",menubgs.c_str()).c_str(),CLASSTYPE_SOUNDMANAGER);
}
void Menu::pauseBgs()
{
	
}
void Menu::setActive()
{
	isactive = true;
}
void Menu::setInactive()
{
	isactive = false;
}