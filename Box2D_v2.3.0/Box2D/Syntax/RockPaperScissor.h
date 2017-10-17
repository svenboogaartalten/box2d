#pragma once
#include <string>
enum CHOISE {
	ROCK,
	PAPER,
	SCISSOR
};
class RockPaperScissor
{
public:	
	int rock, paper, scissor, win, loss;
	CHOISE m_choise;
	void Run();
	void Won();
	void Lose();
	void Tie();
	std::string stringValue(CHOISE);
	RockPaperScissor();
	~RockPaperScissor();
};

