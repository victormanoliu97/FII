#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include"Graph.h"
using namespace std;

int main()
{
	Graph<string> g;

	pair<int, int> ids_A_B = g.AddEdgeAndVertices("A", "B");
	pair<int, int> ids_C_G = g.AddEdgeAndVertices("C", "G");
	pair<int, int> ids_E_F = g.AddEdgeAndVertices("E", "F");


	int id_D = g.AddVertex("D");

	g.AddEdge(ids_A_B.first, ids_C_G.first); 
	g.AddEdge(ids_A_B.first, ids_E_F.first); 
	g.AddEdge(ids_A_B.second, id_D); 
	g.AddEdge(ids_A_B.second, ids_E_F.second); 

	cout << "Initial Graph:\n";
	cout << g;



	// BFS
	pair<vector<int>, vector<int>> vertex_parents = g.BFS(ids_A_B.first);

	int first_vertex = vertex_parents.first[0]; 

	cout << "\nBFS starting at vertex " << g.GetVertexData(ids_A_B.first) << endl;

	for (size_t i = 0; i < vertex_parents.first.size(); ++i)
	{
		int curr_vertex = vertex_parents.first[i];

		int distance = 0;

		while (curr_vertex != first_vertex)
		{
			cout << g.GetVertexData(curr_vertex) << "->";

			curr_vertex = vertex_parents.second[curr_vertex];

			++distance;
		}
		cout << g.GetVertexData(first_vertex) << ", distance = " << distance <<endl;
	}



	// DFS
	vector<int> visit_order = g.DFS(ids_A_B.first, true);

	cout << "\nDFS starting at vertex " << g.GetVertexData(ids_A_B.first) << endl;

	for (int vertex_id : visit_order)
	{
		cout << g.GetVertexData(vertex_id) << "->";
	}

	cout << endl;
	
	return 0;
}