#include "Agent.h"
#include <exception>
#include <random>
#include <boost\dynamic_bitset.hpp>
#include "GeneticSequence.h"

namespace MDLG
{
	void Agent::BreedAgents(std::mt19937& rng, Agent & parent1, Agent & parent2, Agent & child1, Agent & child2, int num_crossovers, double mutation_rate)
	{
		//Ensure all are compatible
		if (!(parent1.IsCompatible(parent2) && parent2.IsCompatible(child1) && child1.IsCompatible(child2)))
		{
			throw std::invalid_argument("Agents are incompatible.");
		}

		child1.genome.clear();
		child2.genome.clear();

		for (int i = 0; i < parent1.genome.size(); i++)
		{
			std::vector<boost::dynamic_bitset<>> results = GeneticSequence::Crossover(rng, num_crossovers, parent1.genome[i], parent2.genome[i]);
			GeneticSequence::Mutate(rng, results[0], mutation_rate);
			GeneticSequence::Mutate(rng, results[0], mutation_rate);

			//Add to child genomes
			child1.genome.push_back(results[0]);
			child2.genome.push_back(results[1]);
		}
	}

	Agent::Agent()
	{
	}

	int Agent::AddSequence(int length)
	{
		this->genome_lengths.push_back(length);
		return this->genome_lengths.size() - 1;
	}

	void Agent::SetGenome(std::vector<boost::dynamic_bitset<>> genome, bool ensure_length_compliance)
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

	void Agent::SetRandomGenome(std::mt19937 & rng)
	{
		this->genome.clear();
		for (int i = 0; i < this->genome_lengths.size(); i++)
		{
			std::string genome_string = "";
			std::uniform_int_distribution<> dis(1, 2);
			for (int j = 0; j < this->genome_lengths[i]; j++)
			{
				genome_string += std::to_string(dis(rng) % 2);
			}
			this->genome.push_back(boost::dynamic_bitset<>(genome_string));
		}
	}

	const std::vector<boost::dynamic_bitset<>>* Agent::get_genome() const
	{
		return &this->genome;
	}

	const std::vector<int>* Agent::get_genome_lengths() const
	{
		return &this->genome_lengths;
	}

	bool Agent::IsCompatible(Agent & other) const
	{
		if (other.genome_lengths.size() != this->genome_lengths.size())
		{
			return false;
		}
		for (int i = 0; i < this->genome_lengths.size(); i++)
		{
			if (other.genome_lengths[i] != this->genome_lengths[i])
			{
				return false;
			}
		}

		return true;
	}

	Agent::~Agent()
	{
	}
}
