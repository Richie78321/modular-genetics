#pragma once

#include "Core.h"
#include <boost\dynamic_bitset.hpp>

namespace MDLG
{
	class Agent;
	class MDLG_API GeneticSequence
	{
	public:
		GeneticSequence(Agent* agent, int length);
		~GeneticSequence();

		boost::dynamic_bitset<> GetBits() const;

	private:
		Agent* agent;
		int start_index;
		int length;
	};
}

