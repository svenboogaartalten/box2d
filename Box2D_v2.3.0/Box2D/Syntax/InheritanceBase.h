#pragma once
#include <iostream>
class InheritanceBase
{
public:
	int m_publicMember;
	char* m_name;
private:
	int m_privateMember;
	
protected:
	int m_protectedMember;
	InheritanceBase(char* name);
	~InheritanceBase();
	
};

