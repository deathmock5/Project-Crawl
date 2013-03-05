//Allegro Imports
#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
#include <allegro5\allegro_image.h>


//system imports
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;


//refrenced classes and namespaces
#include "SystemVars.h"
#include "Player.h"
#include "Map.h"
#include "Menu.h"
enum keys{BUTTONCLICKED,STATECHANGED};
bool buttonPressed[2][4] = {{false,false,false,false},
							{false,false,false,false}};


bool anyButtonChangedStatus();
bool anyButtonIsPressed();
bool noOtherButtonsArePressed(int);
void buttonHelper();

enum gameGuiState{MAIN,OPTION,MULTIPLAYER,INGAME,SHOP,INVINTORY,SAVELOAD,WORLDMAP};

Menu mainmenu;
void mainMenuClickSingle();
void mainMenuClickMulti();
void mainMenuClickOption();
void mainMenuClickExit();
void gameGUIMain(ALLEGRO_EVENT);

Menu menuoptions = Menu();
void gameGUIOption(ALLEGRO_EVENT);

Menu menumulti = Menu();
void gameGUIMultiplayer(ALLEGRO_EVENT);

Menu menuingame = Menu();
void gameGUIIngame(ALLEGRO_EVENT);

Menu menucutscene = Menu();
void gameGUICutscene(ALLEGRO_EVENT);

Menu menushop = Menu();
void gameGUIShop(ALLEGRO_EVENT);

Menu menuinvintory = Menu();
void gameGUIInvintry(ALLEGRO_EVENT);

Menu menusaveload = Menu();
void gameGUISaveLoad(ALLEGRO_EVENT);

Menu menuworldmap = Menu();
void gameGUIWorldMap(ALLEGRO_EVENT);

void initMenus();
//game variables
Map mymap;
gameGuiState curentstate;
bool done = false;
bool redraw = false;
ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *timer = NULL;
int pos_x = 0;
int pos_y = 0;

int main(int argc, char **argv)
{
	ALLEGRO_SAMPLE *bgs;
	
	if(!al_init())
		return -1; //Init
	display = al_create_display(SystemVars::SCREEN_WIDTH, SystemVars::SCREEN_HEIGHT); //make display

	if(!display)
		return -1;

	//init
	al_init_primitives_addon();									//init primitives
	al_install_keyboard();										//init keyboard
	al_install_mouse();											//init mouse
	al_install_audio();											//init audio
	al_init_font_addon();										//init font
	al_init_ttf_addon();										//init ttf
	al_init_acodec_addon();										//init codec
	al_init_image_addon();
	timer = al_create_timer(1.0 / SystemVars::FPS);

	al_reserve_samples(100);
	//bgs = al_load_sample("snd\\01.wav");
	//al_play_sample(bgs,0.5f,0,1,ALLEGRO_PLAYMODE_LOOP,NULL);
	mymap = Map("Lv1",1);
	initMenus();
	curentstate = MAIN;
	al_set_blender(ALLEGRO_ADD, ALLEGRO_ONE, ALLEGRO_INVERSE_ALPHA);
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_start_timer(timer);
	while(!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		switch (curentstate)
		{
		case MAIN:
			gameGUIMain(ev);
			break;
		case OPTION:
			gameGUIOption(ev);
			break;
		case MULTIPLAYER:
			gameGUIMultiplayer(ev);
			break;
		case INGAME:
			gameGUIIngame(ev);
			break;
		case SHOP:
			gameGUIShop(ev);
			break;
		case INVINTORY:
			gameGUIInvintry(ev);
			break;
		case SAVELOAD:
			gameGUISaveLoad(ev);
			break;
		case WORLDMAP:
			gameGUIWorldMap(ev);
			break;
		default:
			cout << "Unrecignised gamestate:" << endl;
			return 1;
			break;
		}
	}
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);
	return 0;
}
bool anyButtonChangedStatus()
{
	for(int i = 0;i < 4;i++)
	{
		if(buttonPressed[1][i])
		{
			return true;
		}
	}
	return false;
}
bool anyButtonIsPressed()
{
	for(int i = 0;i < 4;i++)
	{
		if(buttonPressed[0][i])
		{
			return true;
		}
	}
	return false;
}
bool noOtherButtonsArePressed(int dir)
{
	for(int i = 0;i < 4;i++)
	{
		if(buttonPressed[0][i])
		{
			if(dir != i)
			{
				return false;
			}
		}
	}
	return true;
}
void buttonHelper()
{
	if(anyButtonChangedStatus())
	{
			if(anyButtonIsPressed())
			{
				if(buttonPressed[BUTTONCLICKED][BACK] && buttonPressed[STATECHANGED][BACK])
				{
					mymap.players[0].processInput(WALK,BACK);
				}
				else if(buttonPressed[BUTTONCLICKED][LEFT] && buttonPressed[STATECHANGED][LEFT])
				{
					mymap.players[0].processInput(WALK,LEFT);
				}
				else if(buttonPressed[BUTTONCLICKED][RIGHT] && buttonPressed[STATECHANGED][RIGHT])
				{
					mymap.players[0].processInput(WALK,RIGHT);
				}
				else if(buttonPressed[BUTTONCLICKED][FORWARD] && buttonPressed[STATECHANGED][FORWARD])
				{
					mymap.players[0].processInput(WALK,FORWARD);
				}
				else if(noOtherButtonsArePressed(BACK))
				{
					mymap.players[0].processInput(WALK,BACK);
				}
				else if(noOtherButtonsArePressed(LEFT))
				{
					mymap.players[0].processInput(WALK,LEFT);
				}
				else if(noOtherButtonsArePressed(RIGHT))
				{
					mymap.players[0].processInput(WALK,RIGHT);
				}
				else if(noOtherButtonsArePressed(FORWARD))
				{
					mymap.players[0].processInput(WALK,FORWARD);
				}
			}
			else
			{
				if(buttonPressed[STATECHANGED][BACK])
					mymap.players[0].processInput(STAND,BACK);
				else if(buttonPressed[STATECHANGED][LEFT])
					mymap.players[0].processInput(STAND,LEFT);
				else if(buttonPressed[STATECHANGED][RIGHT])
					mymap.players[0].processInput(STAND,RIGHT);
				else if(buttonPressed[STATECHANGED][FORWARD])
					mymap.players[0].processInput(STAND,FORWARD);
			}
		buttonPressed[STATECHANGED][BACK] = false;
		buttonPressed[STATECHANGED][RIGHT] = false;
		buttonPressed[STATECHANGED][FORWARD] = false;
		buttonPressed[STATECHANGED][LEFT] = false;
	}
}

