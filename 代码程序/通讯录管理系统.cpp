#define MAX 1000
#include<iostream>
#include<string>
using namespace std;
//�����ϵ�˵Ľṹ��

struct person
{
	string m_Name;
	int m_Sex;//1.���� 2.Ů��
	int m_Age;
	string m_Tel;//�绰
	string m_Ad;//סַ
};
struct Addressbooks
{
	struct person personArray[MAX];//ͨѶ¼�������ϵ������
	int m_Size;
};

//���ͨѶ¼�Ľṹ��
void menu()
{
	cout << " -----------------------------------------" << endl;
	cout << " -----------------------------------------" << endl;
	cout << "|              ͨѶ¼����ϵͳ             |" << endl;
	cout << "|-----------------------------------------|" << endl;
	cout << "****************1.�����ϵ��***************" << endl;
	cout << "****************2.��ʾ��ϵ��***************" << endl;
	cout << "****************3.ɾ����ϵ��***************" << endl;
	cout << "****************4.������ϵ��***************" << endl;
	cout << "****************5.�޸���ϵ��***************" << endl;
	cout << "****************6.�����ϵ��***************" << endl;
	cout << "****************0.�˳�ͨѶ¼***************" << endl;
}
void Addperson(Addressbooks* Abs)
{
	if (Abs->m_Size == MAX)
	{
		cout << "�Բ���!ͨѶ¼����,�޷���� ";
		return;
	}
	else
	{
		//����
		string name;
		int sex=0;
		cout << "�����������˵������� "<<endl;
		cin >> name;
		Abs->personArray[Abs->m_Size].m_Name = name;
		//�Ա�
		cout << "�������Ա�(�У�1  Ů��2 �� "<<endl;
		while (true)
		{	
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				Abs->personArray[Abs->m_Size].m_Sex = sex;
				break;
			}
			else
				cout << "�Բ��������������������룺" << endl;
		}
		//����
		cout << "���������䣺"<<endl;
		int age = 0;
		cin >> age;
		Abs->personArray[Abs->m_Size].m_Age = age;
		//�绰
		string tel;
		cout << "������绰���룺 "<<endl;
		cin >> tel;
		Abs->personArray[Abs->m_Size].m_Tel = tel;
		//��ַ
		
		cout << "�������ͥסַ�� " << endl;
        string ad;
		cin >> ad;
		Abs->personArray[Abs->m_Size].m_Ad = ad;
	}
	Abs->m_Size++;
	cout << "��ӳɹ�!" << endl;
	system("pause");//�밴���������
	system("cls");//��������
}	
//2.�����ϵ��
void showperson(Addressbooks * abs)
{
	if (abs->m_Size == 0)
	{
		cout << "�Բ���,û����ӵ���ϵ��" << endl;
	}
	else
	{
		for (int i = 0; i <= abs->m_Size - 1; i++)
		{
			cout << "����: " << abs->personArray[i].m_Name <<
				"  �Ա�: " << (abs->personArray[i].m_Sex==1?"��":"Ů") <<
				"  ����: " << abs->personArray[i].m_Age <<
				"  ��ϵ�绰: " << abs->personArray[i].m_Tel <<
				"  ��ͥסַ: " << abs->personArray[i].m_Ad << endl;
		}
	}
	system("pause");
	system("cls");
}
//�����ϵ���Ƿ����
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
			break;
		}
			
	}
	return -1;
}
//ɾ����ϵ��
void deleteperson(Addressbooks* abs)
{
	cout << "�������ɾ������ϵ��������" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//����ɾ������
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//������ϵ��
void Findperson(Addressbooks* abs)
{
	string name;
	cout << "��������Ҫ���ҵ���ϵ�ˣ�" << endl;
	cin >> name;
	int ret = isExist(abs, name);
		if(ret!=-1)
		{
			cout << "�������ҵ���ϵ����Ϣ���£�" << endl;
		cout << "����: " << abs->personArray[ret].m_Name <<
			"  �Ա�: " << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") <<
			"  ����: " << abs->personArray[ret].m_Age <<
			"  ��ϵ�绰: " << abs->personArray[ret].m_Tel <<
			"  ��ͥסַ: " << abs->personArray[ret].m_Ad << endl;
		}
		else
		{
			cout << "�Բ���û�в鵽��ϵ��" << endl;
		}
	
	system("pause");
	system("cls");
}
//�޸���ϵ��
void modifyperson(Addressbooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ��������" << endl;
	
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//����
		cout << "�������޸ĵ�������" << endl;
		string name;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		cout << endl;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1----��" << endl;
		cout << "2----Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "�����������������" << endl;

		}
		//����
		cout << "�������޸ĵ����䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		//�绰
		cout << "��������Ҫ�޸ĵĵ绰��" << endl;
		string tel;
		cin >> tel;
		abs->personArray[ret].m_Tel = tel;
		//��ͥסַ
		cout << "�������޸ĵļ�ͥסַ��" << endl;
		string ad;
		cin >> ad;
		abs->personArray[ret].m_Ad = ad;
		cout << "�޸ĳɹ�" << endl;
	}
	else
	{
		cout << "û�����������ϵ��" << endl;
	}
	system("pause");
	system("cls");
}
//�����ϵ��
void cleanperson(Addressbooks* abs)
{
	cout << "������������Ƿ������ϵ�ˣ�" << endl;
	cout << "��------1" << endl;
	cout << "��------0" << endl;
	int input = 0;
	
	while (true)
	{
		cin >> input;
		if (input == 1)
		{
			abs->m_Size = 0;//����ǰ�����
			cout << "��ϵ�������" << endl;
		}
		else
			cout << "��ȡ�����" << endl;
			break;
	}
	system("pause");
	system("cls");
}
int main()
{
	Addressbooks Abs;
	Abs.m_Size = 0;//ͨѶ¼��ʼ��

	int input = 0;
	do
	{
		menu();
		cout << "���������ѡ��: " << endl;
		cin >> input;
		cout << endl;
		switch (input)
		{
		case 1:
			Addperson(&Abs);
			break;
		case 2:
			showperson(&Abs);
			break;
		case 3:
			deleteperson(&Abs);
			break;
		case 4:
			Findperson(&Abs);
			break;
		case 5:
			modifyperson(&Abs);
			break;
		case 6:
			cleanperson(&Abs);
			break;
		case 0:
			break;
		default:
			cout << "����Ƿ�������������" << endl;
			cin >> input;
			break;
		}

	} while (input);

	system("pause");
	return 0;
}