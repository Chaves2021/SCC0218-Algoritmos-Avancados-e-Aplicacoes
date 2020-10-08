#include <iostream>
#include <vector>

using namespace std;

#define SUCCESS		0;

int read_input(int N, vector<vector<int> > &maze)
{
	int i, j;
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			cin >> maze[i][j];
			#ifdef DEBUG
				cout << i << " " << j << "\t";
			#endif
		}
		#ifdef DEBUG
			cout << endl;
		#endif
	}
	return SUCCESS;
}

int find_exit(vector<vector<int> > maze, int &answer, int x_curr, int y_curr, int N)
{
	if(x_curr ==  N - 1 && y_curr == N - 1)
	{
		answer++;
		return SUCCESS;
	}
	//This cell is visited
	maze[x_curr][y_curr] = 1;

	//Try to go to all the 4 directions
	if(x_curr + 1 < N && maze[x_curr + 1][y_curr] != 1)
		find_exit(maze, answer, x_curr + 1, y_curr, N);
	if(x_curr - 1 >= 0 && maze[x_curr - 1][y_curr] != 1)
		find_exit(maze, answer, x_curr - 1, y_curr, N);
	if(y_curr + 1 < N && maze[x_curr][y_curr + 1] != 1)
		find_exit(maze, answer, x_curr, y_curr + 1, N);
	if(y_curr - 1 >= 0 && maze[x_curr][y_curr - 1] != 1)
		find_exit(maze, answer, x_curr, y_curr - 1, N);

	return SUCCESS;

}

int print_maze(int N, vector<vector<int> > maze)
{
	int i, j;
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}
	return SUCCESS;
}

int main(void)
{
	int N;
	int answer = 0;
	cin >> N;
	vector<vector<int> > maze(N,vector<int>(N));
	read_input(N, maze);
	#ifdef DEBUG
		print_maze(N, maze);
	#endif
	find_exit(maze, answer, 0, 0, N);
	cout <<  answer << endl;
	return SUCCESS;
}
