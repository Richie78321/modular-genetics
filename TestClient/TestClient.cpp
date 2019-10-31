// TestClient.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "ModularGenetics.h"
#include <boost\dynamic_bitset.hpp>
#include <string>
#include <chrono>
#include <random>

int main()
{
	boost::dynamic_bitset<> seq1(std::string("111111"));
	boost::dynamic_bitset<> seq2(std::string("000000"));

	std::mt19937 rng(12387);

	auto result = MDLG::GeneticSequence::Crossover(rng, 3, seq1, seq2);

	std::cout << result[0] << std::endl;
	std::cout << result[1] << std::endl;

	MDLG::GeneticSequence::Mutate(rng, result[1], .5);
	std::cout << result[1] << std::endl;

	std::cin.get();
}