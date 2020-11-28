#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct A
{
	char name[30];
	int id;

};

void test1()
{
	//cout << sizeof(A) << endl;//36个字节
	ofstream fout("test.txt");
	A a;
	strcpy(a.name, "bite");
	a.id = 2020;
	//按照字符流写
	fout << a.name << endl;
	fout << a.id << endl;
	fout.close();


	ofstream fout2("test.binary.txt");
	if (!fout2.is_open())
		return;
	fout.write((char*)&a,sizeof(A));
	fout.close();

}

//void test()
//{
//	ifstream fin("test.txt");
//	//fin.open("test.txt");
//
//	if (!fin.is_open())
//	{
//		cout << "file open failed!" << endl;
//	}
//
//	//按照字符流读入
//	//  >>getline get
//	int a;
//	string str;
//	char ch;
//	//遇到换行或者空格结束
//	fin >> a;
//	fin >> str;
//
//	char arr[100];
//	char arr2[100];
//	char ch;
//	//换行符作为结束标记，不读入
//	fin.get(ch);
//	fin.get(arr, 99);
//	fin.get(ch);
//	fin.getline(arr2, 99);
//
//	//按照字节流读入
//	//read
//	fin.read(arr, 7);

//}
int main()
{
	test1();
	return 0;
}