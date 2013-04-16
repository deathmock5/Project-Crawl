
//system imports
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <Windows.h>
#include <memory>
using namespace std;


//refrenced classes and namespaces
#include "SystemVars.cpp"
#include "Player.h"
#include "Map.h"
#include "Menu.h"
//#include "Tile.h"
//#include "Entity.h"
//#include "Dungion.h"
//#include "Player.h"
//#include "Item.h"

bool anyButtonChangedStatus();
bool anyButtonIsPressed();
bool noOtherButtonsArePressed(int);
void buttonHelper(int doButtonAction);
int isAnyButtonHeldDown(int,bool);
std::vector<int> buttonsHeldDown;
DIRECTION lastdir;

//TODO: add in music fadeins



enum gameGuiState{MAIN,OPTION,MULTIPLAYER,INGAME,SHOP,INVINTORY,SAVELOAD,WORLDMAP};

Menu mainmenu;
void mainMenuClickSingle();
void mainMenuClickMulti();
void mainMenuClickOption();
void mainMenuClickExit();
void gameGUIMain(ALLEGRO_EVENT);

Menu menuoptions;
void optionsMenuClickResolution();
void optionsMenuClickBrightness();
void optionsMenuClickConfig();
void optionsMenuClickDificulty();
void optionsMenuClickBack();
void gameGUIOption(ALLEGRO_EVENT);

Menu menuoverworld;
void overworldMenuClickDung1();
void overworldMenuClickDung2();
void overworldMenuClickDung3();
void gameGUIOverworld(ALLEGRO_EVENT);

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
void toggleInvintory();

Menu menusaveload = Menu();
void gameGUISaveLoad(ALLEGRO_EVENT);

void initMenus();
void changeGameState(gameGuiState);

//game variables
Dungion mydung;
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
	mydung = Dungion();
	if(al_init())logHelperMessage(OK,1,"Initilised Allegro 5.0.8");
	else{ logHelperMessage(SEVERE,1,"Failed to initilise Allegro 5.0.8"); return -1;}
	
	display = al_create_display(SystemVars::SCREEN_WIDTH, SystemVars::SCREEN_HEIGHT); //make display

	if(display)
		logHelperMessage(OK,1,"Created Display");//return -1;
	
	//init
	if(al_init_primitives_addon())
		logHelperMessage(OK,1,"Initilized primitives addon");   //init primitives
	if(al_install_keyboard())
		logHelperMessage(OK,1,"Installed Keybaord"); //init keyboard
	if(al_install_mouse())
		logHelperMessage(OK,1,"Installed mouse"); //init mouse
	if(al_install_audio())
		logHelperMessage(OK,1,"Installed audio"); //init audio
	al_init_font_addon();
		logHelperMessage(OK,1,"Initilized font addon"); //init font
	if(al_init_ttf_addon())
		logHelperMessage(OK,1,"Initilized ttf addon"); //init ttf
	if(al_init_acodec_addon())
		logHelperMessage(OK,1,"Initilized acodec addon"); //init codec
	if(al_init_image_addon())
		logHelperMessage(OK,1,"Initilized images addon"); 
	timer = al_create_timer(1.0 / SystemVars::FPS);

	al_reserve_samples(100);
	//bgs = al_load_sample("snd\\01.wav");
	//al_play_sample(bgs,0.5f,0,1,ALLEGRO_PLAYMODE_LOOP,NULL);
	
	al_clear_to_color(al_map_rgb(0,0,0));
	//TODO: splash
	al_flip_display();

	initMenus();
	curentstate = MAIN;
	mainmenu.playBgs();


	al_set_blender(ALLEGRO_ADD, ALLEGRO_ONE, ALLEGRO_INVERSE_ALPHA);
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_clear_to_color(al_map_rgb(0,0,0));
	//TODO: splash
	al_flip_display();

	al_start_timer(timer);
	while(!done)
	{
		//updateThreadQue();
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
			gameGUIOverworld(ev);
			break;
		default:
			logHelperMessage(SEVERE,1,"Unrecignised gamestate:");
			return 1;
			break;
		}
	}
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);
	return 0;
}


