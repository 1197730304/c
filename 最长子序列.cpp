////���û������ڻ���
//
//int maxLength(vector<int>& arr) {
//	int max = 0;
//	int left, right = 0;
//	set<int> st;
//	while (right < arr.size())
//	{
//		//�������Ԫ�ز��ظ�������뵽�������ڣ����򻬶�����ǰ�������ƶ�
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