#pragma once
#include <Box2D/Box2D.h>

enum ENTITY_TYPE {GOAL, PLAYER, DEFAULT, PLATFORM};
class Entity {
protected:
	b2Body* m_body;
	b2World* m_world;
public:


	Entity(b2World* world)
	{
		m_world = world;
		
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
