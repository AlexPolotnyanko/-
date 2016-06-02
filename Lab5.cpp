#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class BinTree {
private:
	vector<int> data;
public:
	void	add(int value);
	void	del();
	void	orderT(int i);
	int		get() const { return data[0]; };
	void	show() const;
};

void BinTree::add(int value) {
	data.push_back(value);
	int i = data.size() - 1;
	int parent = (i - 1)/2;

	while (i > 0 && data[parent] > data[i]) {
		int temp = data[i];
		data[i] = data[parent];
		data[parent] = temp;
		i = parent;
		parent = (i - 1) / 2;
	}
}

void BinTree::del() {
	if (data.size() == 0) {
		throw std::logic_error("empty tree");
	}
	int result = data[0];
	data[0] = data[data.size() - 1];
	data.erase(data.begin() + data.size() - 1);

	for (int i = data.size() / 2; i >= 0; i--) {
		orderT(i);
	}
}

void BinTree::show() const {
	for (int i = 0; i < data.size(); i++) {
		cout << data[i] << "  ";
	}
}

vector<string> &split(const string &s, char delim, vector<string> &elems) {
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

vector<string> split(const string &s, char delim) {
	vector<string> elems;
	split(s, delim, elems);
	return elems;
}

void BinTree::orderT(int i) {
	int leftChild;
	int rightChild;
	int lastChild;

	while (true) {
		leftChild = 2*i + 1;
		rightChild = 2*i + 2;
		lastChild = i;

		if ((leftChild < data.size()) && (data[leftChild] < data[lastChild])) {
			lastChild = leftChild;
		}
		if ((rightChild < data.size()) && (data[rightChild] < data[lastChild])) {
			lastChild = rightChild;
		}
		if (lastChild == i) {
			break;
		}
		int temp = data[i];
		data[i] = data[lastChild];
		data[lastChild] = temp;
		i = lastChild;
	}
}

int main(int argc, char* argv[]) {
	BinTree tree;
	string com;
	vector<string> coms;
	int N;
	int i = 0;
	int size;
	cin >> N;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while (i < N && i >= 0) {
		getline(cin, com);
		coms = split(com, ' ');
		size = coms.size();
		if (size == 0) {
			cout << "wrong command\n";
			i--;
		}
		else if (size == 2) {
			if (coms[0] == "add")
				tree.add(stoi(coms[1]));
			else {
				cout << "wrong command\n";
				i--;
			}
		}
		else if (size == 1) {
			try {
				if (coms[0] == "del")
					tree.del();
				else if (coms[0] == "get")
					cout << tree.get() << endl;
				else if (coms[0] == "show") {
					tree.show();
					cout << endl;
				}
				else {
					cout << "wrong command\n";
					i--;
				}
			}
			catch (char* mes) {
				cout << mes << endl;
			}
		}
		else {
			cout << "wrong command\n";
			i--;
		}
		i++;
	}
	system("pause");
	return 0;
}
