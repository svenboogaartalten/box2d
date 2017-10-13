#include "Platform.h"

void Platform::checkMovement()
{
	/*if (m_body->GetPosition == m_from)
	{

	}*/
}

ENTITY_TYPE Platform::getEntityType()
{
	return ENTITY_TYPE::PLATFORM;
}

void Platform::update(float deltaTime)
{
	b2Vec2 distanceToGoal = m_body->GetPosition() - m_destination;
	auto length = distanceToGoal.Length();
	float positionY = m_body->GetPosition().y;
	float positionX = m_body->GetPosition().x;
	if (goToTo)
	{
		
		if (positionY < m_destination.y || positionX > m_destination.x)
		{
			m_destination = m_from;


			float horizontalDistance = (m_destination.x - positionX) / m_speedMultiplier;
			float verticalDistance = (m_destination.y - positionY) / m_speedMultiplier;
			m_body->SetLinearVelocity(b2Vec2(horizontalDistance , verticalDistance));



			goToTo = false;

		}
	}
	else
	{
		if (positionY > m_destination.y|| positionX < m_destination.x)
		{
			m_destination = m_to;

			float horizontalDistance = (m_destination.x - positionX) / m_speedMultiplier;
			float verticalDistance = (m_destination.y - positionY) / m_speedMultiplier;
			m_body->SetLinearVelocity(b2Vec2(horizontalDistance, verticalDistance));

		
			goToTo = true;
		}
	}
}
