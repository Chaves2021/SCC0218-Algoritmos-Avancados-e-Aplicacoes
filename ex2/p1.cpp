#include <vector>
#include <iostream>

#define SUCCESS		0

using namespace std;

int withdraw(vector<int> coins, int n_types)
{
	int i;
	int amount = 0;
	int n_coins = 0;
	for(i = 0; i < n_types - 1; i++)
	{
		if(amount + coins[i] < coins[i + 1])
		{
			amount += coins[i];
			n_coins++;
		}
	}
	//It's returns the number of coins + 1 because you always get the last coin
	return n_coins + 1;
}

int main(void)
{
	int i;
	int n_tests;
	int n_types;
	int coin;
	cin >> n_tests;
	while(n_tests--)
	{
		cin >> n_types;
		vector<int> coins;
		for(i = 0; i < n_types; i++) 
		{
			cin >> coin;
			coins.push_back(coin);
		}
		cout << withdraw(coins, n_types);
		cout << "\n";
		coins.clear();
	}
	return SUCCESS;
}
