#include<iostream>
using namespace std;
int getDigitSum(int num)
{
	int sum = 0;
	while (num)
	{
		sum += num % 10;
		num /= 10;
	}
	return sum;
}
bool check(int key, int rows, int cols, int row, int col, bool* visited)
{
	if (row >= 0 && row < rows && col >= 0 && col < cols && getDigitSum(row) + getDigitSum(col) <= key && !visited[row * cols + col])
		return true;
	return false;
}
int movingCountCore(int key, int rows, int cols, int row, int col, bool* visited)
{
	int count = 0;
	if (check(key, rows, cols, row, col, visited))
	{
		visited[row * cols + col] = true;
		count = 1 + movingCountCore(key, rows, cols, row + 1, col, visited)
			+ movingCountCore(key, rows, cols, row, col + 1, visited)
			+ movingCountCore(key, rows, cols, row - 1, col, visited)
			+ movingCountCore(key, rows, cols, row, col - 1, visited);
		
	}
	return count;
}
int movingCount(int key, int rows, int cols)
{
	if (key < 0 || rows <= 0 || cols <= 0)
		return 0;
	bool* visited = new bool[rows * cols];
	memset(visited, false, rows * cols);
	int count = movingCountCore(key, rows, cols, 0, 0, visited);

	delete[] visited;

	return count;
}
int main()
{

	return 0;
}