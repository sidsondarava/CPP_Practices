#include <vector>
#include "vector.h"


int main() {
    vector<int> v1;
    Vector<int> SV1;
    vector<int> v2(5);
    Vector<int> SV2(5);
    SV2[0] = 10;
    vector<int> v3(5,1);
    Vector<int> SV3(5,1);
    //std::cout<<SV2;

    //Vector<int> SV4(2);
    //cin>>SV4;
    //cout<<SV4;

    vector<int> v4 = v3; //copy constructor
    Vector<int> SV4 = SV3;
    

    v1 = v4; //copy assignment operator
    SV1 = SV4; 

    

    vector<int> v5(vector<int>{1,2,3,4,5});  //move constructor
    Vector<int> SV5 = std::move(SV4);
    //Vector<int> SV5(Vector<int>{1,2,3,4,5});
    
    vector<int> v6; //move assignment operator
    v6 = std::move(v5);
    Vector<int> SV6(1);
    SV6 = std::move(SV5);

    

    

    v6.push_back(6);
    SV6.push_back(8);
    v6.pop_back();
    SV6.pop_back();
    for(size_t i = 0; i < SV6.GetSize(); i++)
    {
         std::cout<< SV6[i] << std::endl;
    }


    v6.reserve(10); //so capacity can be >= 10
    v6.resize(8); // size will updated elements will get the default values.

    return 0;
}
