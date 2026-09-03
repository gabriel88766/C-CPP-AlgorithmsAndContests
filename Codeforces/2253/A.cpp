#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+5;
int np[N]; // 0 if prime, 1 if not prime
void sieve(){
    for(ll i=2; i<N; i++){
        if(!np[i]){
            for(ll j = i*i; j < N; j += i){
                np[j] = 1; //marking all multiples of i as not prime
            }
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    sieve();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ++n;
        if(!np[n]) cout << "YES\n";
        else cout << "NO\n";
    }
}