void buttonHelper(int doButtonAction)
{
	//take the key and send to a function to return an actionenum
	if(curentstate == INGAME)
	{
		switch (doButtonAction)
		{
		case ALLEGRO_KEY_W:
			mydung.players[0].processInput(WALK,BACK);
			lastdir = BACK;
			break;
		case ALLEGRO_KEY_A:
			mydung.players[0].processInput(WALK,LEFT);
			lastdir = LEFT;
			break;
		case ALLEGRO_KEY_S:
			mydung.players[0].processInput(WALK,FORWARD);
			lastdir = FORWARD;
			break;
		case ALLEGRO_KEY_D:
			mydung.players[0].processInput(WALK,RIGHT);
			lastdir = RIGHT;
			break;
		case ALLEGRO_KEY_E:
			toggleInvintory();
			break;
		default:
			mydung.players[0].processInput(STAND,lastdir);
			break;
		} 
	}
	else
	{
		if(doButtonAction == ALLEGRO_KEY_E)
		{
			toggleInvintory();
		}
	}
	if(doButtonAction == ALLEGRO_KEY_ESCAPE)
	{
		done = true;
	}
	
}
//main gui
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
	//logHelperMessage(INFO,1,"Gamestate set to single");
	curentstate = WORLDMAP;
}
void mainMenuClickMulti()
{
	//TODO: mainMenuClickMulti()
}
void mainMenuClickOption()
{
	//TODO: mainMenuClickOption()
	curentstate = OPTION;
}
void mainMenuClickExit()
{
	//TODO: mainMenuClickExit()
}
//options
void gameGUIOption(ALLEGRO_EVENT ev)
{
	//TODO: Setup Option menu
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
				menuoptions.mouseLocation(ev.mouse.x,ev.mouse.y);
			}
		else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			menuoptions.acitonClick();
		}
		else if(ev.type = ALLEGRO_EVENT_TIMER)
		{
			redraw = true;
		}
		
		if(redraw == true && al_event_queue_is_empty(event_queue))
		{
			redraw = false;
			al_clear_to_color(al_map_rgb(0,0,0));

			menuoptions.draw();
			al_flip_display();
		}
}
void optionsMenuClickResolution()
{
	//TODO: optionsMenuClickResolution()
}
void optionsMenuClickBrightness()
{
	//TODO: optionsMenuClickBrightness()
}
void optionsMenuClickConfig()
{
	//TODO: optionsMenuClickConfig()
}
void optionsMenuClickDificulty()
{
	//TODO: optionsMenuClickDificulty()
}
void optionsMenuClickBack()
{
	//TODO: optionsMenuClickBack()
	curentstate = MAIN;
}
//Overworld
void gameGUIOverworld(ALLEGRO_EVENT ev)
{
	//TODO: gameGUIOverworld();
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
				menuoverworld.mouseLocation(ev.mouse.x,ev.mouse.y);
			}
		else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			menuoverworld.acitonClick();
		}
		else if(ev.type = ALLEGRO_EVENT_TIMER)
		{
			redraw = true;
		}
		
		if(redraw == true && al_event_queue_is_empty(event_queue))
		{
			redraw = false;
			al_clear_to_color(al_map_rgb(0,0,0));

			menuoverworld.draw();
			al_flip_display();
		}
}
void overworldMenuClickDung1()
{
	//TODO: overworldMenuClickDung1()
	//mymap = Map("Lv1",1);
	mydung = Dungion("Lv1");
	curentstate = INGAME;
}
void overworldMenuClickDung2()
{
	//TODO: overworldMenuClickDung2()
}
void overworldMenuClickDung3()
{
	//TODO: overworldMenuClickDung3()
}
//multiplayer
void gameGUIMultiplayer(ALLEGRO_EVENT ev)
{
	//TODO: Setup multiplayer menu
}
//ingame
void gameGUIIngame(ALLEGRO_EVENT ev)
{
	if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			int processButton = isAnyButtonHeldDown(ev.keyboard.keycode,true);
			buttonHelper(processButton);
		}
		else if(ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			int processButton = isAnyButtonHeldDown(ev.keyboard.keycode,false);
			buttonHelper(processButton);
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
			mydung.players[0].processInput(ATACK,mydung.players[0].getFaceingDir(pos_x,pos_y));
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
			mydung.Update();
			mydung.Draw();
			//mydung.reftoCurrentMap()->drawLight(display);
			Player* curentplayer = mydung.refToCurrentPlayer();
			menuingame.updateGaugeValue("PHP",mydung.players[0].getHealth());
			menuingame.updateGaugeValue("PMP",mydung.players[0].getMana());
			menuingame.updateGaugeValue("PLV",mydung.players[0].getLives());
			menuingame.draw();
			al_flip_display();
		}
}
//cutscene
void gameGUICutscene(ALLEGRO_EVENT ev)
{
	//TODO: Setup Gui for cutscenes
}
//shop
void gameGUIShop(ALLEGRO_EVENT ev)
{
	//TODO: Setup GUI shop
}
//invintory
void gameGUIInvintry(ALLEGRO_EVENT ev)
{
	if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			int processButton = isAnyButtonHeldDown(ev.keyboard.keycode,true);
			buttonHelper(processButton);
		}
		else if(ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			int processButton = isAnyButtonHeldDown(ev.keyboard.keycode,false);
			buttonHelper(processButton);
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
			mydung.players[0].processInput(ATACK,mydung.players[0].getFaceingDir(pos_x,pos_y));
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
			//Map* curmap = mydung.reftoCurrentMap();

			mydung.Draw();
			//mydung.reftoCurrentMap()->drawLight(display);
			Player* curentplayer = mydung.refToCurrentPlayer();
			menuingame.updateGaugeValue("PHP",curentplayer->getHealth());
			menuingame.updateGaugeValue("PMP",curentplayer->getMana());
			menuingame.updateGaugeValue("PLV",curentplayer->getLives());
			menuingame.draw();
			menuinvintory.draw();
			al_flip_display();
		}
}
//saveload
void gameGUISaveLoad(ALLEGRO_EVENT ev)
{
	//TODO: Setup GUi for saveing and loading
}

