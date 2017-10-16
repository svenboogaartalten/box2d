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

		float radius = 4;
		b2Vec2 vertices[8];
		vertices[0].Set(0, 0);
		for (int i = 0; i < 7; i++) {
			float angle = i / 6.0 * 90 * DEGTORAD;
			vertices[i + 1].Set(radius * cosf(angle), radius * sinf(angle));
		}
		b2FixtureDef myFixtureDef;
		polygonShape.Set(vertices, 8);
		myFixtureDef.shape = &polygonShape;
		myFixtureDef.isSensor = true;
		myFixtureDef.filter.categoryBits = ENTITY_TYPE::SENSOR;
		myFixtureDef.filter.maskBits = ENTITY_TYPE::PLAYER;
		myFixtureDef.density = 0;
		m_body->CreateFixture(&myFixtureDef);
		

		//make the tower rotate at 45 degrees per second
		m_body->SetAngularVelocity(45 * DEGTORAD);
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
