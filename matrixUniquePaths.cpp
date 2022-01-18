#include<bits/stdc++.h>
using namespace std;


void printPathsUtil(int** mat, int currRow, int currCol, int rows, int cols, int* path, int cnt)
{
	if (rows==currRow || cols==currCol)
	{
		return;
	}

	path[cnt] = mat[currRow][currCol];
	if (currRow == (rows - 1) && currCol == (cols - 1))
	{
		for (int i=0; i<=cnt; ++i)
		{
		    if(i==0)
		    {
		    	std::cout << path[i];
		    }
		    else
		    {
		    	std::cout << "-->" << path[i];
		    }
		}
		std::cout << std::endl;
	}
	
	printPathsUtil(mat, currRow, currCol+1, rows, cols, path, cnt+1);
	printPathsUtil(mat, currRow+1, currCol, rows, cols, path, cnt+1);	
}

void printPaths(int** mat, int rows, int cols)
{
	int currRow = 0;
	int currCol = 0;
 	int* path = new int[rows + cols - 1];	
	
	int cnt = 0;	
	for (int i = 0; i < (rows + cols - 1); i++)
	{
		path[i] = -INT_MAX;
	}

	printPathsUtil(mat, currRow, currCol, rows, cols, path, cnt);
}


// Driver function
int main()
{
	// To store adjacency list of graph
	int rows, cols; 
	std::cout << "Num of rows: ";
	std::cin >> rows;	
	std::cout << "Num of cols: ";
	std::cin >> cols;
	int** mat = new int*[rows];
	for(int i=0; i<rows; ++i)
	{
		mat[i] = new int[cols];
		for(int j=0; j<cols; ++j)
		{
			mat[i][j] =  cols * i + j;
		}		
	}
	
    
	printPaths(mat, rows, cols);
}
