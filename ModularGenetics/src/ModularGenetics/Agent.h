#pragma once

#include "Core.h"
#include <vector>
#include <boost\dynamic_bitset.hpp>

namespace MDLG
{
	class MDLG_API Agent
	{
	public:
		Agent();
		~Agent();

		int AddSequence(int length);
		void AddGenome(std::vector<boost::dynamic_bitset<>> genome, bool ensure_length_compliance = true);
		void GenerateRandomGenome(int seed);
		const std::vector<boost::dynamic_bitset<>>* get_genome() const;

	private:
		std::vector<boost::dynamic_bitset<>> genome;
		std::vector<int> genome_lengths;
	};
}
