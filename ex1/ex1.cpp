#include <iostream>
#include <vector>
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

bool isEveryManMarried(vector<PERSON> man)
{
	bool isEveryoneMarried = true;
	//for(i = 0; i < man.size() && isEveryoneMarried; i++)
	for(auto m : man)
	{
		if(m.status == PERSON::SINGLE) isEveryoneMarried = false;
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
		propose(man, woman);
		//debug(man, woman);
		cont++;
		man.clear();
		woman.clear();
	}
}
