#include<iostream>
using namespace std;


class Person
{
public:
	void Print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
//protected:
	string _name = "peter"; // ����
	int _age = 18; // ����
};
// �̳к����Person�ĳ�Ա����Ա����+��Ա�����������������һ���֡��������ֳ���Student��
//Teacher������Person�ĳ�Ա����������ʹ�ü��Ӵ��ڲ鿴Student��Teacher���󣬿��Կ��������ĸ��á�
//����Print���Կ�����Ա�����ĸ��á�
class Student : public Person
{
//protected:
public:

	int _stuid; // ѧ��
};
class Teacher : public Person
{
protected:
	int _jobid; // ����
};



void test()
{
	int a = 2.5;

	Person p;

	Student s;
	
	//��Ƭ��
	//����---������
	p = s;
	Person* ptr = &s;
	Person& ref = s;

	//���಻��ת��Ϊ�������
	//s = p;
	//s = (Student)p;

	//���಻��ת��Ϊ�����ָ�������
	//����ͨ��ǿ������ת��������ȫ
	//Student* ptr2 = &p;

	//ǿ������ת������ȫ�����ʲ��������������ĳ�Ա
	Student* ptr2 = (Student*)&p;
	//Student* ref2 = &p;
	Student& ref2 = (Student&)p;

	//Խ�����
	
	
}
#define sqr(A) A*A

//
//void main()
//{
//	int x = 6, y = 3, z = 2;
//	x /= sqr(y + z) / sqr(y + z);
//	cout << x << endl;
//}


#include<string>
#include<math.h>
//string tobinary(int n)
//{
//	string ret;
//	while (n != 0)
//	{
//		ret += (n % 2);
//		n /= 2;
//	}
//	return ret;
//}
//int binInsert(int n, int m, int j, int i) {
//	string sn = tobinary(n);
//	string sm = tobinary(m);
//	int len = i - j + 1;
//	while (sm.size() != len)
//	{
//		sm.insert(sm.begin(), '0');
//		
//	}
//	sn.insert(sm.(begin()+j - 1), sm);
//	int count = 0;
//	long long sum = 0;
//	for (int k = sn.size() - 1; i >= 0; i--)
//	{
//		int ret = pow(2, count);
//		sum += (ret * (sn[i] - '0'));
//	}
//	return sum;
//}


string tobinary(int n)
{
	string ret;
	while (n != 0)
	{
		ret += (n % 2);
		n /= 2;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}
int binInsert(int n, int m, int j, int i) {
	string sn = tobinary(n);
	string sm = tobinary(m);
	int len = i - j + 1;
	while (sm.size() != len)
	{
		sm.insert(sm.begin(), '0');
	}
	string tmp(sn.begin(), sn.begin() + j - 1);
	string tmp2(sn.begin() + j, sn.end());
	tmp += sm;
	tmp += tmp2;
	sn = tmp;
	int count = 0;
	long long sum = 0;
	for (int k = sn.size() - 1; i >= 0; i--)
	{
		int ret = pow(2, count);
		sum += (ret * (sn[i] - '0'));
		count++;
	}
	return sum;
}

//int main()
//{
//	int ret = binInsert(1024, 19, 2, 6);
//	cout << ret << endl;
//	return 0;
//}


#include<iostream>
#include<vector>
using namespace std;

bool issushu(int n)
{
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}
vector<int> binnum(int n)
{
	vector<int> arr;
	int flag = 0;

	int i = n;
	while (flag == 0)
	{
		if (issushu(i))
		{
			flag = 1;
			arr.push_back(i);
			break;
		}
		i--;
	}
	flag = 0;
	i = n;
	while (flag == 0)
	{
		if (issushu(i * 2 - arr[0]))
		{
			flag = 1;
			arr.push_back(2 * n - arr[0]);
			break;
		}
		i++;
	}


	return arr;

}
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		vector<int> p = binnum(n / 2);
//		cout << p[0] << endl;
//		cout << p[1] << endl;
//	}
//
//
//	return 0;
//}

//int main()
//{
//	int i = 0, a = 1, b = 2, c = 3;
//	i = ++a || ++b || ++c;
//	cout << i << " " << a << " " << b << " " << c << endl;
//	return 0;
//}
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	string str;
//	getline(cin, str);
//	int i = 0;
//	int count = 0;
//	vector<string> ret;
//	string tmp;
//	while (i < str.size())
//	{
//		while (i < str.size() && str[i] != ' ')
//		{
//
//			tmp += str[i];
//
//			i++;
//		}
//		ret.push_back(tmp);
//		tmp.clear();
//		count++;
//		i++;
//
//	}
//	cout << count << endl;
//	for (int i = 0; i < ret.size(); i++)
//	{
//		cout << ret[i] << endl;
//	}
//	return 0;
//}
