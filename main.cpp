#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <unordered_set>

std::unique_ptr<std::vector<int>> uniqNum(std::vector<int> inVec){
    std::vector<int> outVec;
    std::for_each(inVec.begin(),inVec.end(),[inVec,&outVec](int x){
        std::unordered_multiset<int> mySet;
        mySet.insert(inVec.begin(),inVec.end());
        if(mySet.count(x) <= 1) outVec.push_back(x);

    });

    return std::make_unique<std::vector<int>>(outVec);
}

int main() {
    std::vector<int>vec, vec1;



    std::cout<<"input length of array!"<<std::endl;
    int n;
    std::cin>>n;
    vec.resize(n);
    std::cout<<"input array!"<<std::endl;
    for(int & i : vec){
        std::cin>>i;
    }

    auto vecOut = uniqNum(vec);



    for(int x: *vecOut){
        std::cout<<x<<" ";
    }



    return 0;
}
