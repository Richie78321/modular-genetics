#include "Agent.h"
#include <string>
#include <random>

namespace MDLG
{
	Agent::Agent()
	{
	}

	Agent::~Agent()
	{
		delete this->genome;
	}

	void Agent::SetGenome(boost::dynamic_bitset<>* genome)
	{
		if (genome->size() != this->genome_size)
		{
			throw std::invalid_argument("Genome does not match target length of agent genome!");
		}
		this->genome = genome;
	}

	void Agent::SetGenome(int seed)
	{
		//Generate genome randomly
		std::string genome_string = "";
		std::mt19937 gen(seed);
		std::uniform_int_distribution<> dis(1, 2);
		for (int i = 0; i < this->genome_size; i++)
		{
			genome_string += std::to_string(dis(gen) % 2);
		}
		this->genome = new boost::dynamic_bitset<>(genome_string);
	}

	int Agent::AddToGenome(int bit_count)
	{
		int start_position = this->genome_size;
		this->genome_size += bit_count;

		return start_position;
	}

	int Agent::get_genome_size() const
	{
		return this->genome_size;
	}
}
