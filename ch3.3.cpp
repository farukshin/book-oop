#include <iostream>
#include <cmath>
using namespace std;

class Point2D
{
private:
public:
    double x, y;

    Point2D(double a, double b)
    {
        x = a;
        y = b;
        show();
    }

    Point2D(double a)
    {
        x = a;
        y = a;
        show();
    }

    Point2D()
    {
        x = 0;
        y = 0;
        show();
    }

    virtual void show()
    {
        cout << "Point 2D <" << x << ", " << y << ">" << endl;
    }
};

class Point3D : public Point2D
{
public:
    double z;

    Point3D(double a, double b, double c) : Point2D(a, b)
    {
        z = c;
        show();
    }

    Point3D(double a) : Point2D(a)
    {
        z = a;
        show();
    }

    Point3D() : Point2D()
    {
        z = 0;
        show();
    }
    Point3D(Point2D obj)
    {
        x = obj.x;
        y = obj.y;
        z = 0;
        show();
    }
    void show()
    {
        cout << "Point 3D <" << x << ", " << y << ", " << z << ">" << endl;
    }
};

int main()
{
    Point2D p1;

    Point2D p2(1);
    Point2D p3(2, 2);

    Point3D p4;
    Point3D p5(3);
    Point3D p6(4, 4, 4);
    Point3D p7(p3);

    return 0;
}
