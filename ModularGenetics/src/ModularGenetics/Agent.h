#pragma once

#include "Core.h"
#include <vector>
#include <boost\dynamic_bitset.hpp>
#include <random>

namespace MDLG
{
	class MDLG_API Agent
	{
	public:
		static void BreedAgents(std::mt19937& rng, Agent& parent1, Agent& parent2, Agent& child1, Agent& child2, int num_crossovers, double mutation_rate);

		Agent();
		~Agent();

		int AddSequence(int length);
		void SetGenome(std::vector<boost::dynamic_bitset<>> genome, bool ensure_length_compliance = true);
		void SetRandomGenome(std::mt19937& rng);
		const std::vector<boost::dynamic_bitset<>>* get_genome() const;
		const std::vector<int>* get_genome_lengths() const;

		bool IsCompatible(Agent& other) const;

	private:
		std::vector<boost::dynamic_bitset<>> genome;
		std::vector<int> genome_lengths;
	};
}
