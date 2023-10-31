#include <catch.hpp>
#include <iostream>
#include <sstream>

using namespace std;

class Base {
public:
	virtual string fun()
	{
		return "Hello from Base";
	}
};

class Engine {
public:
	virtual ~Engine() {};
	virtual string start() = 0;
};

class GasEngine : public Engine {
public:
	string start() override
	{
		return "GasEngine::start";
	}
};

class Derived: public Base {
public:
	~Derived(){}
	string fun() override
	{
		return "Hello from Derived.fun";
	}
	unique_ptr<Engine> engine{new GasEngine};
};

using UPtrEngine = unique_ptr<Engine>;

string run(Engine* engine)
{
	return engine->start();
}

TEST_CASE("1")
{
	using PtrBase = unique_ptr<Base>;
	PtrBase p{ new Derived };
	p.get()->fun();
	Derived d;
	REQUIRE(run(d.engine.get()) == "GasEngine::start");
}

// single linked list<int>
// add
// print

template<typename T>
class List {
public:
	List(){}
	~List()
	{
		Node* node = head;
		while (node != nullptr) {
			Node* next = node->next;
			delete node;
			node = next;
		}
	}
	void add(const T& val)
	{
		if (head == nullptr) {
			head = new Node(val);
			tail = head;
		}
		else {
			Node* node = new Node(val);
			tail->next = node;
			tail = node;
		}
	}
	void print()
	{
		Node* node = head;
		while (node != nullptr) {
			cout << node->value << ", ";
			node = node->next;
		}
		cout << endl;
	}
	string to_string()
	{
		stringstream ss;
		Node* node = head;
		while (node != nullptr) {
			ss << node->value << ",";
			node = node->next;
		}
		string res = ss.str();
		if (!res.empty())
			res.pop_back();
		return res;
	}
private:
	class Node {
	public:
		Node(const T& val) : value(val) {};
		T value;
		Node* next{ nullptr };
	};
	Node* head{ nullptr };
	Node* tail{ nullptr };
};

TEST_CASE("List")
{
	List<int> l;
	l.add(1);
	l.add(2);
	REQUIRE(l.to_string() == "1,2");
}