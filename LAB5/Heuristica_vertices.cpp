#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

using namespace std;

struct City {
	int x;
	int y;
};

double distance(const City& city1, const City& city2) {
	int x_diff = city1.x - city2.x;
	int y_diff = city1.y - city2.y;
	return sqrt(x_diff * x_diff + y_diff * y_diff);
}

int findNearestCity(const vector<City>& cities, vector<bool>& visited, int currentCity) {
	int nearestCity = -1;
	double minDistance = std::numeric_limits<double>::max();
	
	for (int i=0; i<cities.size(); ++i) {
		if (i!=currentCity && !visited[i]) {
			double dist = distance(cities[currentCity], cities[i]);
			if (dist<minDistance) {
				minDistance=dist;
				nearestCity=i;
			}
		}
	}
	return nearestCity;
}

vector<int> tspVertices(const vector<City>& cities) {
	int numCities = cities.size();
	vector<bool> visited(numCities, false);
	vector<int> path(numCities);
	int currentCity = 0;
	visited[currentCity] = true;
	path[0] = currentCity;
	
	for (int i=1; i<numCities; ++i) {
		int nearestCity = findNearestCity(cities, visited, currentCity);
		visited[nearestCity] = true;
		path[i] = nearestCity;
		currentCity = nearestCity;
	}
	
	return path;
}

int main() {
	vector<City> cities = { {0, 0}, {1, 2}, {3, 4}, {5, 6} };
	vector<int> path = tspVertices(cities);
	cout<<"el camino optimo es: ";
	for (int i=0; i<path.size(); ++i) {
		cout<<path[i]<<" ";
	} cout<<endl;
	
	return 0;
}
