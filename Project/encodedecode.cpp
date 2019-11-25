//This cpp fil ewill be used to decode the data wanted, and encode the data given
// for{
// vector<pair<string,string>> data
// data[i].first
// data[i].second
// }


#include "Main.hpp"

void encode(){
vector<pair<string,string>> data;
    data[1].first = "root";
    data[1].second = "pass.com";
    data[2].first = "root";
    data[2].second = "pass2.com";
    
    string output = "";

    for (pair<string,string> pass: data)
    {   
        output += pass.first + " ";
        output += pass.second + "\n";
        std::cout << pass.first;
        std::cout << pass.second;
    }
    
}


