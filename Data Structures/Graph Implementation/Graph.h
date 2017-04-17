#include<iostream>
#include<utility>
#include<vector>
#include<ostream>

using namespace std;

template<typename T>
class Graph
{
public:
	Graph(bool directed = false) : directed(directed)  {}

	int AddVertex(T value);

	pair<int, int> AddEdgeAndVertices(T start_value, T end_value, int cost = 0);

	void AddEdge(int start_id, int end_id, int cost = 0);

	int VertexCount() const;

	const T & GetVertexData(int vertex_id) const;

	vector<int> GetAllVertexID() const;

	pair<vector<int>, vector<int>> BFS(int start_id) const;

	vector<int> DFS(int start_id, bool recursive = false) const;


	template<typename U>

	friend ostream & operator<<(ostream & out, Graph<U> & g);


private:
	class Vertex;

	vector<Vertex> vertices;

	const bool directed;

	void DFSRecursiv(int vertex_id, vector<int> & visit_order, vector<bool> & visited) const;

	void Print(ostream & out) const;


	class OutEdge
	{
	public:
		OutEdge(int end_id, int cost) : dest_id(end_id), cost(cost) {}
		
		const int GetDestID() const;

		const int GetCost() const;

	private:
		int dest_id;

		int cost;
	};

	
	class Vertex
	{
	public:
		Vertex(int id, T value) : id(id), data(value) {}

		void AddEdge(int end_id, int cost);

		const T & GetData() const;

		const vector<OutEdge> & GetOutgoingEdges() const;

	private:
		int id;
		
		T data;

		vector<OutEdge> outgoing_edges;
	};
};