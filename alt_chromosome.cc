#include "alt_chromosome.hh"
#include "climb_chromosome.hh"
#include "chromosome.hh"


//////////////////////////////////////////////////////////////////////////////
// For an ordered set of parents, return a child using the ordered crossover.
// The child will have alternation arcs from first and second parent, 
// with some additional random choices in case of infeasibility
//

void remove_val (Cities::permutation_t& vector, unsigned val) {
    auto pos = std::find(vector.begin(), vector.end(), val);
    vector.erase(pos);
}

unsigned find_next (Cities::permutation_t vector, unsigned current){
    auto it = std::find(vector.begin(), vector.end(), current);
    unsigned next;
    if (it+1!=vector.end()) {
        next = *(it+1);
    } else {
        next = *vector.begin();
    }
    return next;
}


Chromosome* 
AltChromosome::create_crossover_child (const Chromosome* parent1,const Chromosome* parent2) const {
//AltChromosome*
//AltChromosome::create_crossover_child (Cities::permutation_t p1, Cities::permutation_t p2) const {
    Chromosome* child = parent1->clone();
    auto p1 = parent1->get_ordering();
    auto p2 = parent2->get_ordering();
    auto c = child->get_ordering();

    const unsigned len = p1.size();
    std::vector<unsigned> store; // vector of entries stored into child
    std::vector<unsigned> remain(len,0); // vector of entries not stored into child yet
    std::iota(remain.begin(), remain.end(), 0); // remaining indices in standard permutation order

    // Already have first arc from p1 when cloning, i.e. already set first two entries
    unsigned index = 1; 
    unsigned current = c[index];
    store.push_back(c[0]);
    store.push_back(c[1]);
    remove_val(remain, c[0]);
    remove_val(remain, c[1]);
 
    while (index < c.size()-1) {
	unsigned next;
	if (index  % 2 == 1) { 
	    next = find_next(p2, current); // search for current value in p2, return the next value
	} else {
	    next = find_next(p1, current);
	}

	// if next already in child, then pick unvisited vertices randomly
	auto it2 = std::find(store.begin(), store.end(), next);
	//assert(it2 == store.end());
	if (it2 == store.end()) { // next not already in child
	    c[index+1] = next; // set next in child
	    current = next;
	    store.push_back(next);
	    remove_val(remain, next); // delete next from remaining indices
	} else {
	    std::uniform_int_distribution<int> dist(0, remain.size()-1); // not static bc remain size changes
	    std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
	    int p = dist(generator); // random index for remain vector
	    unsigned random = remain[p];

	    c[index+1] = random;// set random remaining index in child
	    current = random;
	    store.push_back(random);
	    remove_val(remain, random); // delete random index from remaining indices
	}
	index++;
    }
    
    child->set_ordering(c);
    return child;
}

std::pair<Chromosome*, Chromosome*> 
AltChromosome::recombine(const Chromosome* other) {
    auto child1 = create_crossover_child(this, other);
    auto child2 = create_crossover_child(other, this);
    
    return std::make_pair(child1, child2);

}
