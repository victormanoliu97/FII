#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<assert.h>
#include"Graph.h"

using namespace std;

template<typename T>
int Graph<T>::AddVertex(T value)
{
	int id = VertexCount();
	
	vertices.push_back(Vertex(id, value));

	return id;
}

template<typename T>
pair<int, int> Graph<T>::AddEdgeAndVertices(T start_value, T end_value, int cost)
{
	int start_id = AddVertex(start_value);

	int end_id = AddVertex(end_value);

	AddEdge(start_id, end_id, cost);

	return pair<int, int>(start_id, end_id);
}

template<typename T>
void Graph<T>::AddEdge(int start_id, int end_id, int cost)
{
	/*
	assert(start_id >= 0 && start_id < VertexCount());
	assert(end_id >= 0 && end_id < VertexCount());
	*/

	vertices[start_id].AddEdge(end_id, cost);

	if (!directed)
	{
		vertices[end_id].AddEdge(start_id, cost);
	}
}

template<typename T>
int Graph<T>::VertexCount() const
{
	return vertices.size();
}

template<typename T>
const T & Graph<T>::GetVertexData(int vertex_id) const
{
	return vertices[vertex_id].GetData();
}

template<typename T>
vector<int> Graph<T>::GetAllVertexID() const
{
	vector<int> vertex_ids(VertexCount());

	for (size_t i = 0; i < vertex_ids.size(); i++)
	{
		vertex_ids[i] = i;
	}

	return vertex_ids;
}

template<typename T>
pair<vector<int>, vector<int>> Graph<T>::BFS(int start_id) const
{
	vector<int> parent(VertexCount(), -1);

	vector<int> vertex_ids(VertexCount(), -1);

	vector<bool> visited(VertexCount(), false);

	queue<int> my_queue;

	my_queue.push(start_id);

	int index = 0;

	vertex_ids[index++] = start_id;

	parent[start_id] = -1;

	visited[start_id] = true;


	while (!my_queue.empty())
	{
		int id = my_queue.front();

		my_queue.pop();

		for (const OutEdge e : vertices[id].GetOutgoingEdges())
		{
			int neighbour_id = e.GetDestID();

			if (!visited[neighbour_id])
			{
				visited[neighbour_id] = true;

				vertices[index++] = neighbour_id;

				parent[neighbour_id] = id;

				my_queue.push(neighbour_id);
			}
		}
	}

	return make_pair(vertex_ids, parent);
}

template<typename T>
vector<int> Graph<T>::DFS(int start_id, bool recursive) const
{
	vector<bool> visited(VertexCount(), false);

	// Implementare recursiva
	if (recursive)
	{
		vector<int> visit_order_recursive;

		DFSRecursiv(start_id, visit_order_recursive, visited);

		return visit_order_recursive;
	}

	//Implementare iterativa

	vector<int> visit_order(VertexCount(), -1);

	stack<int> my_stack;

	my_stack.push(start_id);

	int index = 0;

	while (!my_stack.empty())
	{
		int id = my_stack.top();

		my_stack.pop();

		if (!visited[id])
		{
			visited[id] = true;

			visit_order[index++] = id;

			for (const OutEdge e : vertices[id].GetOutgoingEdges())
			{
				int neighbour_id = e.GetDestID();

				my_stack.push(neighbour_id);
			}
		}
	}

	return visit_order;
}

template<typename T>
ostream & operator<<(ostream & out, Graph<T> & g)
{
	g.Print(out);

	return out;
}

template<typename T>
void Graph<T>::DFSRecursiv(int vertex_id, vector<int> & visit_order, vector<bool> & visited) const
{
	visited[vertex_id] = true;

	visit_order.push_back(vertex_id); // pre ordine

	for (const OutEdge e : vertices[vertex_id].GetOutgoingEdges())
	{
		int neighbour_id = e.GetDestID();

		if (!visited[neighbour_id])
		{
			DFSRecursiv(neighbour_id, visit_order, visited);
		}
	}

	// post ordine
}

template<typename T>
void Graph<T>::Print(ostream & out) const
{
	out << "V = ";

	for (const Vertex v : vertices)
	{
		out << v.GetData() << " ";
	}

	out << endl;
	
	out << "E = ";

	for (const Vertex v : vertices)
	{
		out << "[" << v.GetData() << ":";

		for (const OutEdge e : v.GetOutgoingEdges())
		{
			out << " " << vertices[e.GetDistID()].GetData();
		}

		out << "]";
	}

	out << endl;
}

template<typename T>
const int Graph<T>::OutEdge::GetDestID() const
{
	return dest_id;
}

template<typename T>
const int Graph<T>::OutEdge::GetCost() const
{
	return cost;
}

template<typename T>
void Graph<T>::Vertex::AddEdge(int end_id, int cost)
{
	outgoing_edges.push_back(OutEdge(end_id, cost));
}

template<typename T>
const T & Graph<T>::Vertex::GetData() const
{
	return data;
}

template<typename T>
const vector<typename Graph<T>::OutEdge> &	Graph<T>::Vertex::GetOutgoingEdges() const
{
	return outgoing_edges;
}