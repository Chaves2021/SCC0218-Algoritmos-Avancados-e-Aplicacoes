#include <iostream>
#include <vector>
using namespace std;

#define NOT_SINGLE -1

struct __person
{
	enum STATUS
	{
		SINGLE,
		ENGAGED,
		MARRIED
	}status;
	vector<int> pref;
	int pair;
};

typedef struct __person PERSON;

void read_input(vector<PERSON> &man, vector<PERSON> &woman)
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
			woman[i].pref.push_back(aux - 1);
			woman[i].status = PERSON::SINGLE;
			woman[i].pair = -2;
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
			man[i].pref.push_back(aux - 1);
			man[i].status = PERSON::SINGLE;
			man[i].pair = -2;
		}
	}
}

void print_results(vector<PERSON> man, vector<PERSON> woman)
{
	unsigned long int i;
	for(i = 0; i < man.size(); i++)
	{
		cout << i + 1 << " " << man[i].pair  + 1<< "\n";
	}
}

int isEveryManMarried(vector<PERSON> man)
{
	bool single = true;
	unsigned long int i;
	for(i = 0; i < man.size() && single; i++)
	{
		if(man[i].status == PERSON::SINGLE) single = false;
	}
	if(single) i = NOT_SINGLE + 1;
	return i - 1;
}

bool shePrefersAnother(vector<PERSON> &man, vector<PERSON> woman, int index0, int index1)
{
	unsigned long int i;
	for(i = 0; i < man.size(); i++)
	{
		if(woman[man[index0].pref[index1]].pref[i] == woman[man[index0].pref[index1]].pair)
			return false;
		if(woman[man[index0].pref[index1]].pref[i] == index0)
		{
			man[woman[man[index0].pref[index1]].pair].status = PERSON::SINGLE;
			man[woman[man[index0].pref[index1]].pair].pair = -1;
			return true;
		}
	}
	return false;
}

void __propose(vector<PERSON> &man, vector<PERSON> &woman, int index)
{
	unsigned long int i;
	bool getEngaged = false;
	for(i = 0; i < man.size() && !getEngaged; i++)
	{
		if(woman[man[index].pref[i]].status == PERSON::SINGLE)
		{
			man[index].pair = man[index].pref[i];
			man[index].status = PERSON::ENGAGED;
			woman[man[index].pref[i]].pair = index;
			woman[man[index].pref[i]].status = PERSON::ENGAGED;
			getEngaged = true;
		}
		else if(shePrefersAnother(man, woman, index, i))
		{
			man[index].pair = man[index].pref[i];
			man[index].status = PERSON::ENGAGED;
			woman[man[index].pref[i]].pair = index;
			woman[man[index].pref[i]].status = PERSON::ENGAGED;
			getEngaged = true;
		}
	}
}

void propose(vector<PERSON> &man, vector<PERSON> &woman)
{
	int index = isEveryManMarried(man);
	unsigned long int i;
	while(index != NOT_SINGLE)
	{
		for(i = 0; i < man.size(); i++)
		{
			__propose(man, woman, i);
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
		print_results(man, woman);
		man.clear();
		woman.clear();
	}
}
