#ifndef _allegro_h_
#define _allegro_h_
#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>
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
private:
	string name;
	int amount;
	ALLEGRO_BITMAP *itemimage;

};
#endif // !_Item_h_