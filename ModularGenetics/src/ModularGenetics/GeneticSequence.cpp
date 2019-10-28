#include "GeneticSequence.h"
#include "Agent.h"

namespace MDLG
{
	GeneticSequence::GeneticSequence(Agent* agent, int length)
	{
		this->agent = agent;
		this->start_index = agent->AddToGenome(length);
	}

	GeneticSequence::~GeneticSequence()
	{
	}

	boost::dynamic_bitset<> GeneticSequence::GetBits() const
	{
		std::string genome_string;
		boost::to_string(*this->agent->get_genome(), genome_string);

		return boost::dynamic_bitset<>(genome_string.substr(this->start_index, this->length));
	}
}