//Other functions
void initMenus()
{
	
	//mymenu.addButton(20.0f,20.0f,al_load_bitmap("Images\\Menus\\Test\\btnup.png"),al_load_bitmap("Images\\Menus\\Test\\btndown.png"),"bla");
	//mainmenu
		mainmenu = Menu(); //mainmenu
		logHelperMessage(INFO,1,"Creating mainmenu");
		//load images.
			ALLEGRO_BITMAP* mainmenubg = load_image("Images\\Menus\\main\\bg.png");
			ALLEGRO_BITMAP* mainmenutitle = load_image("Images\\Menus\\main\\title.png");
			ALLEGRO_BITMAP* mainmenusingle_UP = load_image("Images\\Menus\\main\\single_up.png");
			ALLEGRO_BITMAP* mainmenusingle_DOWN = load_image("Images\\Menus\\main\\single_down.png");
			ALLEGRO_BITMAP* mainmenumulti = load_image("Images\\Menus\\main\\multi_up.png");
			ALLEGRO_BITMAP* mainmenuoptions_UP = load_image("Images\\Menus\\main\\options_up.png");
			ALLEGRO_BITMAP* mainmenuoptions_DOWN = load_image("Images\\Menus\\main\\options_down.png");
			ALLEGRO_BITMAP* mainmenuexit_UP = load_image("Images\\Menus\\main\\exit_up.png");
			ALLEGRO_BITMAP* mainmenuexit_DOWN = load_image("Images\\Menus\\main\\exit_down.png");
			ALLEGRO_BITMAP* mainmenucopyright = load_image("Images\\Menus\\main\\copywrite.png");
			ALLEGRO_BITMAP* mainmenuversion = load_image("Images\\Menus\\main\\version.png");
			ALLEGRO_SAMPLE* mainmenubgs = load_sound("Sound\\BGS\\Scene music 2.wav");
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
			mainmenu.setBgs(mainmenubgs);
	//optionsmenu
		menuoptions = Menu(); // options menu
		logHelperMessage(INFO,1,"Creating optionmenu");
		//images
			ALLEGRO_BITMAP* optionmenubg = load_image("Images\\Menus\\option\\bg.png");
			ALLEGRO_BITMAP* optionmenutitle = load_image("Images\\Menus\\option\\options_title.png");
			ALLEGRO_BITMAP* optionmenuresolution_UP = load_image("Images\\Menus\\option\\resolution_up.png");
			ALLEGRO_BITMAP* optionmenuresolution_DOWN = load_image("Images\\Menus\\option\\resolution_down.png");
			ALLEGRO_BITMAP* optionmenubrightness_UP = load_image("Images\\Menus\\option\\brightness_up.png");
			ALLEGRO_BITMAP* optionmenubrightness_DOWN = load_image("Images\\Menus\\option\\brightness_down.png");
			ALLEGRO_BITMAP* optionmenuconfig_UP = load_image("Images\\Menus\\option\\configuration_up.png");
			ALLEGRO_BITMAP* optionmenuconfig_DOWN = load_image("Images\\Menus\\option\\configuration_down.png");
			ALLEGRO_BITMAP* optionmenudifficulty_UP = load_image("Images\\Menus\\option\\dificulty_up.png");
			ALLEGRO_BITMAP* optionmenudifficulty_DOWN = load_image("Images\\Menus\\option\\dificulty_down.png");
			ALLEGRO_BITMAP* optionmenuback_UP = load_image("Images\\Menus\\option\\back_up.png");
			ALLEGRO_BITMAP* optionmenuback_DOWN = load_image("Images\\Menus\\option\\back_down.png");
		//function pointers
			void(*optionmenuresolutionclick)() = &optionsMenuClickResolution;
			void(*optionmenubrightnessclick)() = &optionsMenuClickBrightness;
			void(*optionmenuconfigclick)() = &optionsMenuClickConfig;
			void(*optionmenudificultyclick)() = &optionsMenuClickDificulty;
			void(*optionmenubackclick)() = &optionsMenuClickBack;
		//add information to menu
			menuoptions.addImage(0,0,optionmenubg);
			menuoptions.addImage(241,21,optionmenutitle);
			menuoptions.addButton(125,156,optionmenuresolution_UP,optionmenuresolution_DOWN,"resolution",optionmenuresolutionclick);
			menuoptions.addButton(125,254,optionmenubrightness_UP,optionmenubrightness_DOWN,"brightness",optionmenubrightnessclick);
			menuoptions.addButton(125,351,optionmenuconfig_UP,optionmenuconfig_DOWN,"config",optionmenuconfigclick);
			menuoptions.addButton(125,446,optionmenudifficulty_UP,optionmenudifficulty_DOWN,"difficulty",optionmenudificultyclick);
			menuoptions.addButton(125,546,optionmenuback_UP,optionmenuback_DOWN,"back",optionmenubackclick);
	//menuoverworld
		menuoverworld = Menu();
		logHelperMessage(INFO,1,"Creating overworldmenu");
		//load images
			ALLEGRO_BITMAP* overworldmenubg = load_image("Images\\Menus\\overworld\\bg.jpg");
			ALLEGRO_BITMAP* overworlddung_UP = load_image("Images\\Menus\\overworld\\dng.png");
			ALLEGRO_BITMAP* overworlddung1_DOWN = load_image("Images\\Menus\\overworld\\dng1.png");
			ALLEGRO_BITMAP* overworlddung2_DOWN = load_image("Images\\Menus\\overworld\\dng2.png");
			ALLEGRO_BITMAP* overworlddung3_DOWN = load_image("Images\\Menus\\overworld\\dng3.png");
		//asign function pointers
			void(*overworldmenuclickdung1)() = &overworldMenuClickDung1;
			void(*overworldmenuclickdung2)() = &overworldMenuClickDung2;
			void(*overworldmenuclickdung3)() = &overworldMenuClickDung3;
		//add buttons
			menuoverworld.addImage(0,0,overworldmenubg);
			menuoverworld.addButton(107,465,overworlddung_UP,overworlddung1_DOWN,"dung1",overworldMenuClickDung1);
			menuoverworld.addButton(714,416,overworlddung_UP,overworlddung2_DOWN,"dung2",overworldMenuClickDung2);
			menuoverworld.addButton(574,323,overworlddung_UP,overworlddung3_DOWN,"dung3",overworldMenuClickDung3);
	//menumulti
		menumulti = Menu();
		//TODO: Load multiplayer gui elements
	//menuingame
		menuingame = Menu();
		ALLEGRO_BITMAP* menuingamephpimg = load_image("Images\\Menus\\ingame\\health.png");
		ALLEGRO_BITMAP* menuingamepmpimg = load_image("Images\\Menus\\ingame\\mana.png");
		ALLEGRO_BITMAP* menuingameplvimg = load_image("Images\\Menus\\ingame\\life.png");
		Bounds menuingamephpbounds = Bounds(608,0,192,32);
		Bounds menuingamepmpbounds = Bounds(416,0,192,32);
		Bounds menuingameplvbounds = Bounds(0,0,192,32);
		menuingame.addGauge(menuingamephpimg,menuingamephpbounds,GAUGE_LAYER,10,"PHP");
		menuingame.addGauge(menuingamepmpimg,menuingamepmpbounds,GAUGE_LAYER,10,"PMP");
		menuingame.addGauge(menuingameplvimg,menuingameplvbounds,GAUGE_LAYER,10,"PLV");
		//TODO: load ingamemenu gui elements
	//menucutscene
		menucutscene = Menu();
		//TODO: load cutscene gui elements
	//menu shop
		menushop = Menu();
		//TODO: load menushot gui elements
	//menu invintory
		menuinvintory = Menu();
		ALLEGRO_BITMAP* menuinvintoybg = load_image("Images\\Menus\\invintory\\bg.png");
		Bounds menuinvintorybgbounds = Bounds(64,122,672,418);
		Bounds menuinvintorymoneybounds = Bounds(560,145,0,0);
		menuinvintory.addImage(menuinvintorybgbounds.getX(),menuinvintorybgbounds.getY(),menuinvintoybg);
		menuinvintory.addNumber(menuinvintorymoneybounds,"INVMONEY",0);
		//TODO: load menuinvintory gui elements
	//menusaveload
		menusaveload = Menu();
		//TODO: load saveload gui elements
}
void changeGameState(gameGuiState newstate)
{
	//music fadeout
	curentstate = newstate;
}
int isAnyButtonHeldDown(int key,bool down)
{
	if(down)
	{
		//a button has been held down
		buttonsHeldDown.push_back(key);//order of buttonpresses
	}
	else
	{
		//a button has been let up
		for(int i = 0; i < (int)buttonsHeldDown.size();i++)
		{
			if(key == buttonsHeldDown[i])
			{
				buttonsHeldDown.erase(buttonsHeldDown.begin() + i);
			}
		}
	}
	if(buttonsHeldDown.size() == 0)
	{
		return 0;
	}
	else
	{
		return buttonsHeldDown[buttonsHeldDown.size()-1];
	}
}
void toggleInvintory()
{
	if(curentstate == INGAME)
	{
		curentstate = INVINTORY;
	}
	else
	{
		curentstate = INGAME;
	}
}