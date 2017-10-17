#include "stdafx.h"
#include "InheritancePrivate.h"


InheritancePrivate::InheritancePrivate() : InheritanceBase("private")
{
	//m_privateMember is not accesible
	//!! both members are now private from outside the class because the inheritance is private!!
}


InheritancePrivate::~InheritancePrivate()
{
}

