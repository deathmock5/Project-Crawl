#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>

class Tile
{
public:
	Tile(int x,int y,ALLEGRO_BITMAP img);
	void Draw();
	void drawLight();
	bool isWall();
private:
	int posx;
	int posy;
	bool wall;
	ALLEGRO_BITMAP *myimg;
};