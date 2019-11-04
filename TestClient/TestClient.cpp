// TestClient.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "ModularGenetics.h"
#include <string>
#include <boost\dynamic_bitset.hpp>
#include <chrono>
#include <random>

using namespace MDLG;

void test();

int main()
{
	std::cin.get();
	test();
	std::cin.get();
}

void test()
{
	std::mt19937 rng(78321);
	std::vector<std::tuple<double, Agent*>> agents;

	std::uniform_real_distribution<> dist(0, 100);

	std::cin.get();

	for (int i = 0; i < 100; i++)
	{
		Agent* new_agent = new Agent();
		new_agent->AddSequence(10);
		new_agent->AddSequence(20);
		new_agent->AddSequence(30);
		new_agent->SetRandomGenome(rng);

		agents.push_back(std::tuple<double, Agent*>{ dist(rng), new_agent });
	}

	std::cin.get();

	std::vector<Agent*> child_agents;
	for (int i = 0; i < 100; i++)
	{
		Agent* new_agent = new Agent();
		new_agent->AddSequence(10);
		new_agent->AddSequence(20);
		new_agent->AddSequence(30);
		child_agents.push_back(new_agent);
	}

	std::cin.get();

	EvolutionClient::BreedGeneration(rng, agents, child_agents, 5, .01);

	for (int i = 0; i < child_agents[0]->get_genome()->size(); i++)
	{
		std::string result;
		boost::to_string((*child_agents[0]->get_genome())[i], result);

		std::cout << result << std::endl;
	}

	std::cin.get();

	for (int i = 0; i < agents.size(); i++)
	{
		delete std::get<1>(agents[i]);
	}

	for (int i = 0; i < child_agents.size(); i++)
	{
		delete child_agents[i];
	}
}