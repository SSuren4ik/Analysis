#pragma once
#include <string>
#include <iostream>
#include "Queue.h"
#include "Stack.h"
#include <vector>
using namespace std;

enum TypeElement {
	Operation,
	Value, 
	Null
};

class Lexema {
	string str;
	TypeElement type;
public:
	Lexema(string _str = " ", TypeElement _type = Null) : str(_str), type(_type) {};
	string getStr() { return str; }
	TypeElement getType() { return type; }
	friend ostream& operator << (ostream& out, Lexema& p) {
		out << "{" << p.str << ", ";
		if (p.type == Operation) {
			out << "operation";
			}
		else if (p.type == Value) {
			out << "value";
		};
		out << "}";
		return out;
	}
};

Queue <Lexema> lex(string input) {
	Queue<Lexema>res;
	input += ' ';
	int i = 0;
	string tmp = "";
	string op = "+-*/()";
	string sep = " \n\t";
	int state = 0;
	for (i = 0; i < input.size(); i++) {
		char c = input[i];
		int fres;
		switch (state)
		{
		case 0: // операция
			if (c >= '0' && c <= '9') {
				tmp = c;
				state = 1;
				break;
			}
			fres = op.find(c);
			if (fres >= 0) {
				tmp = c;
				Lexema l(tmp, Operation);
				res.Push(l);
				state = 0;
				break;
			}
			break;
		case 1: // число
			if (c >= '0' && c <= '9') {
				tmp += c;
				state = 1;
				break;
			}
			fres = op.find(c);
			if (fres >= 0) {
				Lexema l1(tmp, Value);
				res.Push(l1);
				tmp = c;
				Lexema l2(tmp, Operation);
				res.Push(l2);
				state = 0;
				break;
			}
			fres = sep.find(c);
			if (fres >= 0) {
				Lexema l(tmp, Value);
				res.Push(l);
				state = 0;
				break;
			}
			break;
		}
	}
	return res;
};

vector <Lexema> Reverse_Polska(Queue<Lexema> & q)
{
 	vector <Lexema> res;
	int number_skobka = 0;
	int priority1;
	int priority2;
	string op = "+-/*";
	Stack<Lexema> stack;
	char c;
	for (int i = 1; i < q.Get_Size()+1; i++)
	{
		Lexema l = q.Get_Element(i);
		switch (l.getType())
		{
		case Operation:
			c = l.getStr()[0];
			switch (c)
			{
			case '(':
				stack.Push(l);
				number_skobka++;
				break;
			case '+':case '-':case'*':case'/':
				if (stack.IsEmpty())
				{
					stack.Push(l);
					break;
				}
				priority1 = op.find(c)/2;
				while (!stack.IsEmpty())
				{
					priority2 = op.find(stack.Top().getStr()) / 2;
					if (priority1 <= priority2)
					{
						res.push_back(stack.Pop());
					}
					else
					{
						stack.Push(l);
						break;
					}
				}
				break;
			case ')':
				while (true)
				{
					if (!stack.IsEmpty())
					{
						if (stack.Top().getStr() != "(")
						{
							res.push_back(stack.Pop());
						}
						else
						{
							stack.Pop();
							number_skobka--;
							break;
						}
					}
					else
					{
						throw exception("Net (");
					}

				}
			}
			break;
		case Value:
			res.push_back(l);
			break;
		}
	}
	while (stack.IsEmpty() != true)
	{
		res.push_back(stack.Pop());
	}
	if (number_skobka != 0)
	{
		throw exception("Net )");
	}
	return res;
}