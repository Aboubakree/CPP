#include <iostream>
using namespace std;

class Test
{
protected:
	int index;	
public:
	Test(int x):index(x){};
	virtual ~Test(){};
	virtual void	call() const = 0;
	virtual void			up(){index ++;};
	void			down(){index --;};
};

class A : public Test
{
public:
	A(int x):Test(x){};
	~A(){};
	void call() const {cout << "index : " << index << endl; };
	// void up(){index = 0;};
	void up(int x){index = x;};
	void up(int x, int y){index = x+y;};
	void down(){index = 1;};
};

int main()
{
	A a(5);
	Test *b = new A(-5);
	a.call();
	b->up();
	b->call();
	a.up(1);
	a.call();
	a.up(1, 2);
	a.call();
}


