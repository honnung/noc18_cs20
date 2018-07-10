// daa - week 3 programming assignment
// https://onlinecourses.nptel.ac.in/noc18_cs20/progassignment?name=136
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int DFS(const int n, const int src, const vector< vector <int> > &graph, const vector <int> &museums, vector <bool> &visited)
{
	if (visited[src] == true) return 0;
	int sum = museums[src];
	visited[src] = true;
	const vector<int> & adj1 = graph[src];
	for (vector<int>::const_iterator ci = adj1.begin(); ci != adj1.end(); ci++)
	{
		int next = *ci;
		if (visited[next] == false)
			sum += DFS(n, next, graph, museums, visited);
	}
	return sum;
}

int main(void)
{
	int M, A, B;
	cin >> M >> A >> B;
	
	vector< vector <int> > graph;
	graph.reserve(M);
	for (int m = 0; m < M; m++)
	{
		vector<int>  node;
		graph.push_back(node);
	}
	
	for (int m = 0; m < M; m++)
	{
		int x,y,z;
		cin >> x >> y >> z;
		x--; y--; z--;

		vector<int> & adjx = graph[x];
		adjx.push_back(y);

		vector<int> & adjy = graph[y];
		adjy.push_back(x);
		adjy.push_back(z);
		
		vector<int> & adjz = graph[z];
		adjz.push_back(y);
	}
		
	cout << total << endl;
	
	return 0;
}

