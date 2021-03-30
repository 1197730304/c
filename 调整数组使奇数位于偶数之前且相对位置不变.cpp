
#include<iostream>
#include<vector>
using namespace std;
vector<int> reOrderArray(vector<int>& array)
{
	int i = 0, j = array.size() - 1, k = 0;
	int num = 0, end = j;
	vector<int> ret;
	if (j == 0)
		return array;
	while (i <= j)
	{
		if (array[i] % 2 == 1)
			ret.push_back(array[i]);
		i++;
	}

	while (k<=j)
	{
		if (array[k] % 2 == 0)
			ret.push_back(array[k]);
		k++;
	}
	return ret;
}