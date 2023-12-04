#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, k;
    cin >> n >> k;
    if(k >= 1000000){ //avoid overflow
        cout << "-1\n";
        return 0;
    }
    vector<ll> divs;
    for(ll i=1;i*i<=n;i++){
        if(!(n % i)){
            if(i*i != n){
                divs.push_back(i);
                divs.push_back(n/i);
            }else{
                divs.push_back(i);
            }
        }
    }
    ll sum = (k * (k+1))/2;
    if(sum > n) cout << "-1\n";
    else{
        ll bdiv = 1;
        for(auto x : divs){
            if(n/x >= sum){ //overflow
                bdiv = max(bdiv, x);
            }
        }
        for(ll i=1;i<k;i++){
            cout << i*bdiv << " ";
        }
        cout << bdiv*(n/bdiv - sum + k) << "\n";
    }
}
