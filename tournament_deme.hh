/* 
TournamentDeme is a subclass of Deme
*/

#pragma once
#include "deme.hh"

 // Note public inheritance: we want all of Deme's API

class TournamentDeme : public Deme {
     public:
	 TournamentDeme(const Cities* cities_ptr, unsigned pop_size, double mut_rate)
	     :Deme(cities_ptr, pop_size, mut_rate){}

	 //Always explicitly write a virtual destructor
	 virtual ~TournamentDeme() = default;
 
	 // Override compute_next gen 
	 //void compute_next_generation() override;

    private:	
	// Override select_parent with tournament selection 
	Chromosome* select_parent()override;

};
