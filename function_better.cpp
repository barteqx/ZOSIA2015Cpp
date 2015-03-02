#include <iostream>
#include <vector>
#include <utility>

#include <boost/range/adaptors.hpp>

using namespace std;
template <typename T1, typename T2>
using vectorOfDoublePairs = vector<pair<T1,T2>>;
// using instead of typedef is highly preferred! (templateable)

double expectedValue(vectorOfDoublePairs<double, double>& v)
{
    double result = 0;
    
    for (const auto& p : v) // Range loop makes this much clear
    {
        cout << p.first << " * " << p.second
        << " = " << p.first * p.second << endl;
        
        result += p.first * p.second;
    }
    
    return result;
}

int main()
{
    vectorOfDoublePairs<double, double> v{ // initialization list in (only!) curly braces
        {4, 0.2},
        {3, 0.25},
        {1, 0.1},
        {5, 0.05},
        {7, 0.15},
        {6, 0.1},
        {8, 0.15}
    };
    
    cout << expectedValue(v) << endl;
}