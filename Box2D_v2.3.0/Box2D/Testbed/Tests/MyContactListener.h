#pragma once
#include "Entity.h"
#include "Player.h"

class MyContactListener : public b2ContactListener
{
public:
	std::shared_ptr<Player> m_player;

	MyContactListener()
	{
		
	}

	void setPlayer(std::shared_ptr<Player> player)
	{
		m_player = player;
	}

	void BeginContact(b2Contact* contact) {

		////check if fixture A was a ball
		void* bodyUserDataA = contact->GetFixtureA()->GetBody()->GetUserData();
		void*  bodyUserDataB = contact->GetFixtureB()->GetBody()->GetUserData();
		if (bodyUserDataA && bodyUserDataB)
		{
			ENTITY_TYPE typeA = static_cast<Entity*>(bodyUserDataA)->getEntityType();
			ENTITY_TYPE typeB = static_cast<Entity*>(bodyUserDataB)->getEntityType();
			if (typeA == ENTITY_TYPE::GOAL && typeB == ENTITY_TYPE::PLAYER || typeB == ENTITY_TYPE::GOAL && typeA == ENTITY_TYPE::PLAYER  )
			{
				m_player->setReachedGoal();
			}

		}



	}


};