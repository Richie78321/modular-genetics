#pragma once

#include "Core.h"
#include <boost\dynamic_bitset.hpp>

namespace MDLG
{
	class MDLG_API Agent
	{
	public:
		Agent();
		~Agent();

		void SetGenome(boost::dynamic_bitset<>* genome);
		void SetGenome(int seed);

		int AddToGenome(int bit_count);

		int get_genome_size() const;
		const boost::dynamic_bitset<>* get_genome() const;
	
	private:
		int genome_size = 0;
		boost::dynamic_bitset<>* genome = nullptr;
	};
}

