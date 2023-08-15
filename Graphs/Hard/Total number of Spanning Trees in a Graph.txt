#include<bits/stdc++.h>
using namespace std;

// C++ program to find number of spanning
// trees in a graph using Matrix
// Chain Multiplication
#define MAX 100
#define MOD 1000000007

// Matrix Multiplication
void multiply(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX])
{
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			for (int k = 0; k < MAX; k++)
				C[i][j] = (C[i][j] + (A[i][k] * B[k][j])%MOD)%MOD;	
}

// Function to find Nth power of A
void power(int A[MAX][MAX], int N, int result[MAX][MAX])
{
	int temp[MAX][MAX];
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			result[i][j] = (i == j);

	while (N>0)
	{
		if (N%2 == 1)
		{
			multiply(A, result, temp);
			for (int i=0; i<MAX; i++)
				for (int j=0; j<MAX; j++)
					result[i][j] = temp[i][j];
		}

		N = N/2;
		multiply(A, A, temp);
		for (int i=0; i<MAX; i++)
			for (int j=0; j<MAX; j++)
				A[i][j] = temp[i][j];
	}
}

// Function to find number of Spanning
// Trees in a Graph using Matrix Chain
// Multiplication.
int numOfSpanningTree(int graph[][MAX], int V)
{
	int result[MAX][MAX] = {0};
	int temp[MAX][MAX] = {0};

	// Create a copy of graph as the
	// Adjacency matrix will be changed
	// during the process
	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			temp[i][j] = graph[i][j];

	// Find (V-2)th power of Adjacency
	// matrix
	power(temp, V-2, result);

	int ans = 0;

	// Find sum of all elements in (V-2)th
	// power
	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			ans = (ans + result[i][j])%MOD;

	return ans;
}



// Driver program
int main()
{
	// Let us create the following graph
	// 2 <-> 3
	// | |
	// 0 <-1-> 1
	int V = 4; // Number of vertices in graph
	int E = 5; // Number of edges in graph
	int graph[][MAX] = {
						{0, 1, 1, 1},
						{1, 0, 1, 1},
						{1, 1, 0, 1},
						{1, 1, 1, 0}
					};

	cout << numOfSpanningTree(graph, V);

	return 0;
}
