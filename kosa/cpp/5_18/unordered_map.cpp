#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> um;
    um.insert({"A", 100});
    um.insert(make_pair("A", 100));
    um.insert({
        {"C", 1000},
        {"D", 2000}
    });

    for(auto i=um.begin(); i != um.end(); ++i){
        cout<<"["<<i->first<<" "<<i->second<<"]";
    }
    cout<<endl;

    cout<<"find value of B: "<<endl;
    auto bc=um.bucket("B");
    for(auto i=um.begin(bc); i != um.end(bc); ++i){
        cout<<i->first<<":"<<i->second;
    }
    cout<<endl;
    return 0;
}


#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main()
{
    unordered_multiset<string> cities{
        "Braunschweig", "Hanover", "Frankfurt", "New York",
        "Chicago", "Toronto", "Paris", "Frankfurt"
    };

    for(const auto& elem : cities)
        cout<<elem<<" ";
    cout<<endl;
    cities.insert({"London", "Munich", "Hanover", "Braunschweig"});

    for(const auto& elem : cities)
        cout<<elem<<" ";
    cout<<endl;

}

