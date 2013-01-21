class Entity
{
public:
	Entity(float,float);
	~Entity();
	void Draw();
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
Entity::Entity(float spawnx,float spawny)
{
}
Entity::~Entity()
{
}
void Entity::Draw(){}
void Entity::travelToPos(float tarx,float tary,float speed){}
void Entity::update(){}
bool Entity::isLiveingCreature(){return true;}
bool Entity::isAlive(){return true;}
void Entity::drawLight(){}