//#include<iostream>
//using namespace std;
//
//
//
////使用联合体
//
//union un
//{
//	int i = 1;
//	char s;
//}u1;
//
//
//int main()
//{
//	int ret = u1.s;
//	if (ret == 1)
//		cout << "小端字节序" << endl;
//	else
//		cout << "大端字节序" << endl;
//	return 0;
//}
//判断大小端字节序
//1.指针强转 &1=0x00000001  01在低位 *s取得值是低地址，如果*s==1,则小端
//void Func()
//{
//	int i = 1;
//	char* s = (char*)(&i);
//	if (*s == 1)
//		cout << "小端字节序" << endl;
//	else
//		cout << "大端字节序" << endl;
//}
//int main()
//{
//	Func();
//	return 0;
//}