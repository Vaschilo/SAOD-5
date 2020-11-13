#pragma once
#include <iostream>
using namespace std;

class Detail
{
private:
	string name;
	int mass;
public:
	Detail() { this->name = "Std_name"; this->mass = 0; }
	Detail(string name, int mass) { this->name = name; this->mass = mass; }
	~Detail() {}

	string GetName() { return this->name; }
	int GetMass() { return this->mass; }

	void operator = (Detail a)
	{
		this->name = a.name;
		this->mass = a.mass;
	}
	friend ostream& operator <<(ostream& out, Detail a)
	{
		out << a.name << " " << a.mass;
		return out;
	}
	friend istream& operator >>(istream& in, Detail& a)
	{
		in >> a.name >> a.mass;
		return in;
	}
};
