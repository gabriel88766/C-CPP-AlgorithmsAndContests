#include <bits/stdc++.h>
#pragma GCC optimize("O2")
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1234568;
int p[N]; // 0 if prime, 1 if not prime
map<int, int> mp;
set<int> xorb[N];
vector<int> f[N];

int cntp = 0;
void sieve(){
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = i*i; j < N; j += i){
                p[j] = 1; //marking all multiples of i as not prime
            }
            for(ll j=i;j<N;j+=i) f[j].push_back(i);
            mp[i] = cntp++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    sieve();
    int bg = 1000000, nd = 1234567;
    ll ans = 1;
    for(int i=bg;i<=nd;i++){
        set<int> cb;
        int aux = i;
        for(auto x : f[i]){
            int cnt = 0;
            while(!(aux % x)){
                cnt++;
                aux /= x;
            }
            if(cnt % 2) cb.insert(x);
        }
        while(cb.size() && xorb[*prev(cb.end())].size()){
            for(auto x : xorb[*prev(cb.end())]){
                if(cb.count(x)) cb.erase(x);
                else cb.insert(x);
            }
        }
        if(cb.size()){
            xorb[*prev(cb.end())] = cb;
        }else{
            ans = (ans * 2) % MOD;
        }
    }
    cout << ans-1 << "\n";
}