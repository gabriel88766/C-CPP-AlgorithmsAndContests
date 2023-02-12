#include <bits/stdc++.h>

typedef long long int ll;
const ll MOD = 1e9+7;
using namespace std;

int main(){
    ll n, lcm;
    cin >> n;
    for(int i =0;i<n;i++){
        if(!i) cin >> lcm;
        else{
            ll aux;
            cin >> aux;
            lcm = (aux*lcm)/__gcd(aux,lcm);
        }
    }
    cout << lcm << "\n";
}