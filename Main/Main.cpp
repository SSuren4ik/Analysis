#include <iostream>
#include <string>
#include "Stack.h"
#include "Queue.h"
#include "Lexema.h"

using namespace std;

int main() 
{
    string str = "(123 + 10 * 2 - 3)/ 20\n";
    cout << str;
    Queue <Lexema> lex_res;
    lex_res = lex(str);
    cout <<lex_res << endl;
    vector <Lexema> polka;
    double m;
    try
    {
        polka = Reverse_Polska(lex_res);
    }
    catch(exception ex)
    {
        cout << ex.what();
        return 0;
    }
    try
    {
        Calculate(polka);
    }
    catch (exception ex)
    {
        cout << ex.what();
        return 0;
    }

    cout << Calculate(polka);
    cout << endl<< (123.0 + 10.0 * 2.0 - 3.0)/ 20.0;
    return 0;
} 