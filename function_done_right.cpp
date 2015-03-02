#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <numeric>

#include <boost/range/adaptors.hpp>

using namespace std;
using namespace boost::adaptors;

template <typename T>
auto expectedValue(T& container) // auto here
{
    cout << __PRETTY_FUNCTION__ << endl;

	auto lambda = [](auto const& p) // and here and we do not declare a return type
	{
		cout << p.first << " * " << p.second << " = "
			<< p.first * p.second << endl;
        
		return p.first * p.second;
	};
    
    auto range = container | transformed(lambda);
    // range = reverse $ map lambda

 	return accumulate(range.begin(), range.end(), 0.0);
 	// foldr (+) 0 range
}
/*
    We did not use ANY concrete type in the function above - this
    makes the function very general and possible to use on any container!
*/

int main()
{
	map<float,double> c1{ 
		{4, 0.2},
		{3, 0.25},
		{1, 0.1},
		{5, 0.05},
		{7, 0.15},
		{6, 0.1},
		{8, 0.15}
	};

	cout << expectedValue(c1) << endl;

	vector<pair<double,float>> c2{ 
		{4, 0.2},
		{3, 0.25},
		{1, 0.1},
		{5, 0.05},
		{7, 0.15},
		{6, 0.1},
		{8, 0.15}
	};

	cout << expectedValue(c2) << endl;

	unordered_map<float,double> c3{ 
		{4, 0.2},
		{3, 0.25},
		{1, 0.1},
		{5, 0.05},
		{7, 0.15},
		{6, 0.1},
		{8, 0.15}
	};

	cout << expectedValue(c3) << endl;
}