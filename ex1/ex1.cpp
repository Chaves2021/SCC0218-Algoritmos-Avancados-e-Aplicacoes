#include <iostream>
#include <vector>
using namespace std;

#define NOT_SINGLE -1

struct __person
{
	enum STATUS
	{
		SINGLE,
		ENGAGEMENT,
		MARRIED
	}status;
	vector<int> pref;
	int pair;
};

typedef struct __person PERSON;

void read_input(vector<PERSON> man, vector<PERSON> woman)
{
	int i, j;
	int marriages;
	int aux;
	cin >> marriages;
	for(i = 0; i < marriages; i++)
	{
		cin >> aux;
		PERSON w;
		woman.push_back(w);
		for(j = 0; j < marriages; j++)
		{
			cin >> aux;
			woman[i].pref.push_back(aux);
			woman[i].status = PERSON::SINGLE;
		}

	}
	for(i = 0; i < marriages; i++)
	{
		cin >> aux;
		PERSON m;
		man.push_back(m);
		for(j = 0; j < marriages; j++)
		{
			cin >> aux;
			man[i].pref.push_back(aux);
			man[i].status = PERSON::SINGLE;
		}
	}
}

void debug(vector<PERSON> man, vector<PERSON> woman)
{
	int i = 0;
	for(auto w : woman)
	{
		cout << i + 1 << ": ";
		i++;
		for(auto p : w.pref)
		{
			cout << p << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	i = 0;
	for(auto m : man)
	{
		cout << i + 1 << ": ";
		i++;
		for(auto p : m.pref)
		{
			cout << p << " ";
		}
		cout << "\n";
	}
}

int isEveryManMarried(vector<PERSON> man)
{
	bool single = true;
	int i;
	for(i = 0; i < man.size() && single; i++)
	{
		if(man[i].status == PERSON::SINGLE) single = false;
	}
	if(single == true) i = NOT_SINGLE + 1;
	return i - 1;
}

bool isAvailable(vector<PERSON> person)
{
	bool isAvailable;

	return isAvailable;
}

void __propose(PERSON man, vector<PERSON> woman)
{
}

void propose(vector<PERSON> man, vector<PERSON> woman)
{
	int index = isEveryManMarried(man);
	while(index != NOT_SINGLE)
	{
		for(PERSON m : man)
		{
			__propose(m, woman);
		}
		index = isEveryManMarried(man);
	}
}

int main(void)
{
	int tests;
	vector<PERSON> man;
	vector<PERSON> woman;

	cin >> tests;
	while(tests--)
	{
		read_input(man, woman);
		propose(man, woman);
		//debug(man, woman);
		//print_results(man, woman);
		man.clear();
		woman.clear();
	}
}
