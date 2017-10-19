#pragma once
#include "Entity.h"
#define DEGTORAD 0.0174532925199432957f


class Platform : public Entity {
public:
	b2Vec2 m_from, m_to, m_destination;
	bool goToTo = true;
	float m_speedMultiplier;

	Platform(b2World* world, double width, double height, b2Vec2 from, b2Vec2 to, float speedMultiplier = 5, bool reverse = false) 
		:m_from(from),
		m_to(to),
		m_destination(to),
		m_speedMultiplier(speedMultiplier), 
		Entity(world)
	{		

		b2BodyDef myBodyDef;

		myBodyDef.type = b2_kinematicBody; //this will be a kinematic body
		if (reverse == true)
		{
			myBodyDef.position.Set(to.x, to.y);
			m_destination = from;
		}
		else
		{
			myBodyDef.position.Set(from.x, from.y);
		}

		b2PolygonShape boxShape;
		boxShape.SetAsBox(width, height);
		b2FixtureDef boxFixtureDef;
		boxFixtureDef.shape = &boxShape;
		boxFixtureDef.density = 1;


		m_body = m_world->CreateBody(&myBodyDef);
		m_body->CreateFixture(&boxFixtureDef);

		float horizontalDistance = (m_destination.x - m_body->GetPosition().x)/m_speedMultiplier;
		float verticalDistance = (m_destination.y - m_body->GetPosition().y) / m_speedMultiplier;
		m_body->SetLinearVelocity(b2Vec2(horizontalDistance, verticalDistance));


		//m_body->SetUserData(this);
	}

	void checkMovement();

	


	// Inherited via Entity
	virtual ENTITY_TYPE getEntityType() override;


	// Inherited via Entity
	virtual void update(float deltaTime = 0) override;

};
