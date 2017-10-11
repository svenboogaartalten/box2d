#pragma once
#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f
#ifndef CUSTOMCAR
#define CUSTOMCAR
#include <string>
class CustomCar : public Test
{
public:
	b2Body* player;
	float lastStep;
	const char * finished;
	CustomCar()
	{


		b2BodyDef myBodyDef;
		lastStep = 0;
		finished = "Go the the spot on the right to finish the game";

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
		myBodyDef.type = b2_dynamicBody; //this will be a dynamic body
		myBodyDef.position.Set(0, 20); //set the starting position
		myBodyDef.angle = 0; //set the starting angle
		player = m_world->CreateBody(&myBodyDef);
		player->SetTransform(b2Vec2(10, 20), 1);
		player->SetLinearVelocity(b2Vec2(-5, 5)); //moving up and left 5 units per second
		player->SetAngularVelocity(360 * DEGTORAD); //90 degrees per second clockwise
		
		player->CreateFixture(&boxFixtureDef);
		

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

		myBodyDef.position.Set(22, -3); 
		b2Body* endgoal = m_world->CreateBody(&myBodyDef); //add body to world
		endgoal->CreateFixture(&boxFixtureDef); //add fixture to body

		myBodyDef.position.Set(25, 0);
		b2Body* rightOfGoal = m_world->CreateBody(&myBodyDef); //add body to world
		rightOfGoal->CreateFixture(&platformFixtureDef2); //add fixture to body


		

		
		//floor
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
		myBodyDef.type = b2_kinematicBody; //this will be a kinematic body
		myBodyDef.position.Set(-6, 8); // start from left side, slightly above the static body
		b2Body* kinematicBody = m_world->CreateBody(&myBodyDef); //add body to world
		kinematicBody->CreateFixture(&boxFixtureDef); //add fixture to body



		kinematicBody->SetLinearVelocity(b2Vec2(1, 1)); //move right 1 unit per second
		kinematicBody->SetAngularVelocity(360 * DEGTORAD); //1 turn per second counter-clockwise
	

		myBodyDef.position.Set(13.2, -30); 
		b2Body* kinematicBody2 = m_world->CreateBody(&myBodyDef); //add body to world
		kinematicBody2->CreateFixture(&platformFixtureDef); //add fixture to body
		kinematicBody2->SetLinearVelocity(b2Vec2(0, 3)); //move right 1 unit per second
		kinematicBody2->SetAngularVelocity(0); //1 turn per second counter-clockwise




		myBodyDef.position.Set(20, 30); 
		b2Body* kinematicBody3 = m_world->CreateBody(&myBodyDef); //add body to world
		kinematicBody3->CreateFixture(&platformFixtureDef); //add fixture to body
		kinematicBody3->CreateFixture(&platformFixtureDef2); //add fixture to body
		//kinematicBody3->SetLinearVelocity(b2Vec2(1, 1)); //move right 1 unit per second
		kinematicBody3->SetAngularVelocity(360 * DEGTORAD); //1 turn per second counter-clockwise



		




		
	}
	~CustomCar()
	{

	}

	void Keyboard(unsigned char key)
	{
		float impulse = player->GetMass() * 10;
		switch (key)
		{
		case 'w':
			if (lastStep  <= 0)
			{
				player->ApplyLinearImpulse(b2Vec2(0, impulse), player->GetWorldCenter(), true);
				lastStep = 0.75;
			}
			break;
		case 'a':
			player->ApplyLinearImpulse(b2Vec2(-impulse*0.3, 0), player->GetWorldCenter(), true);
			break;
		case 's':
			player->ApplyLinearImpulse(b2Vec2(0, -impulse), player->GetWorldCenter(), true);
			break;
		case 'd':
			player->ApplyLinearImpulse(b2Vec2(impulse*0.3, 0), player->GetWorldCenter(), true);
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
		
		//show some text in the main screen
		m_debugDraw.DrawString(5, m_textLine, "Test by Sven van den Boogaart");
		m_textLine += 15;
		std::string test = "time left :" + std::to_string(lastStep);
		const char * c = test.c_str();
		m_debugDraw.DrawString(5, m_textLine, c);
		m_textLine += 15;
		m_debugDraw.DrawString(5, m_textLine, finished);

		settings->viewCenter.x = player->GetPosition().x;
		settings->viewCenter.y = player->GetPosition().y;
	}

	static Test* Create()
	{
		return new CustomCar;
	}
};


#endif
