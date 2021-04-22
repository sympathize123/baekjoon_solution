#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

long long solution(vector<pair<int, int>>* graph, int vn) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int index = 1;
	long long weight = 0;
	int max = 0;
	bool* selected = new bool[vn + 1];
	for (int i = 0; i < vn + 1; i++) {
		selected[i] = false;
	}
	selected[1] = true;
	vector<int> vertex; vertex.push_back(index);
	while (vertex.size() < vn) {
		for (int i = 0; i < graph[index].size(); i++) {
			if (!selected[graph[index][i].first]) {
				pair<int, int> p1 = make_pair(graph[index][i].second, graph[index][i].first);
				pq.push(p1);
			}
		}
		int vertexnotadded = 1;
		while (vertexnotadded) {
			if (selected[pq.top().second]) {
				pq.pop();
			}
			else {
				selected[pq.top().second] = true;
				index = pq.top().second;
				vertex.push_back(index);
				weight += pq.top().first;
				pq.top().first > max ? max = pq.top().first : max = max;
				pq.pop();
				vertexnotadded = 0;
			}
		}
	}
	delete[] selected;
	return weight - max;
}

int main() {

	string input;
	stringstream ss;
	int v, e;
	getline(cin, input);
	ss.str(input); ss >> v; ss >> e; ss.str(""); ss.clear();
	vector<pair<int, int>>* graph = new vector<pair<int, int>>[v + 1];
	for (int i = 0; i < e; i++) {
		getline(cin, input);
		ss.str(input);
		pair<int, int> p1;
		int firstvertex, secondvertex, weight; ss >> firstvertex; ss >> secondvertex; ss >> weight;
		p1.first = secondvertex; p1.second = weight;
		graph[firstvertex].push_back(p1);
		p1.first = firstvertex;
		graph[secondvertex].push_back(p1);
		ss.str(""); ss.clear();
	}

	cout << solution(graph, v) << endl;
	delete[] graph;
}