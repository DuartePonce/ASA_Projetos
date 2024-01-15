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
$(GEN_EXE): gen_tuganet.cpp
	$(CXX) $(CXXFLAGS) -o $(GEN_EXE) gen_tuganet.cpp

# Rule to build the 'proj' executable
$(PROJ_EXE): Project2.cpp
	$(CXX) $(CXXFLAGS) -o $(PROJ_EXE) Project2.cpp

# Rule to generate data and execute 'proj'
run: $(GEN_EXE) $(PROJ_EXE)
	./$(GEN_EXE) 100 150 10 5 10 ./$(PROJ_EXE) > txt.txt
	./$(PROJ_EXE) < txt.txt

# Clean target to remove executables and generated files
clean:
	rm -f $(GEN_EXE) $(PROJ_EXE) txt.txt