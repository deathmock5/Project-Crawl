//#include spriting
//entitys
//	player
//  enemy
//  objects
#ifdef DMLOGGGER_EXPORTS
#define DMLOGGGER_API __declspec(dllimport) 
#else
#define DMLOGGGER_API __declspec(dllexport) 
#endif
namespace GameLib
{
	class Entity
	{
	public:
		DMLOGGGER_API Entity();
	};
}