class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> result;
        int tmp;
        int i = 0;
        while (i < tokens.size())
        {
            string& s = tokens[i];
            if (!("+" == s || "-" == s || "*" == s || "/" == s))
            {
                result.push(atoi(s.c_str()));
            }
            else
            {
                int right = result.top();
                result.pop();
                int left = result.top();
                result.pop();

                switch (s[0])
                {
                case '+':
                    result.push(left + right);
                    break;
                case '-':
                    result.push(left - right);
                    break;
                case '*':
                    result.push(left * right);
                    break;
                case '/':
                    result.push(left / right);
                    break;
                }

            }
            i++;
        }
        return result.top();
    }
};