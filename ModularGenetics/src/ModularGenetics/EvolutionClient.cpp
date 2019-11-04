#include "EvolutionClient.h"
#include <tuple>
#include "Agent.h"

namespace MDLG
{
	void EvolutionClient::BreedGeneration(std::mt19937& rng, std::vector<std::tuple<double, Agent*>>& weighted_gen, std::vector<Agent*>& new_gen, int num_crossovers, double mutation_rate)
	{
		float weight_sum = 0;
		for (int i = 0; i < weighted_gen.size(); i++)
		{
			if (std::get<0>(weighted_gen[i]) >= 0)
			{
				weight_sum += std::get<0>(weighted_gen[i]);
			}
			else
			{
				throw std::invalid_argument("Agent weight is invalid. Weights must be greater than or equal to zero.");
			}
		}

		for (int i = 0; i < new_gen.size(); i += 2)
		{
			//Perform weighted select for breeding
			Agent* parent1 = WeightedSelect(rng, weighted_gen, weight_sum);
			Agent* parent2 = WeightedSelect(rng, weighted_gen, weight_sum);

			Agent::BreedAgents(rng, *parent1, *parent2, *new_gen[i], *new_gen[(i + 1) % new_gen.size()], num_crossovers, mutation_rate);
		}
	}

	Agent * EvolutionClient::WeightedSelect(std::mt19937 & rng, std::vector<std::tuple<double, Agent*>>& weighted_gen, double weight_sum)
	{
		std::uniform_real_distribution<> dis(0, weight_sum);
		double selection = dis(rng);

		double current_weight = 0;
		for (int i = 0; i < weighted_gen.size(); i++)
		{
			current_weight += std::get<0>(weighted_gen[i]);
			if (current_weight >= selection)
			{
				return std::get<1>(weighted_gen[i]);
			}
		}

		throw std::runtime_error("Unable to perform weighted select -- likely invalid weights.");
	}



	EvolutionClient::EvolutionClient()
	{

	}

	EvolutionClient::~EvolutionClient()
	{

	}
}