void gameGUIMain(ALLEGRO_EVENT ev)
{
	if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch(ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
				}
		}
		else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			{
				done = true;
			}
		else if(ev.type == ALLEGRO_EVENT_MOUSE_AXES)
			{
				mainmenu.mouseLocation(ev.mouse.x,ev.mouse.y);
			}
		else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			mainmenu.acitonClick();
		}
		else if(ev.type = ALLEGRO_EVENT_TIMER)
		{
			redraw = true;
		}
		
		if(redraw == true && al_event_queue_is_empty(event_queue))
		{
			redraw = false;
			al_clear_to_color(al_map_rgb(0,0,0));

			mainmenu.draw();
			al_flip_display();
		}
}	//Main menu
void mainMenuClickSingle()
{
	//TODO: mainMenuClickSingle() goto loadGame
	cout << "Gamestate set to single";
	curentstate = INGAME;
}
void mainMenuClickMulti()
{
	//TODO: mainMenuClickMulti()
}
void mainMenuClickOption()
{
	//TODO: mainMenuClickOption()
}
void mainMenuClickExit()
{
	//TODO: mainMenuClickExit()
}

void gameGUIOption(ALLEGRO_EVENT ev)
{
	//TODO: Setup Option menu
}
void gameGUIMultiplayer(ALLEGRO_EVENT ev)
{
	//TODO: Setup multiplayer menu
}

