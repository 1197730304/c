#include "db.hpp"

void test()
{
	string str = "select * from tb_userinfo;";
	DataBaseSrv* db;
	db= new DataBaseSrv("db_cs.db");
	int ret=db->connect_db();
	if (!ret)
	{
		std::cout << "Êý¾Ý¿âÁ¬½ÓÊ§°Ü" << std::endl;
	}
	ret=db->query_sql(str);
	if (!ret)
	{
		std::cout << "Ö´ÐÐÓï¾äÊ§°Ü£¡" << std::endl;
	}

}