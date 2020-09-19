#include <iostream>
#include <vector>

#define SUCCESS		0;

typedef struct track
{
	int duration;
	bool isVisited;
}TRACK;

int print_output(vector<int> tape)
{
	int sum = 0;
	for(unsigned long int i = 0; i < tape.size; i++)
	{
		printf("%d ", tape[i]);
		sum += tape[i];
	}
	printf("sum: %d\n", sum);
	return SUCCESS;
}

int recursive_backtracking(int N, vector<TRACK> all_tracks, vector<int> &tape)
{
	int sum = 0;
	for(unsigned long int i = 0; i < tape.size(); i++) sum += tape[i];
	if(sum == N) return SUCCESS;
	for(i = 0; i < all_tracks.size(); i++)
	{
		if(!(all_tracks[i].isVisited) && (sum + all_tracks[i].duration) <= N)
		{
			all_tracks[i].isVisited = true;
			tape.push_back(all_tracks[i].duration);
			recursive_backtracking(N, all_tracks, tape);
		}
	}
	return SUCCESS;
}

int main(void)
{
	int N;
	int n_tracks;
	vector<TRACK> all_tracks;
	vector<int> tape;
	int counter, i;
	TRACK aux;
	aux.isVisited = false;
	int sum = 0;
	while(cin >> N)
	{
		cin >> n_tracks;
		while(counter < n_tracks)
		{
			cin >> aux.duration;
			all_tracks.push_back(aux);
			++counter;
		}
		for(i = 0; i < n_tracks; i++) recursive_backtracking(N, all_tracks, tape);
		print_output(tape);
		duration.clear();
		tracks.clear();
	}
	return SUCCESS;
}
