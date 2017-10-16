#pragma once
#include "Entity.h"

class Player : public Entity {
public:

	bool m_goalReached = false;
	bool hasReachedGoal() {
		return m_goalReached;
	}

	Player(b2World* world):Entity(world)
	{
		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		m_body = m_world->CreateBody(&bodyDef);

		b2PolygonShape polygonShape;
		polygonShape.SetAsBox(1, 1);

		b2FixtureDef myFixtureDef;
		myFixtureDef.shape = &polygonShape;		
		myFixtureDef.filter.categoryBits = ENTITY_TYPE::PLAYER;
		myFixtureDef.shape = &polygonShape;
		myFixtureDef.density = 1;

		m_body->CreateFixture(&myFixtureDef);//shape, density

		m_body->SetUserData(this);
	}

	void setReachedGoal()
	{
		m_goalReached = true;
	}


	void startContact(b2Fixture* contactWith)
	{
		
	}


	// Inherited via Entity
	virtual ENTITY_TYPE getEntityType() override;


	// Inherited via Entity
	virtual void update(float deltaTime = 0) override;

};