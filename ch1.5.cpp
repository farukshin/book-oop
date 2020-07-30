#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    string name;
    double money;
    double rate;
    int time;

public:
    void set(double m = 100, double r = 13, int t = 3)
    {
        money = m;
        rate = r;
        time = t;
    }

    void setName(string s)
    {
        name = s;
    }

    double result()
    {
        double ans = money;
        for (int i = 0; i < time; i++)
            ans *= (1 + rate / 100);
        return ans;
    }

    void show()
    {
        cout << name << ": " << money << ": " << rate << ": " << time << ": " << result() << endl;
    }

    BankAccount(string name)
    {
        setName(name);
        set();
        show();
    }

    BankAccount(string name, double m, double r, int t)
    {
        setName(name);
        set(m, r, t);
        show();
    }
};

int main()
{
    BankAccount ivanov("Ivanov Ivan");
    BankAccount petrov("Petrov Petr", 90, 18, 4);
    return 0;
}
