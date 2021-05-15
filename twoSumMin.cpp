//class Solution {
//public:
//    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
//        vector<int> ret;
//        if (array.size() == 0 || array.size() == 1)
//            return ret;
//        int i = 0, j = array.size() - 1;
//        int s = 0;
//        while (i < j)
//        {
//
//            s = array[i] + array[j];
//            if (s == sum)
//            {
//                ret.push_back(array[i]);
//                ret.push_back(array[j]);
//                break;
//            }
//            else if (s < sum) {
//                i++;
//            }
//            else {
//                j--;
//            }
//        }
//        return ret;
//    }
//};