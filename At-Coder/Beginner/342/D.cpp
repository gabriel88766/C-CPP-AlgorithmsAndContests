#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 2e5+1;
int p[N]; // 0 if prime, 1 if not prime
vector<int> pr;
vector<int> fact[N];
void sieve(){
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = i*i; j < N; j += i){
                p[j] = 1; //marking all multiples of i as not prime
            }
            pr.push_back(i);
        }
    }
    //routine 2
    for(auto x : pr){
        for(int i=x; i < N; i+=x){
            int cnt = 0;
            int aux = i;
            while(!(aux % x)){
                cnt++;
                aux /= x;
            }
            if(cnt%2) fact[i].push_back(x);
        }
    }
}

map<vector<int>, ll> mp;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    ll c0 = 0;
    sieve();
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(x == 0) c0++;
        else mp[fact[x]]++;
    }
    ll ans = 0;
    for(auto [k, v] : mp){
        ans += (v*(v-1))/2;
    }
    ans += c0 * (n-c0);
    ans += (c0*(c0-1))/2;
    cout << ans << "\n";
}
