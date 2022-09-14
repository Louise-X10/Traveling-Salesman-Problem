# Traveling-Salesman-Problem

This project uses C++ code and Genetic Algorithm to solve the Traveling Salesman Problem. The inheritance mechanism and polymorphism are utilized to implement different GA programs. This is a project from CSCI 221 taught by Eitan Frachtenberg. There's an optional extra-credit instruction to implement an algorithm with a modification of my choice, so I chose to modify the recombination process to use alternative edge crossover (AEX) instead. There was also an optional part to evaluate the performance of algorithms on multithread machines, which I also implemented and included here. 

"challenge.tsv" contains simulated data of city coordiantes used to run the algorithms. "five.tsv" contains data of 5 cities used for a preliminary test of algorithms. 

## Results
"shortest.tsv" implements randomized search. 

"baseline_ga.tsv" implements random swap for mutation and ordered crossover for recombination, it uses 'chromosome' and 'deme'.

"local.tsv" implements local hill climbing mutation, it uses 'climb_chromosome' and 'deme'.

"tournament.tsv" implements tournament selection, it uses 'climb_chromosome' and 'tournament_deme'.

"alternative.tsv" implements alternative edge crossover for recombination, it uses 'alt_chromosome' and 'tournament_deme'.

"performance.tsv" shows runtimes for scaling from 1 to 4 threads, it uses 'climb_chromosome' and 'tournament_deme'.

Most procedures use a population of size 1000 and 0.3 mutation rate, except the alternative chormosome procedure that uses 0.8 as mutation rate because higher mutation rate seems to produce better results. 

## Compilation instructions
Type "make" in the terminal to build the program. 
Run "./tsp challenge.tsv popsize mutrate > tournament.tsv" to obtain results for the tournament algorithm. Remember to comment out corresponding lines of code in "tsp.cc" to run different algorithms.
