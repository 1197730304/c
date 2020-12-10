#include<iostream>
using namespace std;


//�����ࣺ�������麯������
//�����಻��ʵ��������Ϊ����಻����
class A
{
public:
	//final���ε��麯�����������в����ٱ���д
	//����ʵ�ּ̳�
	virtual void func() final
	{
		cout << "A::func()" << endl;
	}

	virtual void func2()
	{
		cout << "A::func2()" << endl;
	}

	//���麯��
	virtual void func4() = 0;
	//��������д���麯��
	virtual ~A()
	{
		cout << "~A()"<<endl;
	}
};


class B :public A
{
public:

	virtual ~B()//��д����������������ײ㺯������ͬ
	{
		cout << "~B()" << endl;
	}
	//override��ǿ������ĺ���������д�����һ���麯��
	//���ֽӿڼ̳�
	virtual void func2()override
	{
		cout << "B::func2()" << endl;
	}

	//��д�����еĴ��麯��
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
	
	//��Ƭ,���ڴ�й¶�ķ��գ��������Ƕ�̬����������������Դ����
	//�ᵼ��ֻ����ø��������������������Դ���ᱻ�ͷ�
	//��̬��������----���������----->��������
	//����ָ���������ִ�м̳���ϵ�еĶ���
	A* pc = new B;
	delete pc;
}

//��̬��������
//�麯������Ϊ������д�ŵ�ʵ�ʵ�ַ����
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