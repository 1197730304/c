//class Solution {
//public:
//    string LeftRotateString(string str, int n) {
//        if (str.size() == 0)
//            return "";
//        if (n == 0)
//            return str;
//        int tp = n % str.size();
//        if (tp == 0)
//            return str;
//        reverse(str.begin(), str.begin() + tp);
//        reverse(str.begin() + tp, str.end());
//        reverse(str.begin(), str.end());
//
//        return str;
//    }
//};