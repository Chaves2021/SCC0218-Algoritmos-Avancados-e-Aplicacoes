#include <bits/stdc++.h>
using namespace std;

struct __person
{
	enum STATUS
	{
		SINGLE,
		ENGAGEMENT,
		MARRIED
	}status;
	vector<int> pref;
};

typedef struct __person PERSON;

bool isEveryManMarried(vector<PERSON> man)
{
	bool isEveryoneMarried = true;
	for(int i = 0; i < man.size() && isEveryoneMarried; i++)
	{
		if(man[i].status == PERSON::SINGLE) isEveryoneMarried = false;
	}
	return isEveryoneMarried;
}

void propose(vector<PERSON> man, vector<PERSON> woman)
{
	int counter = 0;
	while(!isEveryManMarried(man))
	{
		if(man[counter].status == PERSON::SINGLE)
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
	int i, j;
	int aux;
	//PERSON *man = new PERSON [500];
	//PERSON *woman = new PERSON [500];
	vector<PERSON> man;
	vector<PERSON> woman;
	//PERSON m, w;

	cin >> tests;
	//while(cont < tests)
	while(tests--)
	{
		cin >> marriages;
		int cont;
		for(i = 0; i < marriages; i++)
		{
			cin >> aux;
			for(j = 0; j < marriages; j++)
			{
				cin >> aux;
				PERSON w;
				woman.push_back(w);
				woman[i].pref.push_back(aux);
				woman[i].status = PERSON::SINGLE;
			}

		}
		for(i = 0; i < marriages; i++)
		{
			cin >> aux;
			for(j = 0; j < marriages; j++)
			{
				cin >> aux;
				PERSON m;
				man.push_back(m);
				man[i].pref.push_back(aux);
				man[i].status = PERSON::SINGLE;
			}
		}
		//propose(man, woman);
		for(i = 0; i < marriages; i++)
		{
			cout << i << ": ";
			for(j = 0; j < man.size(); j++)
			{
				cout << man[i].pref[j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
		for(i = 0; i < marriages; i++)
		{
			cout << i << ": ";
			for(j = 0; j < man.size(); j++)
			{
				cout << woman[i].pref[j] << " ";
			}
			cout << "\n";
		}
		cont++;
		man.clear();
		woman.clear();
	}
}
