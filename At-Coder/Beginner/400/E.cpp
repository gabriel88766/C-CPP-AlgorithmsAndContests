#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6;
int ttp[N+1]; // 0 if prime, 1 if not prime
vector<ll> v;
void sieve(){
    for(ll i=2; i<=N; i++){
        if(!ttp[i]){
            for(ll j = i; j <= N; j += i){
                ttp[j]++;
            }
        }
        if(ttp[i] == 2) v.push_back(i);
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    sieve();
    int q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        int lo = 0, hi = v.size() - 1;
        while(lo != hi){
            int mid = lo + (hi - lo + 1)/2;
            if(v[mid]*v[mid] <= n) lo = mid;
            else hi = mid - 1;
        }
        cout << v[lo]*v[lo] << "\n";
    }
}
