
#include<iostream>
#include<string>
using namespace std;

int main()
{
    int tmp = 1;
    string s;
    cin >> s;
    int str[26] = { 0 };
    for (int i = 0; i < s.size(); i++)
    {
        str[s[i] - 'a']++;
    }
    for (int j = 0; j < s.size(); j++)
    {
        if (str[s[j] - 'a'] == 1)
        {
            cout << s[j];
            tmp = 2;
            break;
        }
        else
            continue;
    }
    if (tmp == 1)
    {
        cout << -1;
    }

    return 0;
}

class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int n = s.size();
        int began = 0, end = 0;
        for (i = 0; i <= n; i++)
        {
            if (s[i] == ' ' || s[i] == '\0')
            {
                for (end = i - 1; end > began; end--, began++)
                {
                    swap(s[end], s[began]);
                }
                began = i + 1;
            }

        }
        return s;
    }
};

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k)
        {
            if (s.size() - i < k)
                reverse(s.begin() + i, s.end());
            else
            {
                reverse(s.begin() + i, s.begin() + k + i);
            }
        }
        return s;
    }
};


class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26] = { 0 };
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            arr[s[i] - 'a']++;
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};