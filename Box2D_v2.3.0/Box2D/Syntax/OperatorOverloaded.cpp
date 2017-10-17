#include "stdafx.h"
#include "OperatorOverloaded.h"


OperatorOverloaded::OperatorOverloaded(int value): m_value(value)
{
	
}


OperatorOverloaded::~OperatorOverloaded()
{
}

//We can now add two of our custom objects together.
OperatorOverloaded OperatorOverloaded::operator+(const OperatorOverloaded & other)
{
	return OperatorOverloaded(m_value + other.m_value);
}
