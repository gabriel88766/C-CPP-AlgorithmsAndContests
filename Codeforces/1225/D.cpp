#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 317;
int p[N]; // 0 if prime, 1 if not prime
vector<ll> primes;
void sieve(){
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = i*i; j < N; j += i){
                p[j] = 1; //marking all multiples of i as not prime
            }
            primes.push_back(i);
        }
    }
}

map<vector<pair<int,int>>, int> mp;
vector<pair<int,int>> fact[100005];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    //primes lower than sqrt(N) = 316.
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sieve();
    for(int i=0;i<n;i++){
        int aux = v[i];
        for(int j=0;j<primes.size();j++){
            int cnt = 0;
            while(!(aux % primes[j])){
                aux /= primes[j];
                cnt++;
            }
            cnt %= k;
            if(cnt != 0){
                fact[i].push_back({primes[j], cnt});
            }
        }
        if(aux != 1) fact[i].push_back({aux, 1});
        mp[fact[i]]++;
    }
    
    ll ans = 0;
    for(int i=0;i<n;i++){
        vector<pair<int,int>> rev;
        bool ok = true;
        for(auto x: fact[i]){
            rev.push_back({x.first, k-x.second});
            if(rev.back().second != x.second) ok = false;
        }
        ans += mp.count(rev) ? mp[rev] : 0;
        if(ok) ans--;
    }
    cout << ans/2;
}
