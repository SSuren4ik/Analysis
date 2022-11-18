#include <iostream>
#include <string>
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main()
{
    Queue <int> q(5);
    for (int i = 0; i < 6; i++)
    {
        q.Push(i);
    }
    for (int i = 0; i < 6; i++)
    {
        cout << q.Pop() << "  ";
    }
    return 0;
}

/*
int main() {
	string str = "( 123 -10)/ 50 *	\t	30 \n";
	cout << str;
	queue <Lexema> lex_res;
	lex_res = lex(str);
	print(lex_res);
	return 0;
*/