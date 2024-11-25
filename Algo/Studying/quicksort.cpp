#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

typedef long long int ll; 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); //almost safe random

void quicksort(vector<int> &vec){
    if(vec.size() <= 1) return; //already ordered.
    int pvt = vec[uniform_int_distribution<int>(0, vec.size()-1)(rng)];
    vector<int> left, mid, right;
    for(auto &x : vec){
        if(x < pvt) left.push_back(x);
        else if(x == pvt) mid.push_back(x);
        else right.push_back(x);
    }
    quicksort(left);
    quicksort(right);
    vec.clear();
    for(auto &x : left) vec.push_back(x);
    for(auto &x : mid) vec.push_back(x);
    for(auto &x : right) vec.push_back(x);
}

int main(){
    vector<int> example;
    for(int i=0;i<=500000;i++){
        example.push_back(uniform_int_distribution<int>(0, 2)(rng));
    }
    quicksort(example);
    cout << "sorted:\n";
    for(auto &x : example) cout << x << " ";
    cout << "\n";
}
