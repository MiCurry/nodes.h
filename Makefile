all: nodes 

nodes: nodes.cpp nodes.h
	g++ nodes.cpp -o nodes

clean:
	rm -f nodes 
