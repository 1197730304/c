//#include<iostream>
//using namespace std;
//
//
//
////ʹ��������
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
//		cout << "С���ֽ���" << endl;
//	else
//		cout << "����ֽ���" << endl;
//	return 0;
//}
//�жϴ�С���ֽ���
//1.ָ��ǿת &1=0x00000001  01�ڵ�λ *sȡ��ֵ�ǵ͵�ַ�����*s==1,��С��
//void Func()
//{
//	int i = 1;
//	char* s = (char*)(&i);
//	if (*s == 1)
//		cout << "С���ֽ���" << endl;
//	else
//		cout << "����ֽ���" << endl;
//}
//int main()
//{
//	Func();
//	return 0;
//}