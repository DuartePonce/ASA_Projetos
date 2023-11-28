# Define compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -O3 -Wall

# Executable names
GEN_EXE = gen
PROJ_EXE = proj

# Default target
all: $(GEN_EXE) $(PROJ_EXE)

# Rule to build the 'gen' executable
$(GEN_EXE): gen_supermarble.cpp
	$(CXX) $(CXXFLAGS) -o $(GEN_EXE) gen_supermarble.cpp

# Rule to build the 'proj' executable
$(PROJ_EXE): Proj1New.cpp
	$(CXX) $(CXXFLAGS) -o $(PROJ_EXE) Proj1New.cpp

# Rule to generate data and execute 'proj'
run: $(GEN_EXE) $(PROJ_EXE)
	./$(GEN_EXE) 100000 100000 10000000 ./$(PROJ_EXE) > txt.txt
	./$(PROJ_EXE) < txt.txt

# Clean target to remove executables and generated files
clean:
	rm -f $(GEN_EXE) $(PROJ_EXE) txt.txt