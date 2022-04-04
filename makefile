CPP_FLAGS = -std=c++17 -pthread -O3
SOURCE = ./src/main.cpp
DEPENDENCIAS = ./src/parse_utils/parse.cpp ./src/algorithms/pre_processing.cpp ./src/algorithms/algorithms.cpp ./src/algorithms/alg_utils_sg.cpp ./src/algorithms/alg_utils_mul.cpp 
ALGORITMOS = ./src/algorithms/brute_force.cpp ./src/algorithms/kmp.cpp ./src/algorithms/boyermoore.cpp ./src/algorithms/sellers.cpp 
OUTPUTS = ./bin/outputs/output*
MAIN = ./bin/pmt

all: config

config:
	g++ $(CPP_FLAGS) $(SOURCE) $(DEPENDENCIAS) $(ALGORITMOS) -o $(MAIN)

clean:
	rm $(OUTPUTS)
	rm $(MAIN)

