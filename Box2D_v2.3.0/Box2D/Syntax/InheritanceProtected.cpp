#include "stdafx.h"
#include "InheritanceProtected.h"


InheritanceProtected::InheritanceProtected() : InheritanceBase("Protected")
{
	//m_privateMember is not accesible
	//!! both members are now protected from outside the class because the inheritance is protected!!
}


InheritanceProtected::~InheritanceProtected()
{
}