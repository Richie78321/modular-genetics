#include "Agent.h"
#include <exception>
#include <random>

namespace MDLG
{
	Agent::Agent(std::vector<int> genome_lengths)
	{
		this->genome_lengths = genome_lengths;
	}

	Agent::Agent()
	{
	}

	int Agent::AddSequence(int length)
	{
		this->genome_lengths.push_back(length);
		return this->genome_lengths.size() - 1;
	}

	void Agent::AddGenome(std::vector<boost::dynamic_bitset<>> genome, bool ensure_length_compliance)
	{
		if (ensure_length_compliance)
		{
			//Verify length
			if (genome.size() != genome_lengths.size())
			{
				throw std::invalid_argument("Genome does not comply with agent genome length.");
			}

			for (int i = 0; i < genome.size(); i++)
			{
				if (genome[i].size() != genome_lengths[i])
				{
					throw std::invalid_argument("Genome does not comply with agent genome length.");
				}
			}
		}

		this->genome = genome;
	}

	void Agent::GenerateRandomGenome(int seed)
	{
		this->genome.clear();
		for (int i = 0; i < this->genome_lengths.size(); i++)
		{
			std::string genome_string = "";
			std::mt19937 gen(seed);
			std::uniform_int_distribution<> dis(1, 2);
			for (int j = 0; j < this->genome_lengths[i]; j++)
			{
				genome_string += std::to_string(dis(gen) % 2);
			}
			this->genome.push_back(boost::dynamic_bitset<>(genome_string));
		}
	}

	const std::vector<boost::dynamic_bitset<>>* Agent::get_genome() const
	{
		return &this->genome;
	}

	Agent::~Agent()
	{
	}
}