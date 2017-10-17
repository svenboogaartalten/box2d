#pragma once
class OperatorOverloaded
{
public:
	int m_value;
	OperatorOverloaded(int value);
	~OperatorOverloaded();
	OperatorOverloaded operator +(const OperatorOverloaded&);
};

