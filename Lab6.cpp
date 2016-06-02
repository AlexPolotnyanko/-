#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Gr {
private:
	size_t num_root; 
	size_t num_n; 
	size_t num_e; 
	size_t** matrix; 
public:
	Gr(size_t num_r, size_t node_num, size_t edge_num);
	void getData(string& expression);
	void Dijkstra();
	~Gr();
};

vector<string> split(const string &s, char delim);

int main() {
	size_t num_n, num_e, num_root;
	cin >> num_n;
	cin >> num_e;
	cin >> num_root;
	Gr graph(num_root, num_n, num_e);
	string expression;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int i = 0; i < num_e; i++) {
		getline(cin, expression);
		graph.getData(expression);
	}
	graph.Dijkstra();

	system("pause");
	return 0;
}

Gr::Gr(size_t num_r, size_t node_num, size_t edge_num) {
	num_root = num_r;
	num_n = node_num;
	num_e = edge_num;
	matrix = new size_t*[num_n];

	for (int i = 0; i < num_n; i++)
		matrix[i] = new size_t[num_n];

	for (int i = 0; i < num_n; i++)
		for (int j = 0; j < num_n; j++)
			matrix[i][j] = 0;
}

void Gr::getData(string& expression) {
	vector<string> data = split(expression, ' ');
	if (data.size() != 3)
		return;
	if (stoi(data[0]) >= num_n || stoi(data[1]) >= num_n)
		return;
	matrix[stoi(data[0])][stoi(data[1])] = stoi(data[2]);
}

void Gr::Dijkstra() {
	size_t* distances = new size_t[num_n];
	bool* isVisited = new bool[num_n];

	for (int i = 0; i < num_n; i++) {
		distances[i] = SIZE_MAX;
		isVisited[i] = false;
	}

	distances[num_root] = 0;
	size_t index, u;

	for (int i = 0; i < num_n - 1; i++) {
		size_t min = SIZE_MAX;

		for (int j = 0; j < num_n; j++)
			if (!isVisited[j] && distances[j] <= min) {
				min = distances[j];
				index = j;
			}

		u = index;
		isVisited[u] = true;

		for (int j = 0; j < num_n; j++)
			if (!isVisited[j] && matrix[u][j] && distances[u] != SIZE_MAX && distances[u] + matrix[u][j] < distances[j])
				distances[j] = distances[u] + matrix[u][j];
	}

	for (int i = 0; i < num_n; i++)
		if (distances[i] != SIZE_MAX)
			cout << distances[i] << "  ";
		else
			cout << "inf  ";
	cout << endl;
}

Gr::~Gr() {
	for (int i = 0; i < num_n; i++)
		delete matrix[i];
	delete matrix;
}

vector<string> split(const string &s, char delim) {
	vector<string> elems;
	stringstream ss(s);
	string item;

	while (getline(ss, item, delim))
		elems.push_back(item);

	return elems;
}
