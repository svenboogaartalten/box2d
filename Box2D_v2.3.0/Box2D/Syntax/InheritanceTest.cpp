#include "stdafx.h"
#include "InheritanceTest.h"

#include "InheritancePrivate.h"
#include "InheritancePublic.h"
#include "InheritanceProtected.h"
#include "MultipleInheritance.h"

InheritanceTest::InheritanceTest()
{
}


InheritanceTest::~InheritanceTest()
{
}

void InheritanceTest::RunTest()
{
	std::cout << std::endl << std::endl;
	std::cout << "Inheritance test" << std::endl;
	//We used public inheritance so we can change the public members
	InheritancePublic publicInstance;
	publicInstance.m_publicMember = 2;


	//We cant change the public members of the base class because we used protected inheritance
	InheritanceProtected protectedInstance;
	
	//we cant access the printdata function for the private and public inherited objects.
	//protectedInstance.printData();

	//We cant change the public members of the base class because we used private inheritance
	InheritancePrivate privateInstance;


	//We inherited from multiple base classes, now we can access the members of both base classes.
	MultipleInheritance multipleBaseClassesInstance;
	multipleBaseClassesInstance.m_publicMember = 2;
	multipleBaseClassesInstance.secondBaseClassMember = 2;





}
