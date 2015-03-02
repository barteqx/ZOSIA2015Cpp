#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef vector<pair<double,double> > vectorOfDoublePairs;

double expectedValue(vectorOfDoublePairs& v)
{
	double result = 0;

	for (vectorOfDoublePairs::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << it->first << " * " << it->second 
			<< " = " << it->first * it->second << endl;
		result += it->first * it->second;
	}

	return result;
}

int main()
{
	vectorOfDoublePairs v;
	v.push_back(make_pair<double,double>(4, 0.2));
	v.push_back(make_pair<double,double>(3, 0.25));
	v.push_back(make_pair<double,double>(1, 0.1));
	v.push_back(make_pair<double,double>(5, 0.05));
	v.push_back(make_pair<double,double>(7, 0.15));
	v.push_back(make_pair<double,double>(6, 0.1));
	v.push_back(make_pair<double,double>(8, 0.15));

	cout << expectedValue(v) << endl;
}