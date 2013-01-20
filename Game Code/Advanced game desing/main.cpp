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

//refrenced classes and namespaces
#include "SystemVars.cpp";

using namespace std;
SystemVars systemvars;
int main(int argc, char **argv)
{
	bool done = false;
	bool redraw = false;
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;

	if(!al_init())
		return -1; //Init
	int test = systemvars.SCREEN_WIDTH;
	display = al_create_display(systemvars.SCREEN_WIDTH, systemvars.SCREEN_HEIGHT); //make display

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
	timer = al_create_timer(1.0 / systemvars.FPS);

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
			}
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
			//draw walls
			//draw doors
			//make inlay
			//draw floor
			//draw gui
			//draw entitys
			//draw player
			//posibility of lighting
			al_flip_display();
		}
	}
	return 0;
}