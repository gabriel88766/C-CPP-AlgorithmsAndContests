#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+5;
int p[N]; // 0 if prime, 1 if not prime

void sieve(){
    p[1] = 1;
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = i*i; j < N; j += i){
                p[j] = 1; //marking all multiples of i as not prime
            }
        }
    }
}

ll fat[N], invfat[N];
void init(){ //MOD must be prime
    fat[0] = invfat[N-1] = 1;
    for(int i=1;i<N;i++){
        fat[i] = (fat[i-1]*i) % MOD;
    }
    ll aux = MOD - 2, aux2 = fat[N-1];
    while(aux){
        if(aux & 1) invfat[N-1] = (invfat[N-1] * aux2) % MOD;
        aux2 = (aux2 * aux2) % MOD;
        aux >>= 1;
    }
    for(int i=N-2;i>=0;i--) invfat[i] = (invfat[i+1] * (i + 1)) % MOD;
}

map<int,int> oc;
set<int> pap, npap;

ll dp[2025], newdp[2025];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    sieve();
    init();
    ll ans = 0;
    int n;
    cin >> n;
    vector<int> v(2*n);
    for(int i=0;i<2*n;i++) cin >> v[i];
    for(int i=0;i<2*n;i++){
        if(p[v[i]] == 0) pap.insert(v[i]);
        else npap.insert(v[i]);
        oc[v[i]]++;
    }
    if(pap.size() < n){
        cout << "0\n";
        return 0;
    } 
    ll fac = fat[n];
    for(auto it = npap.begin(); it != npap.end(); ++it){
        fac = (fac * invfat[oc[*it]]) % MOD;
    }
    dp[0] = fac;
    for(auto it = pap.begin(); it != pap.end(); ++it){
        memset(newdp, 0, sizeof(newdp));
        for(int i=0;i<=2023;i++){
            if(i == 0) newdp[0] = (dp[0] * invfat[oc[*it]]) % MOD;
            else{
                newdp[i] = ((dp[i] * invfat[oc[*it]]) + (dp[i-1] * invfat[oc[*it]-1])) % MOD; 
            }
        }
        for(int i=0;i<2023;i++) dp[i] = newdp[i];
    }
    cout << dp[n];
}
