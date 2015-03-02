#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <numeric>

#include <boost/range/adaptors.hpp>

using namespace std;
using namespace boost::adaptors;

template <typename T1, typename T2>
auto expectedValue(vector<pair<T1,T2>> & container)
// We template this function to make this more generic
{
    cout << __PRETTY_FUNCTION__ << endl;
    
    // lambda ofc!
    auto lambda = [](pair<T1,T2> & p) -> decltype(p.first * p.second) // some decltype() magic
    {
        cout << p.first << " * " << p.second << " = "
        << p.first * p.second << endl;
        
        return p.first * p.second;
    };
    
    auto range = container | transformed(lambda); // usage of adaptors
    // range = reverse $ map lambda
    
    // if you can use something more descriptive than plain for - use it.
    return accumulate(range.begin(), range.end(), 0.0);
    // foldr (+) 0 range
}

int main()
{
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
}
