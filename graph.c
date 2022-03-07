#include "graph.h"

struct Node
{
	int type; //0 if source, 1 if sink, otherwise
	int in;
	int out;
};

struct Edge
{
	int capacity;
	struct Node start;
	struct Node stop;
};

struct Edge* create_edge(struct Node node1, struct Node node2, int capacity)
{
	struct Edge* edge;
	edge->start = node1;
	edge->stop = node2;
	edge->capacity = capacity;
	return edge;
}
