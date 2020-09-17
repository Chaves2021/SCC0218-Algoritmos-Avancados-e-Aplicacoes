#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

#define SUCCESS		0

/*
 *
 INPUT: First line with 2 numbers.
        First number is the number of chambers, and seconde the number of specimens
 
        After that, the second line shows the weight of each specimen
 *
 */

int read_input(vector<int> &specimens_weight)
{
	int i;
	int n_specimens;
	int weight;
	cin >> n_specimens;
	for(i = 0; i < n_specimens; i++) 
	{
		cin >> weight;
		specimens_weight.push_back(weight);
	}
	return n_specimens;
}

int __print_output(int left, int right, int chamber, float imbalance)
{
	cout << " " << chamber << ": ";
	//Does not print duplicated
	if(left <= right)
	{
		if(right && left && right != left) cout << left << " " << right << endl;
		else if(right) cout << right << endl;
		else if(left) cout << left << endl;
		else cout << endl;
	}
	else cout << endl;
	return SUCCESS;
}

int print_output(vector<int> specimens_weight, float imbalance, int n_chambers)
{
	int i, j;
	for(i = 0; i < n_chambers; i++, j--)
	{
		__print_output(specimens_weight[i], specimens_weight[specimens_weight.size() - i - 1], i, imbalance);
	}
	cout << fixed;
	cout << "IMBALANCE = " << setprecision(5) << imbalance << endl;
	return SUCCESS;
}

//The function returns the imbalance value
float balance(int n_chambers, vector<int> &specimens_weight)
{
	int i;
	int aux = 0;
	float imbalance = 0.0;
	float sum_mass = 0.0;

	while((aux + (int) specimens_weight.size()) % n_chambers) aux++;
	while(aux--) specimens_weight.push_back(0);

	std::sort(specimens_weight.begin(), specimens_weight.end());
	for(i = 0; i < (int) specimens_weight.size(); i++)
	{
		sum_mass += specimens_weight[i];
	}
	for(i = 0; i < n_chambers; i++)
	{
		if(specimens_weight[i] < specimens_weight[specimens_weight.size() - i - 1])
			imbalance += abs((specimens_weight[i] + specimens_weight[specimens_weight.size() - i - 1]) - (sum_mass / n_chambers));
		else if(specimens_weight[i] == specimens_weight[specimens_weight.size() - i - 1])
			imbalance += abs(specimens_weight[i] - sum_mass / n_chambers);
		else imbalance += sum_mass / n_chambers;
	}

	return imbalance;
}

int main(void)
{
	int n_chambers;
	int aux = 0;
	float imbalance;
	vector<int> specimens_weight;
	while(cin >> n_chambers)
	{
		cout << "Set #" << ++aux << endl; 
		read_input(specimens_weight);
		imbalance = balance(n_chambers, specimens_weight);
		print_output(specimens_weight, imbalance, n_chambers);
		specimens_weight.clear();
		cout << endl;
	}
	return SUCCESS;
}
