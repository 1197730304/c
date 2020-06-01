#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
using namespace std;

class Date
{
public:
	Date(int year=2010)
		:_year(year)
	{}
private:
	int _year;
};


void test()
{
	//malloc 只进行空间申请，不初始化
	int* ptr = (int*)malloc(sizeof(int));
	*ptr = 4;
	//calloc 空间申请+0初始化
	int* ptr2 = (int*)calloc(1, sizeof(int));
	//realloc:第一个参数为nuller,等效于malloc
	int* ptr3 = (int*)realloc(nullptr, sizeof(int));
	//原地调整大小
	int* ptr4 = (int*)realloc(ptr, sizeof(int) * 4);
	//重新开空间
	int* ptr5 = (int*)realloc(ptr2, sizeof(char));
	free(ptr3);
	free(ptr4);
	free(ptr5);
	//二次释放
	//free(ptr);
}

void test2()
{
	Date* pd1 = new Date(2020);
	Date* pd2 = new Date(2030);
	Date* pd3 = new Date[10];

	delete pd1;
	delete pd2;
	delete[] pd3;
}

void Swap(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}

template<class T1, class T2>
T2 add(T1& left,T2& right)
{
	return left + right;
}

void test3()
{
	string str;
	string str2("123");
	string str3 = "abc";
	string str4("0123456789", 5);
	string str5(str3);
	string str6(str4, 2, 5);
	string str7(10, 'b');
}

//迭代器
void test4()
{
	string str("0123456789");
	string::iterator it = str.begin();
	while (it != str.end())
	{
		cout << *it << " ";;
		++it;
	}
	cout << endl;

	vector<int> vet = {0,1,2,3,4,5,6,7,8,9 };
	vector<int>::iterator vit = vet.begin();
	while (vit != vet.end())
	{
		cout << *vit << " ";;
		++vit;
	}
	cout << endl;
}

//反向迭代器

void test5()
{
	string str("0123456789");
	string::reverse_iterator rit = str.rbegin();
	while (rit != str.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;
}

void test6()
{
	string str("0123456789");
	int ret = str.size();
	cout << "size" << " :" << ret<<endl;	
	ret = str.length();
	ret = str.capacity();
	cout << "length" << " :" << ret << endl;
	cout << "capacity" << " :" << ret << endl;
	size_t max_size = str.max_size();

	str.clear();
	 ret = str.size();
	cout << "size" << " :" << ret << endl;
	ret = str.length();
	cout << "length" << " :" << ret << endl;
	ret = str.capacity();
	cout << "capacity" << " :" << ret << endl;
}

void test7()
{
	string s;
	cout << s.capacity() << endl;
	int cap = s.capacity();
	for (int i = 0; i < 200; i++)
	{
		s.push_back(i);
		if (cap != s.capacity())
		{
			cap = s.capacity();
			cout << cap << endl;
		}
	}
}

void test8()
{
	string str("0123456789");
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i]<<" ";
	}
	cout << endl;
	for (int i = 0; i < str.size(); i++)
	{
		cout << str.operator[](i) << " ";
	}
	cout << endl;
	cout << string(str, 2, 5) << endl;
	cout << str[2] << endl;
}
int main()
{
	//test();
	//test2();
	/*char p1 = 'a';
	char p2='c';
	int p3 = 20;
	int p4 = 2;
	cout << add(p1, p3) << endl;*/
	//test4();
 //   test5();
	//test6();
	//test7();
	test8();
	return 0;
}
