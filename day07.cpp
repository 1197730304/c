#include<iostream>
#include<stack>
#include<string>
using namespace std;
//
//bool chkParenthesis(string A, int n) {
//    if (n % 2 != 0)
//        return false;
//    stack<char> st;
//    if ((A[0] == '(' || A[0] == ')'))
//    {
//        st.push(A[0]);
//    }
//    
//        int i = 1;
//    while (i < A.size())
//    {
//        if (st.top() == A[i] && (A[i] == '(' || A[i] == ')'))
//        {
//            st.push(A[i]);
//        }
//        else
//        {
//            st.pop();
//        }
//        i++;
//    }
//    if (st.empty())
//    {
//        return true;
//    }
//    else
//        return false;
//}
//
//int main()
//{
//    string str;
//    cin >> str;
//    int n;
//    cin >> n;
//    cout << chkParenthesis(str, n) << endl;
//}
//
//#include<iostream>
//using namespace std;
//
//
//int main()
//{
//    int cur = 0, prev0 = 0, prev1 = 1;
//    int N;
//    long long sum;
//    cin >> N;
//    while (cur < N)
//    {
//        cur = prev0 + prev1;
//        prev0 = prev1;
//        prev1 = cur;
//    }
//    int m1 = cur - N;
//    int m2 = N - prev1;
//    int ret = m1 > m2 ? m2 : m1;
//    cout << ret << endl;
//    return 0;
//}

//bool chkParenthesis(string A, int n) {
//    if (n % 2 != 0 || A[0] == ')')
//        return false;
//    stack<char> st;
//    if (A[0] == '(')
//    {
//        st.push(A[0]);
//    }
//
//    int i = 1;
//    while (i < A.size())
//    {
//        if (st.top() == A[i] || st.empty())
//        {
//            st.push(A[i]);
//        }
//        else
//        {
//            st.pop();
//        }
//        i++;
//    }
//    if (st.empty())
//    {
//        return true;
//    }
//    else
//        return false;
//}


//#include<iostream>
//#include<string>
//#include<vector>
//
//using namespace std;
//
//bool lenth(vector<string> s, int n)
//{
//    for (int i = 1; i < n; i++)
//    {
//        if (s[i - 1].size() > s[i].size())
//            return false;
//    }
//    return true;
//}
//
//bool Comp(vector<string> s, int n)
//{
//    for (int i = 1; i < n; i++)
//    {
//        if (s[i - 1] > s[i])
//            return false;
//
//    }
//    return true;
//}
//int main()
//{
//    int n;
//    cin >> n;
//    vector<string> str(n);
//    for (int i = 0; i < n; i++)
//    {
//        cin >> str[i];
//    }
//
//   bool ret=lenth(str, n);
//   bool ret2 = Comp(str, n);
//   if (ret && ret2)
//       cout << "both" << endl;
//   else if (ret && !ret2)
//   {
//       cout << "lengths" << endl;
//   }
//   else if (!ret && ret2)
//   {
//       cout << "lexicographically" << endl;
//   }
//   else
//       cout << "none" << endl;
//
//    return 0;
//}

#include<iostream>
using namespace std;

int Minnum(int num1, int num2)
{
	int sum = 1;
	for (int i = 2; i <= num1; i++)
	{
		if (num1 % i == 0 && num2 % i == 0)
		{
			sum *= i;
			num1 /= i;
			num2 /= i;
		}
		else
			continue;
	}
	return sum * num1 * num2;
}
int main()
{
	//最小公倍数
	int m, n;
	cin >> m >> n;
	int ret = Minnum(m, n);
	cout << ret << endl;
	return 0;
}