#pragma once

#include "Core.h"
#include <vector>
#include <random>

namespace MDLG
{
	class Agent;

	class MDLG_API EvolutionClient
	{
	public:
		static void BreedGeneration(std::mt19937& rng, std::vector<std::tuple<double, Agent*>>& weighted_gen, std::vector<Agent*>& new_gen, int num_crossovers, double mutation_rate);
		static Agent* WeightedSelect(std::mt19937& rng, std::vector<std::tuple<double, Agent*>>& weighted_gen, double weight_sum);

		EvolutionClient();
		~EvolutionClient();
	};
}