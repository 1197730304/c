#include "db.hpp"

void test()
{
	string str = "select * from tb_userinfo;";
	DataBaseSrv* db;
	db= new DataBaseSrv("db_cs.db");
	int ret=db->connect_db();
	if (!ret)
	{
		std::cout << "���ݿ�����ʧ��" << std::endl;
	}
	ret=db->query_sql(str);
	if (!ret)
	{
		std::cout << "ִ�����ʧ�ܣ�" << std::endl;
	}

}