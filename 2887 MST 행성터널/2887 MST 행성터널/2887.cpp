#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

long min1(long  a, long  b, long  c) {
	if (a <= b && a <= c)
		return a;
	else if (b <= a && b <= c)
		return b;
	else
		return c;
}

typedef struct Node {
	int xcord;
	int ycord;
	int zcord;
	vector<pair<int, int>> edge;
}node;

int solution(vector<node> graph, int vn) {
	int index = 0;
	int mincost = 0;
	bool* visited = new bool[vn];

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair< int, int>>> pq;

	vector<int> vertex;
	vertex.push_back(index);

	for (int i = 0; i < vn; i++) {
		visited[i] = false;
	}
	visited[index] = true;

	while (vertex.size() < vn) {
		for (int k = 0; k < vn; k++) {
			int weight = min1(abs(graph[index].xcord - graph[k].xcord), abs(graph[index].ycord - graph[k].ycord), abs(graph[index].zcord - graph[k].zcord));
			pair<int, int> p = make_pair(k, weight);
			if (!visited[p.first]) {
				graph[index].edge.push_back(p);
			}
			p.first = index;
			if (!visited[p.first]) {
				graph[k].edge.push_back(p);
			}
		}
		for (int i = 0; i < graph[index].edge.size(); i++) {
			if (!visited[graph[index].edge[i].first]) {
				pair< int, int> p1 = make_pair(graph[index].edge[i].second, graph[index].edge[i].first);
				pq.push(p1);
			}
		}
		int vertexisnotadded = 1;
		while (vertexisnotadded) {
			if (visited[pq.top().second]) {
				pq.pop();
			}
			else {
				index = pq.top().second;
				mincost += pq.top().first;
				vertex.push_back(index);
				visited[index] = true;
				pq.pop();
				vertexisnotadded = 0;
			}
		}
	}
	delete[] visited;
	return mincost;
}

int main() {
	string input;
	stringstream ss;
	int v;
	getline(cin, input);
	ss.str(input); ss >> v; ss.str(""); ss.clear();
	vector<node> graph;
	for (int i = 0; i < v; i++) {
		getline(cin, input);
		ss.str(input);
		node newnode;
		int xcord, ycord, zcord; ss >> xcord; ss >> ycord; ss >> zcord;
		newnode.xcord = xcord; newnode.ycord = ycord; newnode.zcord = zcord;
		graph.push_back(newnode);
		ss.str(""); ss.clear();
	}
	cout << solution(graph, v) << endl;
}