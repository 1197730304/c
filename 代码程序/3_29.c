#include<stdio.h>
//int removeDuplicates(int* nums, int numsSize) {
//	int count = 0;
//	for (int i = 0; i < numsSize; i++)
//	{
//
//	}
//}
//int main()
//{
//	int arr[10] = { 1,1,2,2,3,4,5,6,7,7 };
//	int count = removeDuplicates(arr, 10);
//	for (int i = 0; i < count; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//1.
//void reverse(int* arr, int len)
//{
//	//翻转一次
//	int p = arr[len - 1];
//	for (int i = len-1; i >=1; i--)
//	{
//		arr[i] = arr[i - 1];
//	}
//	arr[0] = p;
//	return;
//}
//void overturn(int* arr, int len,int k)
//{
//	for (int i = 0; i < k; i++)
//	{
//		reverse(arr, len);
//	}
//	return;
//}

//2.第二种方法
void reverse(int* nums, int left, int right)
{
	while (left < right)
	{
		int t = nums[left];
		nums[left] = nums[right];
		nums[right] = t;
		left++;
		right--;
	}
}
void rotate(int* nums, int numsSize, int k) {
	k %= numsSize;
	reverse(nums, 0, numsSize - k - 1);
	reverse(nums, numsSize - k, numsSize - 1);
	reverse(nums, 0, numsSize - 1);
}
int main()
{
	int arr[7] = { 1,2,3,4,5,6,7 };
	int k = 3;
	//overturn(arr, 7, 3);
	rotate(arr, 7, 3);
	for (int i = 0; i < 7; i++)
	{
		printf("%d ", arr[i]);
	}
}

