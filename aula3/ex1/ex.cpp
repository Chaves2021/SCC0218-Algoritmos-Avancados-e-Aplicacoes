#include <iostream>
#include <vector>

using namespace std;

#define SUCCESS		0;

typedef struct tape
{
	vector<int> tracks;
	int duration;
}TAPE;


int print_output(TAPE tape)
{
	for(unsigned long int i = 0; i < tape.tracks.size(); i++) cout << tape.tracks[i] << " ";
	cout << "sum:" << tape.duration << endl;
	return SUCCESS;
}

int choose_best_tape(TAPE &tape, TAPE &aux_tape)
{
	if(tape.duration < aux_tape.duration)
	{
		tape.duration = aux_tape.duration;
		tape.tracks = aux_tape.tracks;
	}
	return SUCCESS;
}

int recursive_backtracking(int N, vector<int> all_tracks, TAPE &tape, TAPE &aux_tape, int index)
{
	aux_tape.duration += all_tracks[index];
	aux_tape.tracks.push_back(all_tracks[index]);

	choose_best_tape(tape, aux_tape);

	for(unsigned long int i = index + 1; i < all_tracks.size(); i++)
	{
		if((aux_tape.duration + all_tracks[i]) <= N)
			recursive_backtracking(N, all_tracks, tape, aux_tape, i);
	}
	//Need to pop when the function reaches the end to test other possibilities
	//If I don't use that, the function goes through only a part of the tree of possibilities
	aux_tape.duration -= all_tracks[index];
	aux_tape.tracks.pop_back();

	return SUCCESS;
}

int main(void)
{
	int N;
	int n_tracks;
	vector<int> all_tracks;
	unsigned long int i;
	TAPE tape;
	TAPE aux_tape;
	int aux;
	while(cin >> N)
	{
		cin >> n_tracks;
		while(n_tracks--)
		{
			cin >> aux;
			all_tracks.push_back(aux);
		}
		tape.duration = 0;
		tape.tracks.clear();
		for(i = 0; i < all_tracks.size(); i++) 
		{
			aux_tape.duration = 0;
			recursive_backtracking(N, all_tracks, tape, aux_tape, i);
			aux_tape.tracks.clear();
		}
		print_output(tape);
		all_tracks.clear();
	}
	return SUCCESS;
}
