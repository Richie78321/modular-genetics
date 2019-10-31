#pragma once
#include "Core.h"
#include <boost\dynamic_bitset.hpp>
#include <random>

namespace MDLG
{
	class Agent;

	class MDLG_API GeneticSequence
	{
	public:
		static std::vector<boost::dynamic_bitset<>> Crossover(std::mt19937& rng, int num_crossovers, const boost::dynamic_bitset<>& sequence_1, const boost::dynamic_bitset<>& sequence_2);
		static void Mutate(std::mt19937& rng, boost::dynamic_bitset<>& sequence, double mutation_rate);

		GeneticSequence(Agent& agent, int length);
		~GeneticSequence();

		const boost::dynamic_bitset<>* bit_seq() const;
		const int length;

	private:
		int seq_index;
		Agent& agent;
	};
}