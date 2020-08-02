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

    double findValue(double m, double r, int t)
    {
        if (t == 0)
            return m;
        else
            return findValue(m, r, t - 1) * (1 + r / 100);
    }

    double total()
    {
        return findValue(money, rate, time);
    }

public:
    void set(string n, double m, double r, int t)
    {
        name = n;
        money = m;
        rate = r;
        time = t;
    }

    BankAccount(string n, double m, double r, int t)
    {
        set(n, m, r, t);
    }

    BankAccount()
    {
        set("Anonimouse", 0, 0, 0);
    }

    void show()
    {
        cout << "Deposit info:" << endl
             << "Name: " << name << endl
             << "Money: " << money << endl
             << "Rate: " << rate << endl
             << "Time: " << time << endl
             << "Total: " << total() << endl
             << endl;
        ;
    }

    BankAccount operator+(int t)
    {
        BankAccount tmp;
        tmp.set(name, money, rate, time + t);
        return tmp;
    }

    BankAccount operator+(double m)
    {
        BankAccount tmp;
        tmp.set(name, money + m, rate, time);
        return tmp;
    }

    BankAccount operator*(int r)
    {
        BankAccount tmp;
        tmp.set(name, money, rate + r, time);
        return tmp;
    }

    double operator!()
    {
        return total();
    }

    double operator-(BankAccount tmp)
    {
        return total() - !tmp;
    }
};

int main()
{
    BankAccount ivanov("Ivanov Ivan", 100, 12, 3);
    ivanov.show();

    BankAccount fellow;
    fellow = ivanov + 2;
    fellow.show();
    ((ivanov + 25.0) * 4).show();
    double diff = fellow - ivanov;
    cout << "Diff total money " << diff << endl;
    return 0;
}
