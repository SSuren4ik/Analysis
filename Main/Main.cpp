#include <iostream>
#include <string>
#include "Stack.h"
#include "Queue.h"
#include "Lexema.h"

using namespace std;

int main() 
{
    string str = "( 123 -10)/ 50 *	\t	30\n";
    cout << str;
    Queue <Lexema> lex_res;
    lex_res = lex(str);
    cout <<lex_res;
    return 0;
}

/*
        Queue <int> q(5);
    for (int i = 0; i < 5; i++)
    {
        q.Push(i);
    }
    cout<< q;
*/