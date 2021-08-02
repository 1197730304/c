//#include<iostream>
//#include<map>
//using namespace std;
//
//int findNum(int* p,int len)
//{
//	map<int, int> mp;
//	for (int i = 0; i < len; i++)
//	{
//		mp[p[i]]++;
//	}
//	for (int i = 0; i < len; i++)
//	{
//		if (mp[p[i]] == 1)
//		{
//			return i;
//		}
//	}
//	return -1;
//}
//int main()
//{
//	int n = 0;
//	cin >> n;
//	int* p = new int[10000];
//	//memset(p, 0, 10000);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> p[i];
//	}
//	cout << findNum(p, n) << endl;
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//
//bool isAllRepeat(string s)
//{
//	char tmp = s[0];
//	for (auto e : s)
//	{
//		if (e != tmp)
//		{
//			return false;
//		}
//	}
//	return true;
//}
//bool isRepeat(string& s)
//{
//	for (int i = 0; i < s.size()-1; i++)
//	{
//		if (s[i] == s[i + 1])
//		{
//			return true;
//		}
//	}
//	return false;
//}
//void func( string& s)
//{
//	while (isRepeat(s))
//	{
//		int i = 0;
//		char tmp = s[i];
//		int begin = i;
//		int count = 1;
//		while (i < s.size()-1)
//		{
//			if (tmp == s[i + 1])
//			{
//				count++;
//				//s.erase(i + 1,1);
//				//s.erase(i,1);
//				
//			}
//			else
//			{
//				tmp = s[i + 1];
//				
//			}
//			i++;
//		}
//		s.erase(begin, count);
//	}
//}
//int main()
//{
//	string str;
//	cin >> str;
//	if (isAllRepeat(str))
//	{
//		cout << "" << endl;
//	}
//	else
//	{
//		func(str);
//		cout <<str<< endl;
//	}
//
//	return 0;
//
//}


