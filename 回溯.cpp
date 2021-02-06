#include<iostream>
using namespace std;

//矩阵中的路径问题
bool hashPathCore(char* matrix, int rows, int cols, int row,int col, const char* str, int& pathLength, bool* visited)
{
	if (str[pathLength] == '\0')
		return true;
	bool hasPath = false;
	if (row >= 0 && row < rows && col >= 0 && col < cols && matrix[row * cols + col] == str[pathLength] && !visited[row * cols + col])
	{
		pathLength++;
		visited[row * cols + col] = true;
		hasPath = hashPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited)
			|| hashPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited)
			|| hashPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited)
			|| hashPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited);
		if (!hasPath)
		{
			--pathLength;
			visited[row * cols + col] = false;
		}
	}
	return hasPath;
}
bool hasPath(char* matrix, int rows, int cols, char* str)
{
	if (matrix == nullptr || rows < 0 || cols < 0 || str == nullptr)
		return false;
	//创建一个visit数组保存访问的状态
	bool* visited = new bool[rows * cols];
	memset(visited, 0, rows * cols);
	int pathLength = 0;
	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			if (hashPathCore(matrix, rows, cols, row, col, str, pathLength, visited))
			{
				return true;
			}
		}
	}
	delete[] visited;

	return false;

}

