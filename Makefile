CXX=clang++
CXXFLAGS=-Wall -Wextra -pedantic -Werror -std=c++17 -O3
LDFLAGS=$(CXXFLAGS)
OBJ=$(SRC:.cc=.o)

all:  tsp

tsp: tsp.o chromosome.o climb_chromosome.o deme.o cities.o tournament_deme.o
	$(CXX) $(LDFLAGS) -o $@ $^

test_alt: test_alt.o cities.o chromosome.o climb_chromosome.o alt_chromosome.o
	$(CXX) $(LDFLAGS) -o $@ $^
%.o: %.cc %.hh
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c -o $@ $<

clean:
	rm -rf *.o tsp
