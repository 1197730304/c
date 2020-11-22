#include<iostream>
#include<string>

using namespace std;

class CMyString
{
public:
	CMyString(char* pData = nullptr);
	CMyString(const CMyString& str);
	~CMyString(void);


private:
	char* m_pData;

};
	CMyString& CMyString::operator=(const CMyString &str)
	{
		if (&str == this)
		{
			return *this;
		}
		delete[] m_pData;
		m_pData = nullptr;

		m_pData = new char[strlen(str.m_pData) + 1];
		strcpy(m_pData, str.m_pData);

		return *this;

	}

	CMyString& CMyString::operator=(const CMyString& str)
	{
		if (this != &str)
		{
			CMyString strTemp(str);
			char* temp = strTemp.m_pData;
			strTemp.m_pData = m_pData;
			m_pData = temp;
		}
		return *this;
	}