#pragma once
#include "Detail.h"

class Node
{
private:
	Detail data;
public:
	Node* left;
	Node* rigth;
	Node() { this->left = nullptr; this->rigth = nullptr; }
	Node(Detail data) { this->left = nullptr; this->rigth = nullptr; this->data = data; }
	~Node() {}

	Detail GetData() { return this->data; }
	void SetData(Detail a) { this->data = a; }

	int sum() 
	{ 
		int sum = this->data.GetMass();
		if (this->left != nullptr) sum += this->left->sum();
		if (this->rigth != nullptr) sum += this->rigth->sum();
		return sum;
	}

	void print(int a)
	{
		for (int i = 0; i < a; i++) cout << "|";
		cout << data << endl;
		if (this->left != nullptr)this->left->print(a + 1); else { for (int i = 0; i < a + 1; i++) cout << "|"; cout << "NULL" << endl; }
		if (this->rigth != nullptr)this->rigth->print(a + 1); else { for (int i = 0; i < a + 1; i++) cout << "|"; cout << "NULL" << endl; }
	}
};

class Tree
{
private:
	Node* root;
	int size;

	void funk(int i, Node* current, int this_num, Detail data)
	{
		int buff = i;
		if (data.GetMass() > current->GetData().GetMass())
		{
			Detail temp(current->GetData().GetName(), current->GetData().GetMass());
			current->SetData(data);
			data = temp;
		}
		while (!(i == this_num * 2 || i == this_num * 2 + 1))
		{
			i /= 2;
		}
		if (i == this_num * 2)
		{
			if (current->left == nullptr) current->left = new Node(data);
			else funk(buff, current->left, this_num * 2, data);
		}
		else
		{
			if (current->rigth == nullptr) current->rigth = new Node(data);
			else funk(buff, current->rigth, this_num * 2 + 1, data);
		}
	};
	void clear_recurse(Node* current)
	{
		if (current == nullptr) return;
 		if (current->left != nullptr) { clear_recurse(current->left); delete current->left; }
		if (current->rigth != nullptr) { clear_recurse(current->rigth); delete current->rigth; }
	}

public:
	Tree() { this->root = nullptr; this->size = 0; }
	~Tree() { this->clear(); }
	void clear()
	{
		clear_recurse(this->root);
		delete this->root;
		this->root = nullptr;
		this->size = 0;
	}
	void push(Detail alfa)
	{
		++this->size;
		if (this->root == nullptr)
		{
			this->root = new Node(alfa);
			return;
		}
		this->funk(this->size, this->root, 1, alfa);
	}

	int sum() 
	{
		if (this->root == nullptr) return 0;
		return this->root->sum();
	}
	void print() 
	{
		if (this->root == nullptr) return;
		this->root->print(0);
	}
};