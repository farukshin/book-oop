#include <iostream>
#include <cmath>
using namespace std;

class Point2D
{
private:
public:
    double x, y;
    void set(double a, double b)
    {
        x = a;
        y = b;
    }

    void show()
    {
        cout << "Point 2D <" << x << ", " << y << ">" << endl;
    }
    double dist()
    {
        return sqrt(x * x + y * y);
    }
    void getInfo()
    {
        show();
        cout << "D to <0, 0> " << dist() << endl
             << endl;
    }
};

class Point3D : public Point2D
{
public:
    double z;
    double dist()
    {
        return sqrt(x * x + y * y + z * z);
    }
    void show()
    {
        cout << "Point 3D <" << x << ", " << y << ", " << z << ">" << endl;
    }
    void getInfo()
    {
        show();
        cout << "D to <0, 0, 0> " << dist() << endl
             << endl;
    }
};

int main()
{
    Point2D p1;
    p1.set(1, 1);
    p1.getInfo();

    Point3D p2;
    p2.set(2, 2);
    p2.z = 5;
    p2.getInfo();

    return 0;
}
