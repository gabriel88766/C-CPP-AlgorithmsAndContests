#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+5;
int p[N]; // 0 if prime, 1 if not prime
vector<ll> sim;
void sieve(){
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = i*i; j < N; j += i){
                p[j] = 1; //marking all multiples of i as not prime
            }
        }
    }
    for(int i=3;i<=100000;i+=2){
        if(!p[i] && !p[(i+1)/2]){
            sim.push_back(i);
        }
    }
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int q;
    cin >> q;
    sieve();
    while(q--){
        int l, r;
        cin >> l >> r;
        int ans = upper_bound(sim.begin(), sim.end(), r) - lower_bound(sim.begin(), sim.end(), l);
        cout << ans  << "\n";
    }    
}
