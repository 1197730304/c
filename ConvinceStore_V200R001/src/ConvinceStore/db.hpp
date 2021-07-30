
#include<iostream>
#include "db/sqlite3.h"
#include<string>

using namespace std;

class DataBaseSrv
{
public:
	DataBaseSrv(const std::string& db_name)
	{
		db_ = db_name;
		dbOpr_ = nullptr;
		errmsg_ = nullptr;
	}

	~DataBaseSrv()
	{
		sqlite3_close(dbOpr_);
	}

	bool connect_db()
	{
		int rc;

		rc = sqlite3_open(db_.c_str(), &dbOpr_);

		if (rc) {
			fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(dbOpr_));
			return false;
		}
		else {
			fprintf(stderr, "Opened database successfully\n");
			return true;
		}

	}
	static int callback(void* NotUsed, int argc, char** argv, char** azColName) {
		int i;
		for (i = 0; i < argc; i++) {
			printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
		}
		printf("\n");
		return 0;
	}

	bool query_sql(const std::string& sql)
	{
		int ret=sqlite3_exec(dbOpr_, sql.c_str(), callback, 0, &errmsg_);
		if (ret)
		{
			std::cout << "database query sql failed£º " << errmsg_ << std::endl;
			return false;
		}
		return true;
	}


private:
	std::string db_;
	sqlite3* dbOpr_;
	char* errmsg_;


};