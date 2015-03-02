#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>

#include <boost/range/adaptors.hpp>

using namespace std;
using namespace boost::adaptors;

template <typename T>
auto expectedValue(T& container)
{
    cout << __PRETTY_FUNCTION__ << endl;
    
    auto lambda = [](auto const& p)
    {
        return p.first * p.second;
    };
    
    auto range = container | transformed(lambda);
    return accumulate(range.begin(), range.end(), 0.0);
}

std::shared_ptr<Abc> a = std::make_shared<Abc>(...);

auto squared = [](auto x) { return x * x; };

template <typename T>
auto variation(T& container)
{
    auto lambda = [](const auto p) -> decltype(p)
    {
        return { squared(p.first), p.second };
    };
    
    auto X2 = container | transformed(lambda);
    return expectedValue(X2) - squared(expectedValue(container));
}

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
    
    auto var = variation(c1);
    cout << setprecision(100) << var << endl; // if ~4.7875 then correct
    
    vector<pair<double,float>> c2{
        {4, 0.2},
        {3, 0.25},
        {1, 0.1},
        {5, 0.05},
        {7, 0.15},
        {6, 0.1},
        {8, 0.15}
    };
    
    auto var2 = variation(c2);
    cout << setprecision(100) << var2 << endl;
}