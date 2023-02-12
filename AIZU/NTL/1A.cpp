#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, rn;
    cin >> n;
    rn = n;
    vector<int> fact;
    for(int i=2;i<=31800;i++){
        if(i > n) break;
        while(!(n % i)){
            fact.push_back(i);
            n /= i;
        }
    }
    if(n > 1) fact.push_back(n);
    cout << rn << ":";
    for(auto u : fact) cout << " " << u;
    cout << "\n";
}