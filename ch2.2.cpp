#include <iostream>
using namespace std;

void show()
{
    cout << "Функция show() без аргументов" << endl;
}

void show(string txt)
{
    cout << "Функция show(): " << txt << endl;
}

int main()
{
    show();
    show("параметр1");
    return 0;
}
