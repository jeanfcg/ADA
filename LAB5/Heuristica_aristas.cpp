#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>


using namespace std;

struct City {
	int x;
	int y;
};	

struct Edge {
	int city1;
	int city2;
	double distance;
};

bool sortByDistance(const Edge& edge1, const Edge& edge2) {
	return edge1.distance < edge2.distance;
}

double distance(const City& city1, const City& city2) {
	int x_diff = city1.x - city2.x;
	int y_diff = city1.y - city2.y;
	return sqrt(x_diff * x_diff + y_diff * y_diff);
}

int find(int city, vector<int>& parent) {
	if (parent[city] == city)
		return city;
	return find(parent[city], parent);
}

void unite(int city1, int city2, vector<int>& parent) {
	int root1 = find(city1, parent);
	int root2 = find(city2, parent);
	parent[root2] = root1;
}

vector<int> tspEdges(const vector<City>& cities) {
	int numCities = cities.size();
	vector<Edge> edges;
	vector<int> parent(numCities);
	vector<int> path(numCities);
	
	for (int i=0; i<numCities; ++i) {
		parent[i]=i;
		for (int j=i+1; j<numCities; ++j) {
			double dist=distance(cities[i], cities[j]);
			edges.push_back({ i, j, dist });
		}
	}
	sort(edges.begin(), edges.end(), sortByDistance);
	
	int count=0;
	for (const auto& edge : edges) {
		if (find(edge.city1, parent) != find(edge.city2, parent)) {
			unite(edge.city1, edge.city2, parent);
			path[count] = edge.city1;
			count++;
		}
	}
	
	path[count] = edges.back().city2;
	
	return path;
}

int main() {
	vector<City> cities = { {0, 0}, {1, 2}, {3, 4}, {5, 6} };
	vector<int> path = tspEdges(cities);
	
	cout << "el camino optimo es: ";
	for (int i=0; i<path.size(); ++i) {
		cout << path[i] << " ";
	} cout << endl;
	
	return 0;
}
