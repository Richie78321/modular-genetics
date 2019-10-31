#include "GeneticSequence.h"
#include "Agent.h"
#include <random>

namespace MDLG
{
	std::vector<boost::dynamic_bitset<>> GeneticSequence::Crossover(std::mt19937& rng, int num_crossovers, const boost::dynamic_bitset<>& sequence_1, const boost::dynamic_bitset<>& sequence_2)
	{
		//Validate values
		if (num_crossovers < 1)
			throw std::invalid_argument("Must have one or more crossovers.");
		if (sequence_1.size() != sequence_2.size())
			throw std::invalid_argument("Genetic sequences must be of equal length to crossover.");

		std::string child_1, child_2;
		boost::to_string(sequence_1, child_1);
		boost::to_string(sequence_2, child_2);

		//Generate random device
		std::uniform_int_distribution<> dis(1, sequence_1.size() - 1);

		for (int i = 0; i < num_crossovers; i++)
		{
			int crossover_index = dis(rng);

			//Crossover w/ substrings
			std::string new_child_1 = child_1.substr(0, crossover_index) + child_2.substr(crossover_index, sequence_1.size() - crossover_index);
			std::string new_child_2 = child_2.substr(0, crossover_index) + child_1.substr(crossover_index, sequence_1.size() - crossover_index);

			//Apply crossover
			child_1 = new_child_1;
			child_2 = new_child_2;
		}

		return std::vector<boost::dynamic_bitset<>>{ boost::dynamic_bitset<>(child_1), boost::dynamic_bitset<>(child_2) };
	}

	void GeneticSequence::Mutate(std::mt19937& rng, boost::dynamic_bitset<>& sequence, double mutation_rate)
	{
		if (mutation_rate < 0 || mutation_rate > 1)
		{
			throw std::invalid_argument("Invalid mutation rate.");
		}

		std::uniform_real_distribution<> dis(0, 1);

		for (int i = 0; i < sequence.size(); i++)
		{
			if (dis(rng) <= mutation_rate)
			{
				sequence.flip(i);
			}
		}
	}

	GeneticSequence::GeneticSequence(Agent& agent, int length) : length(length), agent(agent)
	{
		this->seq_index = agent.AddSequence(length);
	}

	const boost::dynamic_bitset<>* GeneticSequence::bit_seq() const
	{
		return &(*this->agent.get_genome())[this->seq_index];
	}

	GeneticSequence::~GeneticSequence()
	{
	}
}