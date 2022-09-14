/* 
AltChromosome class is a subclass of a ClimbChromosome.
*/

#pragma once
#include "climb_chromosome.hh"

class AltChromosome : public ClimbChromosome {
     public:
	 AltChromosome(const Cities* cities_ptr)
	     : ClimbChromosome(cities_ptr){}

	 //Always explicitly write a virtual destructor
	 virtual ~AltChromosome() = default;
	
	// Override recombine with alternating edges crossover (AEX)
	std::pair<Chromosome*, Chromosome*> recombine(const Chromosome* other) override;
   
	/*
	AltChromosome* 
	create_crossover_child(const Chromosome* parent1,
		const Chromosome* parent2,
		unsigned begin,
		unsigned end) const override {return nullptr;}
	*/

	// Overload create_crossover_child
	//AltChromosome* create_crossover_child (Cities::permutation_t parent1, Cities::permutation_t parent2) const;
	Chromosome* create_crossover_child (const Chromosome* parent1,const Chromosome* parent2) const;
	
    private:
	using Chromosome::create_crossover_child;

};
