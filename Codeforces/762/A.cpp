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
    vector<ll> od;
    for(ll i = 1; i*i <= n; i++){
        if(n % i == 0){
            k--;
            if(i * i != n) od.push_back(n / i);
        }
        if(k == 0){
            cout << i << "\n";
            return 0;
        }
    }
    k--;
    reverse(od.begin(), od.end());
    if(k < od.size()) cout << od[k] << "\n";
    else cout << "-1\n"; 
}
