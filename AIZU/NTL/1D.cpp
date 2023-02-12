#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, phi;
    cin >> n;
    if(n == 1){
        cout << 1 << "\n";
        return 0;
    }
    phi = n;
    vector<int> fact;
    for(int i=2;i<=31800;i++){
        if(i > n) break;
        if(!(n % i)){
            fact.push_back(i);
            while(!(n % i)){
                n /= i;
            }
        }
    }
    if(n > 1) fact.push_back(n);
    for(auto u : fact){
        phi /= u;
        phi *= (u-1);
    }
    cout << phi << "\n";
}