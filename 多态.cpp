#include<iostream>
using namespace std;


//抽象类：包含纯虚函数的类
//抽象类不能实例化，因为这个类不完整
class A
{
public:
	//final修饰的虚函数，在子类中不能再被重写
	//体现实现继承
	virtual void func() final
	{
		cout << "A::func()" << endl;
	}

	virtual void func2()
	{
		cout << "A::func2()" << endl;
	}

	//纯虚函数
	virtual void func4() = 0;
	//析构尽量写成虚函数
	virtual ~A()
	{
		cout << "~A()"<<endl;
	}
};


class B :public A
{
public:

	virtual ~B()//重写父类的析构函数，底层函数名相同
	{
		cout << "~B()" << endl;
	}
	//override：强制子类的函数必须重写父类的一个虚函数
	//体现接口继承
	virtual void func2()override
	{
		cout << "B::func2()" << endl;
	}

	//重写父类中的纯虚函数
	virtual void func4()
	{
		cout << "B::func4()" << endl;
	}
};

void test()
{
	//A* pa = new A;
	B* pb = new B;
	//delete pa;
	delete pb;
	
	//切片,有内存泄露的风险：析构不是多态，如果子类对象有资源申请
	//会导致只会调用父类的析构，子类对象的资源不会被释放
	//多态：看对象----》子类对象----->子类析构
	//父类指针或者引用执行继承体系中的对象
	A* pc = new B;
	delete pc;
}

//多态：看对象
//虚函数的行为：虚表中存放的实际地址决定
class Base
{
public:
	virtual void func1()
	{
		cout << "Base::func1()" << endl;
	}

private:

	int _b = 1;
};
int main()
{
	cout << sizeof(Base) << endl;
}