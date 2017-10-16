#pragma once
#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f

#include <string>
#include "Player.h"
#include "Goal.h"
#include "Platform.h"
#include <vector>
#include "../Framework/Test.h"

#ifndef CUSTOMCAR
#define CUSTOMCAR

#include "MyContactListener.h"

class CustomCar : public Test
{
public:
	
	std::vector<std::shared_ptr<Platform>> m_platforms;
	std::vector<std::shared_ptr<Entity>> m_entities;
	std::shared_ptr<Player> m_player;
	std::unique_ptr<Goal> m_goal;
	b2Body* player;
	bool isFinished = false;
	float lastStep;
	const char * finished;
	MyContactListener myContactListenerInstance;


	CustomCar()	
	{
		

		
		m_player = std::make_shared<Player>(m_world);
		myContactListenerInstance.setPlayer(m_player);
		m_goal = std::make_unique<Goal>(m_world);
		m_player->setPosition(b2Vec2(20, 20));
		m_player->getBody()->SetTransform(b2Vec2(10, 20), 1);
		m_player->getBody()->SetLinearVelocity(b2Vec2(-5, 5)); //moving up and left 5 units per second
		m_player->getBody()->SetAngularVelocity(360 * DEGTORAD); //90 degrees per second clockwise

		m_goal->setPosition(b2Vec2(22, -2));


		b2BodyDef myBodyDef;
		lastStep = 0;
		finished = "Go get the orange box on your right side to finish the quest.";

		//SHAPES
		b2PolygonShape boxShape;
		boxShape.SetAsBox(1, 1);
		b2FixtureDef boxFixtureDef;
		boxFixtureDef.shape = &boxShape;
		boxFixtureDef.density = 1;



		//horizontal
		b2PolygonShape platformShape;
		platformShape.SetAsBox(3, 1);
		b2FixtureDef platformFixtureDef;
		platformFixtureDef.shape = &platformShape;
		platformFixtureDef.density = 1;

		//vertical
		b2PolygonShape platformShape2;
		platformShape2.SetAsBox(1, 3);
		b2FixtureDef platformFixtureDef2;
		platformFixtureDef2.shape = &platformShape2;
		platformFixtureDef2.density = 1;

		b2CircleShape circleShape;
		circleShape.m_p.Set(0, 0); //position, relative to body position
		circleShape.m_radius = 1; //radius
		b2FixtureDef myCircleFixtureDef;

		myCircleFixtureDef.shape = &circleShape; //this is a pointer to the shape above
		
		
		b2PolygonShape polygonShape;
		//----


		//CREATE BODIES
		
		

		//Boxes
		myBodyDef.type = b2_staticBody; //this will be  static bodies

		myBodyDef.position.Set(0, 10); 
		b2Body* staticBody = m_world->CreateBody(&myBodyDef); //add body to world
		staticBody->CreateFixture(&boxFixtureDef); //add fixture to body

		myBodyDef.position.Set(5,5); 
		b2Body* staticBody2 = m_world->CreateBody(&myBodyDef); //add body to world
		staticBody2->CreateFixture(&boxFixtureDef); //add fixture to body

		myBodyDef.position.Set(10, 0);	
		b2Body* staticBody3 = m_world->CreateBody(&myBodyDef); //add body to world
		staticBody3->CreateFixture(&boxFixtureDef); //add fixture to body

		myBodyDef.position.Set(19, 0);
		b2Body* leftOfGoal = m_world->CreateBody(&myBodyDef); //add body to world
		leftOfGoal->CreateFixture(&platformFixtureDef2); //add fixture to body

		

		myBodyDef.position.Set(27, -1);
		b2Body* rightOfGoal = m_world->CreateBody(&myBodyDef); //add body to world
		rightOfGoal->CreateFixture(&platformFixtureDef2); //add fixture to body


		

		
		//walls
		myBodyDef.position.Set(0, 0); //middle, bottom
		b2EdgeShape edgeShape;
		

		
		
		edgeShape.Set(b2Vec2(-15, 0), b2Vec2(30, -4));
		b2Body* floor = m_world->CreateBody(&myBodyDef);
		b2FixtureDef myFixtureDef;
		myFixtureDef.friction = 0;
		myFixtureDef.shape = &edgeShape;
		floor->CreateFixture(&myFixtureDef); //add a fixture to the body
		myFixtureDef.friction = 1;
		
		edgeShape.Set(b2Vec2(12, 15), b2Vec2(12, -4));
		b2FixtureDef myFixtureDef2; 
		myFixtureDef2.shape = &edgeShape;
		floor->CreateFixture(&myFixtureDef2); //add a fixture to the body
		
		
		edgeShape.Set(b2Vec2(-50, -10), b2Vec2(50, -10));
		b2FixtureDef absoluteFloor;
		absoluteFloor.shape = &edgeShape;
		floor->CreateFixture(&absoluteFloor); //add a fixture to the body

		edgeShape.Set(b2Vec2(-50, 40), b2Vec2(50, 40));
		b2FixtureDef roofFixture;
		roofFixture.shape = &edgeShape;
		floor->CreateFixture(&roofFixture); //add a fixture to the body

		edgeShape.Set(b2Vec2(-50, 40), b2Vec2(-50, -40));
		b2FixtureDef sideLeft;
		sideLeft.shape = &edgeShape;
		floor->CreateFixture(&sideLeft); //add a fixture to the body

		edgeShape.Set(b2Vec2(50, 40), b2Vec2(50, -40));
		b2FixtureDef sideRight;
		sideRight.shape = &edgeShape;
		floor->CreateFixture(&sideRight); //add a fixture to the body

		//kinematics

		auto platformVertical = std::make_shared<Platform>(m_world, 2, 1, b2Vec2(18, 10), b2Vec2(18, 0),2.92);
		m_platforms.push_back(platformVertical);
		m_entities.push_back(platformVertical);

		auto platformHorizontal = std::make_shared<Platform>(m_world, 2, 1, b2Vec2(20, 5), b2Vec2(30, 5),1);
		m_platforms.push_back(platformHorizontal);
		m_entities.push_back(platformHorizontal);


		myBodyDef.type = b2_kinematicBody; //this will be a kinematic body
		myBodyDef.position.Set(-6, 8); 
		b2Body* kinematicBody = m_world->CreateBody(&myBodyDef);
		kinematicBody->CreateFixture(&boxFixtureDef);
		kinematicBody->SetLinearVelocity(b2Vec2(1, 1)); 
		kinematicBody->SetAngularVelocity(360 * DEGTORAD); 
	

		myBodyDef.position.Set(13.2, -30); 
		b2Body* kinematicBody2 = m_world->CreateBody(&myBodyDef); //add body to world
		kinematicBody2->CreateFixture(&platformFixtureDef); //add fixture to body
		kinematicBody2->SetLinearVelocity(b2Vec2(0, 3)); 
		kinematicBody2->SetAngularVelocity(0); 




		myBodyDef.position.Set(20, 30); 
		b2Body* kinematicBody3 = m_world->CreateBody(&myBodyDef); //add body to world
		kinematicBody3->CreateFixture(&platformFixtureDef); //add fixture to body
		kinematicBody3->CreateFixture(&platformFixtureDef2); //add fixture to body
		kinematicBody3->SetAngularVelocity(360 * DEGTORAD); 




		m_world->SetContactListener(&myContactListenerInstance);




		
	}
	~CustomCar()
	{

	}

