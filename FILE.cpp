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
	//cout << sizeof(A) << endl;//36���ֽ�
	ofstream fout("test.txt");
	A a;
	strcpy(a.name, "bite");
	a.id = 2020;
	//�����ַ���д
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
//	//�����ַ�������
//	//  >>getline get
//	int a;
//	string str;
//	char ch;
//	//�������л��߿ո����
//	fin >> a;
//	fin >> str;
//
//	char arr[100];
//	char arr2[100];
//	char ch;
//	//���з���Ϊ������ǣ�������
//	fin.get(ch);
//	fin.get(arr, 99);
//	fin.get(ch);
//	fin.getline(arr2, 99);
//
//	//�����ֽ�������
//	//read
//	fin.read(arr, 7);

//}
int main()
{
	test1();
	return 0;
}