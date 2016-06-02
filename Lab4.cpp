#include <iostream>

using std::cin;
using std::cout;
using std::endl;

template <typename T>
class Tree {
private:
	T* data;
	size_t n;
public:
	Tree(T* tmp, size_t number) : data(tmp), n(number) {};

	void direct(T key) const;
	void reverse(T key) const;
	void symmetric(T key) const;
};

template<typename T>
void Tree<T>::direct(T key) const {
	for (size_t i = 0; i < this->n; i++) {
		if (this->data[i] == key) {
			cout << i << ' ';
			direct(i);
		}
	}
}

template<typename T>
void Tree<T>::reverse(T key) const {
	for (size_t i = 0; i < this->n; i++) {
		if (this->data[i] == key) {
			reverse(i);
		}
	}
	if (key != -1) {
		cout << key << ' ';
	}
}

template<typename T>
void Tree<T>::symmetric(T key) const {
	size_t x = 0;
	for (size_t i = 0; i < this->n; i++) {
		if (this->data[i] == key) {
			symmetric(i);
			if ((!x) && (key != -1)) {
				cout << key << ' ';				
			}
			x++;
		}
	}
	if (x == 0) {
		cout << key << ' ';
	}
}

int main() {
	size_t n;
	cin >> n;
	int* tree = new int[n];
	for (size_t i = 0; i < n; i++) {
		cin >> tree[i];
	}

	Tree<int> t(tree, n);

	t.direct(-1);
	cout << endl;

	t.reverse(-1);
	cout << endl;

	t.symmetric(-1);
	cout << endl;

	delete[] tree;
	system("pause");
	return 0;
}
