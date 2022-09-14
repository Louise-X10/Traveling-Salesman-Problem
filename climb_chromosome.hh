/* 
ClimbChromosome class is a subclass of a Chromosome.
*/

#pragma once
#include "chromosome.hh"

 // Note public inheritance: we want all of Chromosome's API

class ClimbChromosome : public Chromosome {
     public:
	 ClimbChromosome(const Cities* cities_ptr)
	     : Chromosome(cities_ptr){}

	 //Always explicitly write a virtual destructor
	 virtual ~ClimbChromosome() = default;
	
	// Override clone
	Chromosome* clone() const override {
	    return new ClimbChromosome(*this);
	}
 
	 // Override mutate with local hill climbing 
	void mutate() override;
};
