#include<iostream>
#include<string>
#include<time.h>
#include<set>
using namespace std;

//3.�������ظ���Ԫ��

//void print(int* arr,int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//
//}

//void FindComNum(int* arr, int n)
//{
//	int i = 0;
//	set<int> st;
//	int p[10000] = { 0 };
//	while (i < n)
//	{
//
//		p[arr[i]]++;
//		i++;
//	}
//	for (int j = 0; j < n; j++)
//	{
//		if (p[arr[j]] >= 2)
//			st.insert(arr[j]);
//	}
//	for (auto& e : st)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}


//int main()
//{
//	int* arr;
//	int n;
//	cin >> n;
//	arr = new int[n];
//	srand((unsigned int)time(NULL));
//	for (int i = 0; i < n; i++)
//	{
//		arr[i] = rand() % n;
//	}
//	cout << "ԭ���飺" << endl;
//	print(arr, n);
//	FindComNum(arr, n);
//	return 0;
//}


//��ά����Ĳ���
bool Find(int* arr, int rows, int cols, int number)
{
	bool find = false;
	int i = 0, j = cols - 1;
	while (i < rows && j >= 0)
	{
		if (arr[i * cols + j] == number)
		{
			find = true;
			break;
		}
		else if (arr[i * cols + j] > number)
		{
			j--;

		}
		else
		{
			i++;
		}

	}
	return find;

}

//�ո��滻��%20

void replace(string& str)
{
	string newStr;
	int i = 0;
	while (i < str.size())
	{
		if (str[i] == ' ')
		{
			newStr += "%20";
		}
		else
		{
			newStr += str[i];
		}
		i++;
	}
	newStr += '\0';
	string t = str;
	str = newStr;
	newStr = t;

}

int main()
{
	string str;
	getline(cin, str);
	replace(str);
	cout << str << endl;

	return 0;
}