void gameGUIIngame(ALLEGRO_EVENT ev)
{
	if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch(ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_W:
				buttonPressed[BUTTONCLICKED][BACK] = true;
				buttonPressed[STATECHANGED][BACK] = true;
				break;
			case ALLEGRO_KEY_A:
				buttonPressed[BUTTONCLICKED][LEFT] = true;
				buttonPressed[STATECHANGED][LEFT] = true;
				break;
			case ALLEGRO_KEY_S:
				buttonPressed[BUTTONCLICKED][FORWARD] = true;
				buttonPressed[STATECHANGED][FORWARD] = true;
				break;
			case ALLEGRO_KEY_D:
				buttonPressed[BUTTONCLICKED][RIGHT] = true;
				buttonPressed[STATECHANGED][RIGHT] = true;
				break;
			}
			buttonHelper();
		}
		else if(ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch(ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_W:
				if(buttonPressed[BUTTONCLICKED][BACK])
				{
					//if(noOtherButtonsArePressed(BACK))
						buttonPressed[STATECHANGED][BACK] = true;
					buttonPressed[BUTTONCLICKED][BACK] = false;
				}
				break;
			case ALLEGRO_KEY_A:
				if(buttonPressed[BUTTONCLICKED][LEFT])
				{
					//if(noOtherButtonsArePressed(LEFT))
						buttonPressed[STATECHANGED][LEFT] = true;
					buttonPressed[BUTTONCLICKED][LEFT] = false;
				}
				break;
			case ALLEGRO_KEY_S:
				if(buttonPressed[BUTTONCLICKED][FORWARD])
				{
					//if(noOtherButtonsArePressed(FORWARD))
						buttonPressed[STATECHANGED][FORWARD] = true;
					buttonPressed[BUTTONCLICKED][FORWARD] = false;
				}
				break;
			case ALLEGRO_KEY_D:
				if(buttonPressed[BUTTONCLICKED][RIGHT])
				{
					//if(noOtherButtonsArePressed(RIGHT))
						buttonPressed[STATECHANGED][RIGHT] = true;
					buttonPressed[BUTTONCLICKED][RIGHT] = false;
				}
				break;
			}
			buttonHelper();
		}
		else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			{
				done = true;
			}
		else if(ev.type == ALLEGRO_EVENT_MOUSE_AXES)
		{
			pos_x = ev.mouse.x;
			pos_y = ev.mouse.y;
		}
		else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			//TODO: Handle buttons on mouse clicked
			mymap.players[0].processInput(ATACK,mymap.players[0].getFaceingDir(pos_x,pos_y));
		}
		else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
		{
			//TODO: Handle buttons on mouse un clicked
		}
		else if(ev.type = ALLEGRO_EVENT_TIMER)
		{
			redraw = true;
		}
		
		if(redraw == true && al_event_queue_is_empty(event_queue))
		{
			redraw = false;
			al_clear_to_color(al_map_rgb(0,0,0));
			
			
			mymap.update(mymap);
			mymap.draw();
			mymap.drawLight(display);
			//string action = mymenu.hasScrolledOverOption(pos_x,pos_y);
			/*if(action != "null")
			{

			}
			else
			{

			}
			mymenu.draw();*/
			//draw gui
			
			al_flip_display();
		}
}
void gameGUICutscene(ALLEGRO_EVENT ev)
{
	//TODO: Setup Gui for cutscenes
}
void gameGUIShop(ALLEGRO_EVENT ev)
{
	//TODO: Setup GUI shop
}
void gameGUIInvintry(ALLEGRO_EVENT ev)
{
	//TODO: GUI Invintory
}
void gameGUISaveLoad(ALLEGRO_EVENT ev)
{
	//TODO: Setup GUi for saveing and loading
}
void gameGUIWorldMap(ALLEGRO_EVENT ev)
{
	//TODO: Guiworld map menu
}
void initMenus()
{
	
	//mymenu.addButton(20.0f,20.0f,al_load_bitmap("Images\\Menus\\Test\\btnup.png"),al_load_bitmap("Images\\Menus\\Test\\btndown.png"),"bla");
	//mainmenu
	mainmenu = Menu(); //mainmenu
	//load images.
		ALLEGRO_BITMAP* mainmenubg = al_load_bitmap("Images\\Menus\\main\\bg.png");
		ALLEGRO_BITMAP* mainmenutitle = al_load_bitmap("Images\\Menus\\main\\title.png");
		ALLEGRO_BITMAP* mainmenusingle_UP = al_load_bitmap("Images\\Menus\\main\\single_up.png");
		ALLEGRO_BITMAP* mainmenusingle_DOWN = al_load_bitmap("Images\\Menus\\main\\single_down.png");
		ALLEGRO_BITMAP* mainmenumulti = al_load_bitmap("Images\\Menus\\main\\multi_up.png");
		ALLEGRO_BITMAP* mainmenuoptions_UP = al_load_bitmap("Images\\Menus\\main\\options_up.png");
		ALLEGRO_BITMAP* mainmenuoptions_DOWN = al_load_bitmap("Images\\Menus\\main\\options_down.png");
		ALLEGRO_BITMAP* mainmenuexit_UP = al_load_bitmap("Images\\Menus\\main\\exit_up.png");
		ALLEGRO_BITMAP* mainmenuexit_DOWN = al_load_bitmap("Images\\Menus\\main\\exit_down.png");
		ALLEGRO_BITMAP* mainmenucopyright = al_load_bitmap("Images\\Menus\\main\\copywrite.png");
		ALLEGRO_BITMAP* mainmenuversion = al_load_bitmap("Images\\Menus\\main\\version.png");
	//create button pointer functions
		void(*mainmenusingleclick)() = &mainMenuClickSingle;
		void(*mainmenumulticlick)() = &mainMenuClickMulti;
		void(*mainmenuoptionclick)() = &mainMenuClickOption;
		void(*mainmenuexitclick)() = &mainMenuClickExit;
	//add buttons
		mainmenu.addImage(0,0,mainmenubg);
		mainmenu.addImage(112,60,mainmenutitle);
		mainmenu.addButton(266,350,mainmenusingle_UP,mainmenusingle_DOWN,"Single",mainmenusingleclick);
		mainmenu.addImage(266,414,mainmenumulti);//TODO:multiplayer button
		mainmenu.addButton(266,480,mainmenuoptions_UP,mainmenuoptions_DOWN,"Options",mainmenuoptionclick);
		mainmenu.addButton(266,545,mainmenuexit_UP,mainmenuexit_DOWN,"Exit",mainmenuexitclick);
		mainmenu.addImage(0,606,mainmenucopyright);
		mainmenu.addImage(575,606,mainmenuversion);
	menuoptions = Menu(); // options menu
	//TODO: Load option gui elements
	menumulti = Menu();
	//TODO: Load multiplayer gui elements
	menuingame = Menu();
	//TODO: load ingamemenu gui elements
	menucutscene = Menu();
	//TODO: load cutscene gui elements
	menushop = Menu();
	//TODO: load menushot gui elements
	menuinvintory = Menu();
	//TODO: load menuinvintory gui elements
	menusaveload = Menu();
	//TODO: load saveload gui elements
	menuworldmap = Menu();
	//TODO: load menuworldmap gui elements
}