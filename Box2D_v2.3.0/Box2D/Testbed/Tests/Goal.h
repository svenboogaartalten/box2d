#pragma once
#include "Entity.h"

class Goal : public Entity {
public:
	bool m_playerTouchedMe = false;


	Goal(b2World* world) :Entity(world)
	{
		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		m_body = m_world->CreateBody(&bodyDef);

		b2PolygonShape polygonShape;
		polygonShape.SetAsBox(1, 1);

		m_body->CreateFixture(&polygonShape, 1);//shape, density

		m_body->SetUserData(this);
	}

	void setReached(bool status)
	{
		m_playerTouchedMe = true;
	}

	bool isReached()
	{
		return m_playerTouchedMe;
	}



	// Inherited via Entity
	virtual ENTITY_TYPE getEntityType() override;


	// Inherited via Entity
	virtual void update(float deltaTime = 0) override;

};
