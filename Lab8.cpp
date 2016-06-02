#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Base {
protected:
	int value;
public:
	Base() : value(0) {};
	Base(int val) : value(val) {};

	int get() { return value; };
	virtual void show() = 0;
};

class A : public Base {
public:
	A() : Base() {};
	A(int val) : Base(val) {};

	void show() { cout << "class A: " << get() << endl; };
};

class B : public Base {
public:
	B() : Base() {};
	B(int val) : Base(val) {};

	void show() { cout << "class B: " << get() << endl; }
};

class C : public Base {
public:
	C() : Base() {};
	C(int val) : Base(val) {};

	void show() { cout << "class C: " << get() << endl; }
};

vector<Base*> objects;

class F {
public:
	virtual void operator()() {};
	virtual void operator()(string, int) {};
};

class FShow : public F {
public:
	FShow() {};
	void operator()();
};

class FCreate : public F {
public:
	FCreate() {};
	void operator()(string classname, int value);
};


void FCreate::operator()(string classname, int value) {
	Base* base;

	if (classname == "A")
		base = new A(value);
	else if (classname == "B")
		base = new B(value);
	else if (classname == "C")
		base = new C(value);
	else return;

	objects.push_back(base);
}

void FShow::operator()() {
	for (auto it : objects)
		it->show();
}

vector<string> split(const string &s, char delim) {
	vector<string> elems;
	stringstream ss(s);
	string item;

	while (getline(ss, item, delim))
		elems.push_back(item);

	return elems;
}
vector<string> split(const string &s, char delim);

int main() {
	map<string, F*> mfunc;
	F *fshow = new FShow;
	F *fcreate = new FCreate;
	mfunc["showall"] = fshow;
	mfunc["create"] = fcreate;
	string expression;
	vector<string> expressions;
	Functor *fctr;
	int N;
	cin >> N;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int i = 1; i <= N; i++) {
		getline(cin, expression);
		expressions = split(expression, ' ');
		fctr = mfunc[expressions[0]];

		if (fctr == nullptr) {
			cout << "wrong operation\n";
			i--; 
			continue;
		}

		if (expressions.size() == 1) {
			(*fctr)();
		}
		else if (expressions.size() == 3) {
			(*fctr)(expressions[1], stoi(expressions[2]));
		}
		else {
			cout << "wrong operation\n"; i--;
		}
	}

	system("pause");
	return 0;
}
