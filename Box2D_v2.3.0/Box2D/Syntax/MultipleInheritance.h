#pragma once
#include "AnotherBase.h"
#include "InheritanceBase.h"

class MultipleInheritance :
	public AnotherBase, public InheritanceBase
{
public:
	MultipleInheritance();
	~MultipleInheritance();
};

