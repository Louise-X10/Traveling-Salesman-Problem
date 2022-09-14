#include "climb_chromosome.hh"

Cities::permutation_t swap_left(Cities::permutation_t order, int p, int N) {
    if (p==0) {
	std::swap(order[p], order[N-1]);
    } else {
        std::swap(order[p], order[p-1]);
    }
    return order;
}

Cities::permutation_t swap_right(Cities::permutation_t order, int p, int N) {
    if (p==N-1) {
	std::swap(order[p], order[0]);
    } else {
        std::swap(order[p], order[p+1]);
    }
    return order;
}

void ClimbChromosome::mutate() {
    double best_fitness = get_fitness();
    static std::uniform_int_distribution<int> distribution(0, order_.size()-1); 
    int p = distribution(generator_); // random int from 0 to permutation length-1
    int N = order_.size();
    auto best_order = order_;

    order_ = swap_left(order_,p,N);
    double fitness_left = get_fitness();
    if (fitness_left > best_fitness) {
	best_order = order_;
    }
    order_ = swap_right(order_,p,N);

    order_ = swap_right(order_,p,N);
    double fitness_right = get_fitness();
    if (fitness_right > best_fitness) {
	best_order = order_;
    }
    
    order_ = best_order;

}

/* Method using clone
void ClimbChromosome::mutate() {
    double best_fitness = get_fitness();
    static std::uniform_int_distribution<int> distribution(0, order_.size()-1); 
    int p = distribution(generator_); // random int from 0 to permutation length-1
    int N = order_.size();
    auto best_order = order_;

    Chromosome* left = this->clone();
    left->order_ = swap_left(order_,p,N);
    double fitness_left = left->get_fitness();
    if (fitness_left > best_fitness) {
	best_order = order_;
    }
 
    Chromosome* right = this->clone();
    right->order_ = swap_right(order_,p,N);
    double fitness_right = right->get_fitness();
    if (fitness_right > best_fitness) {
	best_order = order_;
    }

    order_ = best_order;
    delete left;
    delete right;

}

*/
