#include <iostream>


class A
{
private:
    int x;
public:
    A(){};
    ~A(){};
    int getX() const {return x;};
    void setX(int new_x) {x = new_x;};
};


A operator+(const A& a1, const A& a2)
{
    A a;
    a.setX(a1.getX() + a2.getX());
    return a;
}

int main()
{
    A a,b,c;
    a.setX(1);
    b.setX(2);
    c = a + b;
    std::cout << c.getX() << std::endl;
    return 0;
}