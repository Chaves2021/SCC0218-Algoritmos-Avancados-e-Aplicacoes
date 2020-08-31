#include <bits/stdc++.h>
using namespace std;

struct _person
{
	enum class STATUS
	{
		SINGLE,
		ENGAGEMENT,
		MARRIED
	}status;
	vector<int> pref;
	int counter;
};

typedef struct _person PERSON;

bool isEveryManMarried(PERSON *man)
{
	bool isEveryoneMarried = true;
	for(int i = 0; i < man->counter && isEveryoneMarried; i++)
	{
		if(man->status == STATUS::SINGLE) isEveryoneMarried = false;
	}
	return isEveryoneMarried;
}

void propose(PERSON *man, PERSON *woman)
{
	while(!isEveryManMarried(man))
	{
		if(man->status == STATUS::SINGLE)
		{
			//TODO
			//Needs to think how to create the marriages
			//Very tired right now :p
		}
	}
}

int main(void)
{
	int tests;
	int marriages;
	int i, j, cont;
	int aux;
	PERSON *man = new PERSON [500];
	PERSON *woman = new PERSON [500];

	cin >> tests;
	//while(cont < tests)
	while(cont--)
	{
		cin >> marriages;
		int cont;
		for(i = 0; i < marriages; i++);
		{
			cin >> aux;
			woman->pref.push_back(aux);
			woman->counter++;
			woman->status = STATUS::SINGLE;

		}
		for(i = 0; i < marriages; i++);
		{
			cin >> aux;
			man->pref.push_back(aux);
			man->counter++;
			man->status = STATUS::SINGLE;
		}
		propose(man, woman);
		cont++;
		man->pref.clear();
		woman->pref.clear();
	}
}
