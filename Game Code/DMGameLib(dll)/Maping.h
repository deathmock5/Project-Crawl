
namespace GameLib
{
	class Tile
	{
		Tile();

		void Draw();
	};
	class Map
	{
	public:
		Map();
		Map(std::string,std::string,int);
		Map(ALLEGRO_BITMAP*,ALLEGRO_BITMAP*,string,string,int);
		void draw();
		void drawLight(ALLEGRO_DISPLAY*);
		void moveMapToPos(float posx,float posy,float speed);
		void update(class Dungion&);
		bool isOnScreen();
		void show();
		void hide();
		void addDoor(DIRECTION dir,int tomapid,bool needskey);
		bool doorUnlocked();
		void setDoorLockStatus(bool);
		void spawnEnttityInMap(class Entity);
		void spawnEnttityInMap(class Entity,bool);
		void bakeTilemap();
	private:

	};
}
//tile
//map