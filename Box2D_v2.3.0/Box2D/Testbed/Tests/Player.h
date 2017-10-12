#pragma once

class Player {
public:
	b2Body* m_body;
	b2World* m_world;

	Player(b2World* world)
	{
		m_world = world;
		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		m_body = m_world->CreateBody(&bodyDef);

		b2PolygonShape polygonShape;
		polygonShape.SetAsBox(1, 1);
		
		m_body->CreateFixture(&polygonShape, 1);//shape, density

		m_body->SetUserData(this);
	}

	void setPosition(b2Vec2 position)
	{
		m_body->SetTransform(position,1);
	}

	b2Body* getBody()
	{
		return m_body;
	}



	~Player()
	{
		m_body->GetWorld()->DestroyBody(m_body);

	}
};