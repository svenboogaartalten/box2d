#include "stdafx.h"
#include "RockPaperScissor.h"
#include <string>
#include <iostream>
void RockPaperScissor::Run()
{
	std::string input = "";
	while (input != "q")
	{
		std::cout << win << " - " << loss << std::endl;
		CHOISE pcPick = static_cast<CHOISE>(rand() % 3);
		std::cout << "p for paper, r for rock, s for scissors, q to surrender." << std::endl;
		std::cin >> input;
		if (input == "s")
		{
			m_choise == SCISSOR;
			switch (pcPick) {
			case(PAPER):
				Won();
				break;
			case(SCISSOR):
				Tie();
				break;	
			default:
				Lose();
			}
		}
		else if (input == "p")
		{
			m_choise == PAPER;
			switch (pcPick) {
			case(ROCK):
				Won();
				break;
			case(PAPER):
				Tie();
				break;
			default:
				Lose();
			}
			
		}
		else if (input == "r")
		{
			m_choise == ROCK;
			switch (pcPick) {
			case(SCISSOR):
				Won();
				break;
			case(ROCK):
				Tie();
				break;
			default:
				Lose();
			};
		}
		else {
			std::cout << "Not valid.";
		}
		std::cout << "The pc picked: "<< stringValue(pcPick) << std::endl << std::endl;
		

	}
}

void RockPaperScissor::Won()
{
	win++;
	std::cout << "you won" << std::endl;
}

void RockPaperScissor::Lose()
{
	loss++;
	std::cout << "you lost" << std::endl;
}

void RockPaperScissor::Tie()
{
	std::cout << "its a tie" << std::endl;
}

std::string RockPaperScissor::stringValue(CHOISE& choise)
{
	switch (choise) {
	case(SCISSOR):
		return "scissors";
	case(ROCK):
		return "rock";
	case(PAPER):
		return "paper";
	default:
		return "Not valid";
	};
}

RockPaperScissor::RockPaperScissor() :rock(0), paper(0), scissor(0), m_choise(ROCK), win(0), loss(0)
{
}


RockPaperScissor::~RockPaperScissor()
{
}
