#ifndef _allegro_h_
#define _allegro_h_
#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
#endif // !_allegro_h_

#ifndef _Item_h_
#define _Item_h_
#include <vector>
#include <cstdlib>
#include <sstream>
using namespace std;
class Item
{
public:
	Item();
	Item(string);
	void drawIcon();

private:
	//rednering
	ALLEGRO_BITMAP *itemimage;

	//information
	string name;
	int amount;

	//vector<Efects> 
};
#endif // !_Item_h_