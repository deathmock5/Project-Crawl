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
using namespace std;

//refrenced classes and namespaces
#include "SystemVars.h"
#include "Map.h"
#include "Player.h"
enum keys{BUTTONCLICKED,STATECHANGED};
bool buttonPressed[2][4] = {{false,false,false,false},
							{false,false,false,false}};
Map mymap;
bool anyButtonChangedStatus();
bool anyButtonIsPressed();
bool noOtherButtonsArePressed(int);
void buttonHelper();
int main(int argc, char **argv)
{
	bool done = false;
	bool redraw = false;
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;

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

	mymap = Map("Place",1);
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
		else if(ev.type = ALLEGRO_EVENT_TIMER)
		{
			redraw = true;
		}

		if(redraw == true && al_event_queue_is_empty(event_queue))
		{
			redraw = false;
			al_clear_to_color(al_map_rgb(0,0,0));
			
			
			mymap.update();
			mymap.draw();
			mymap.drawLight(display);
			//draw gui
			//draw entitys
			//draw player
			//posibility of lighting
			
			al_flip_display();
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