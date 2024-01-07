# Define compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -O3 -Wall

# Executable names
GEN_EXE = gen

# Default target
all: $(GEN_EXE)

# Rule to build the 'gen' executable
$(GEN_EXE): gen_ubiquity.cpp
	$(CXX) $(CXXFLAGS) -o $(GEN_EXE) gen_ubiquity.cpp

  #cerr << "Usage: " << progname << " <T> <P> <Tcmin> <Tcmax> <Tlmax> <Pok> <seed>" << endl;
  #cerr << "  T: number of toys" << endl;
  #cerr << "  P: number of packs" << endl;
  #cerr << "  Tcmin: Toy min capacity" << endl;
  #cerr << "  Tcmax: Toy max capacity" << endl;
  #cerr << "  Tlmax: Toy max profit" << endl;
  #cerr << "  Pok: % valid packs [0,100]" << endl;
  #cerr << "  seed: random seed generator (opcional)" << endl;

# Rule to generate data and execute 'proj'
run: $(GEN_EXE) 
	./$(GEN_EXE) 30 10 20 50 30 5 ./$(PROJ_EXE) > testfile
	python3 projecto.py < testfile

# Clean target to remove executables and generated files
clean:
	rm -f $(GEN_EXE) testfile