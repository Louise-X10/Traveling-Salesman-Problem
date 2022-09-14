#include "tournament_deme.hh"
#include<cassert>

// Take pairs in set of parents, discard lower fitness of each pair, have half the size in resulting set
void tournament(std::vector<Chromosome*> &pop) {
    for (unsigned i = 0; i < pop.size()/2; i++){
	auto fit_1 = pop[i];
	auto fit_2 = pop[i+1];
	if (fit_1 <= fit_2) {
	    pop.erase(pop.begin()+i);
	} else {
	    pop.erase(pop.begin()+i+1);
	}
    }
}
Chromosome* TournamentDeme::select_parent() {

    // P is some constant power of two (no bigger than population size)
    unsigned  P =16;
    assert(P <= pop_.size());

    static std::uniform_int_distribution<int> distribution(0, pop_.size()-1); // random int generator for 0 to permutation length

    // Select P parents at random
    std::vector<Chromosome*> pop;
    for (unsigned i = 0; i < P; i++) {
	int random = distribution(generator_);
	pop.push_back(pop_[random]);
    }

    // Repeat until one parent left
    while (pop.size() > 1) {
	//unsigned size = pop.size();
	tournament(pop);
	//assert(pop.size() == size/2);
    }

    return pop[0];
}

