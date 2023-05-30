#include <iostream>
#include <cstdlib>
using namespace std;
class MyPoint
{
public:
    // constructors
    MyPoint();
    MyPoint(int coordX, int coordY);
    MyPoint(const MyPoint& p);
    // accessor functions
    int getX() const;
    int getY() const;
    // mutator function
    void setX(int x);
    void setY(int y);
    // comparison operators
    bool operator== (const MyPoint& p) const;
    bool operator!= (const MyPoint& p) const;
    // utility functions
    int dist2sqr(const MyPoint& p) const; // 직선거리(Euclidean distance)의 제곱을 계산
    int dist1(const MyPoint& p) const;    // 직각거리(rectilinear distance)를 계산
private:
    int x, y;
};

// constructors
MyPoint::MyPoint()
    :x(0), y(0)         // set default to origin (0,0)
{
}
MyPoint::MyPoint(int coordX, int coordY)
    :x(coordX), y(coordY)
{
}
MyPoint::MyPoint(const MyPoint& p)
{
    x = p.x;
    y = p.y;
}
// accessor functions
int MyPoint::getX() const
{
    return x;
}
int MyPoint::getY() const
{
    return y;
}
// mutator functions
void MyPoint::setX(int coordX)
{
    x = coordX;
}
void MyPoint::setY(int coordY)
{
    y = coordY;
}
bool MyPoint::operator== (const MyPoint& p) const
{
    return x == p.x && y == p.y;
}
bool MyPoint::operator!= (const MyPoint& p) const
{
    return !operator==(p);
}
// 직선거리(Euclidean distance)의 제곱을 계산
int MyPoint::dist2sqr(const MyPoint& p) const
{
    return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
}
// 직각거리(rectilinear distance)를 계산
int MyPoint::dist1(const MyPoint& p) const
{
    int distanceX, distanceY;
    distanceX = abs(x - p.x);
    distanceY = abs(y - p.y);

    return distanceX + distanceY;
}

int main()
{
    int numTestCases;
    cin >> numTestCases;
    for (int i = 0; i < numTestCases; i++)
    {
        int coordX, coordY;
        cin >> coordX >> coordY;
        MyPoint p1(coordX, coordY);
        cin >> coordX >> coordY;
        MyPoint p2(coordX, coordY);
        if (p1 == p2)
            cout << "1" << " ";
        if (p1 != p2)
            cout << "0" << " ";
        cout << p1.dist2sqr(p2) << " " << p1.dist1(p2) << " ";
        coordX = p1.getX();
        coordY = p1.getY();
        MyPoint p3(p1);
        p3.setX(coordY);
        p3.setY(coordX);
        cout << p1.dist2sqr(p3) << " " << p1.dist1(p3) << endl;
    }
    return 0;
}