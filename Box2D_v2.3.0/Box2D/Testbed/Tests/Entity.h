#pragma once
#include <Box2D/Box2D.h>
#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f



enum ENTITY_TYPE {
	BOUNDARY = 0x0001,
	PLAYER = 0x0002,
	DEFAULT = 0x0004,
	PLATFORM = 0x0008,
	GOAL = 0x0010,
	SENSOR = 0x0020,
};
class Entity {
protected:
	b2Body* m_body;
	b2World* m_world;
public:


	Entity(b2World* world):m_world(world)
	{
		
	}

	virtual ENTITY_TYPE getEntityType() = 0;
	virtual void update(float deltaTime = 0) = 0;

	void setPosition(b2Vec2 position)
	{
		m_body->SetTransform(position, 1);
	}

	b2Body* getBody()
	{
		return m_body;
	}



	~Entity()
	{
		m_body->GetWorld()->DestroyBody(m_body);

	}
};
