#define MAX 1000
#include<iostream>
#include<string>
using namespace std;
//设计联系人的结构体

struct person
{
	string m_Name;
	int m_Sex;//1.男生 2.女生
	int m_Age;
	string m_Tel;//电话
	string m_Ad;//住址
};
struct Addressbooks
{
	struct person personArray[MAX];//通讯录保存的联系人数组
	int m_Size;
};

//设计通讯录的结构体
void menu()
{
	cout << " -----------------------------------------" << endl;
	cout << " -----------------------------------------" << endl;
	cout << "|              通讯录管理系统             |" << endl;
	cout << "|-----------------------------------------|" << endl;
	cout << "****************1.添加联系人***************" << endl;
	cout << "****************2.显示联系人***************" << endl;
	cout << "****************3.删除联系人***************" << endl;
	cout << "****************4.查找联系人***************" << endl;
	cout << "****************5.修改联系人***************" << endl;
	cout << "****************6.清空联系人***************" << endl;
	cout << "****************0.退出通讯录***************" << endl;
}
void Addperson(Addressbooks* Abs)
{
	if (Abs->m_Size == MAX)
	{
		cout << "对不起!通讯录已满,无法添加 ";
		return;
	}
	else
	{
		//姓名
		string name;
		int sex=0;
		cout << "请输入待添加人的姓名： "<<endl;
		cin >> name;
		Abs->personArray[Abs->m_Size].m_Name = name;
		//性别
		cout << "请输入性别：(男：1  女：2 ） "<<endl;
		while (true)
		{	
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				Abs->personArray[Abs->m_Size].m_Sex = sex;
				break;
			}
			else
				cout << "对不起，输入有误，请重新输入：" << endl;
		}
		//年龄
		cout << "请输入年龄："<<endl;
		int age = 0;
		cin >> age;
		Abs->personArray[Abs->m_Size].m_Age = age;
		//电话
		string tel;
		cout << "请输入电话号码： "<<endl;
		cin >> tel;
		Abs->personArray[Abs->m_Size].m_Tel = tel;
		//地址
		
		cout << "请输入家庭住址： " << endl;
        string ad;
		cin >> ad;
		Abs->personArray[Abs->m_Size].m_Ad = ad;
	}
	Abs->m_Size++;
	cout << "添加成功!" << endl;
	system("pause");//请按任意键继续
	system("cls");//清屏操作
}	
//2.添加联系人
void showperson(Addressbooks * abs)
{
	if (abs->m_Size == 0)
	{
		cout << "对不起,没有添加的联系人" << endl;
	}
	else
	{
		for (int i = 0; i <= abs->m_Size - 1; i++)
		{
			cout << "姓名: " << abs->personArray[i].m_Name <<
				"  性别: " << (abs->personArray[i].m_Sex==1?"男":"女") <<
				"  年龄: " << abs->personArray[i].m_Age <<
				"  联系电话: " << abs->personArray[i].m_Tel <<
				"  家庭住址: " << abs->personArray[i].m_Ad << endl;
		}
	}
	system("pause");
	system("cls");
}
//检测联系人是否存在
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
//删除联系人
void deleteperson(Addressbooks* abs)
{
	cout << "请输入待删除的联系人姓名：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//进行删除操作
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//查找联系人
void Findperson(Addressbooks* abs)
{
	string name;
	cout << "请输入您要查找的联系人：" << endl;
	cin >> name;
	int ret = isExist(abs, name);
		if(ret!=-1)
		{
			cout << "您所查找的联系人信息如下：" << endl;
		cout << "姓名: " << abs->personArray[ret].m_Name <<
			"  性别: " << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") <<
			"  年龄: " << abs->personArray[ret].m_Age <<
			"  联系电话: " << abs->personArray[ret].m_Tel <<
			"  家庭住址: " << abs->personArray[ret].m_Ad << endl;
		}
		else
		{
			cout << "对不起，没有查到联系人" << endl;
		}
	
	system("pause");
	system("cls");
}
//修改联系人
void modifyperson(Addressbooks* abs)
{
	cout << "请输入您要修改的联系人姓名：" << endl;
	
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//姓名
		cout << "请输入修改的姓名：" << endl;
		string name;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		cout << endl;
		//性别
		cout << "请输入性别：" << endl;
		cout << "1----男" << endl;
		cout << "2----女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入错误！请重新输入" << endl;

		}
		//年龄
		cout << "请输入修改的年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		//电话
		cout << "请输入您要修改的电话：" << endl;
		string tel;
		cin >> tel;
		abs->personArray[ret].m_Tel = tel;
		//家庭住址
		cout << "请输入修改的家庭住址：" << endl;
		string ad;
		cin >> ad;
		abs->personArray[ret].m_Ad = ad;
		cout << "修改成功" << endl;
	}
	else
	{
		cout << "没有你输入的联系人" << endl;
	}
	system("pause");
	system("cls");
}
//清空联系人
void cleanperson(Addressbooks* abs)
{
	cout << "请谨慎操作！是否清空联系人：" << endl;
	cout << "是------1" << endl;
	cout << "否------0" << endl;
	int input = 0;
	
	while (true)
	{
		cin >> input;
		if (input == 1)
		{
			abs->m_Size = 0;//将当前的清空
			cout << "联系人已清空" << endl;
		}
		else
			cout << "已取消清空" << endl;
			break;
	}
	system("pause");
	system("cls");
}
int main()
{
	Addressbooks Abs;
	Abs.m_Size = 0;//通讯录初始化

	int input = 0;
	do
	{
		menu();
		cout << "请输入你的选择: " << endl;
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
			cout << "输入非法，请重新输入" << endl;
			cin >> input;
			break;
		}

	} while (input);

	system("pause");
	return 0;
}