#include <bits/stdc++.h>

using namespace std;


vector<int> nums = {-17, -8, -2, 2, 5, 12, 14};
vector<pair<int, int>> training_Set;
void init_set(){
    for(auto x : nums){
        training_Set.push_back({x, x*x + 6*x - 17});
    }
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init_set();
}
