#include "stdafx.h"
#include "InheritanceBase.h"
#include <iostream>



InheritanceBase::InheritanceBase(char* name): m_name(name), m_privateMember(1), m_protectedMember(1)
{
	
}


InheritanceBase::~InheritanceBase()
{
}