	void Keyboard(unsigned char key)
	{
		float impulse = m_player->getBody()->GetMass() * 10;
		switch (key)
		{
		case 'w':
			if (lastStep  <= 0)
			{
				m_player->getBody()->ApplyLinearImpulse(b2Vec2(0, impulse), m_player->getBody()->GetWorldCenter(), true);
				lastStep = 0.75;
			}
			break;
		case 'a':
			m_player->getBody()->ApplyLinearImpulse(b2Vec2(-impulse*0.3, 0), m_player->getBody()->GetWorldCenter(), true);
			break;
		case 's':
			m_player->getBody()->ApplyLinearImpulse(b2Vec2(0, -impulse), m_player->getBody()->GetWorldCenter(), true);
			break;
		case 'd':
			m_player->getBody()->ApplyLinearImpulse(b2Vec2(impulse*0.3, 0), m_player->getBody()->GetWorldCenter(), true);
			break;
		
		}
	}

	void Step(Settings* settings)
	{
		//run the default physics and rendering
		Test::Step(settings);
		float32 timeStep = settings->hz > 0.0f ? 1.0f / settings->hz : float32(0.0f);
		if (lastStep > 0)
		{
			lastStep -= timeStep;
		}
		for (auto const& var : m_entities)
		{
			var->update(timeStep);
		}
		
		//show some text in the main screen
		m_debugDraw.DrawString(5, m_textLine, "Test by Sven van den Boogaart");
		m_textLine += 15;
		std::string test = "time left :" + std::to_string(lastStep);
		const char * c = test.c_str();
		m_debugDraw.DrawString(5, m_textLine, c);
		m_textLine += 15;
		m_debugDraw.DrawString(5, m_textLine, finished);
		m_textLine += 15;
		if (!isFinished && m_player->hasReachedGoal())
		{
			finished = "You completed the quest.";
			isFinished = true;
		}

		settings->viewCenter.x = m_player->getBody()->GetPosition().x;
		settings->viewCenter.y = m_player->getBody()->GetPosition().y;




	}

	static Test* Create()
	{
		return new CustomCar;
	}
};




#endif
