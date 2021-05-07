////利用滑动窗口机制
//
//int maxLength(vector<int>& arr) {
//	int max = 0;
//	int left, right = 0;
//	set<int> st;
//	while (right < arr.size())
//	{
//		//如果最后的元素不重复，则插入到滑动窗口，否则滑动窗口前面向右移动
//		if (!st.count(arr[right]))
//			st.insert(arr[right++]);
//		else {
//			st.erase(arr[left++]);
//		}
//		max = max > st.size() ? max : st.size();
//	}
//	return max;
//
//
//
//}