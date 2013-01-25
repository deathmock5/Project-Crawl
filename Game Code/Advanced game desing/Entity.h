#ifndef _allegro_h_
#define _allegro_h_
#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>
#endif // !_allegro_h_
#ifndef _Entity_h_
#define _Entity_h_

class Entity
{
public:
	Entity(float,float);
	~Entity();
	void draw();
	void travelToPos(float tarx,float tary,float speed);
	void update();
	bool isLiveingCreature();
	bool isAlive();
	void drawLight();
private:
	float posx;
	float posy;
	float speed;
	float velocityx;
	float velocityy;
};
#endif // !_Entity_h_