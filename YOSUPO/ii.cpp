#include <bits/stdc++.h>

typedef unsigned long long int ull;
const ull INF_LL = 0x3f3f3f3f3f3f3f3f;
const int INF_INT = 0x3f3f3f3f;
const double PI = acos(-1.), EPS = 1e-9; 
using namespace std;


//1*1*1*1*1...*1 convolution.
//is a multiplicative function.

typedef long long int ll;
map<ll, ll> val[30];
const ll MOD = 1'234'567'891;
ll calc(int e, int n){
    if(val[e].count(n)) return val[e][n];
    if(n == 0) return val[e][n] = (e == 0 ? 1 : 0); 
    if(n == 1) return val[e][n] = 1;
    int hf = n/2;
    vector<ll> ps(e+1);
    for(int i=0;i<=e;i++){
        calc(i, hf);
        if(i == 0) ps[i] = val[i][hf] % MOD;
        else ps[i] = (ps[i-1] + val[i][hf]) % MOD;
    }
    for(int i=0;i<=e;i++){
        if(n % 2) val[e][n] = (val[e][n] + val[i][hf] * ps[e-i]) % MOD;
        else val[e][n] = (val[e][n] + val[i][hf] * val[e-i][hf]) % MOD;
    }
    return val[e][n];
}


const ll N = 1e6+1;
char p[N];
vector<ll> pr;
void sieve(){
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = i*i; j < N; j += i){
                p[j] = 1; 
            }
            pr.push_back(i);
        }
    }
}

const ll posm = 1000000000;
const ll expm = 1000000000;
ll mis = 1, mxs = 1000000;
char p2[N];
ll fat[N];
ll num[N];
void seg_sieve(){
    for(auto x : pr){
        ll fm = ((mis-1)/x + 1) * x;
        for(ll j = fm; j <= mxs; j += x){
            if(j == x) continue;
            p2[j-mis] = true;
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("out", "w", stdout);
    for(int i=1;i<=7;i++){
        for(int j=i+1;j<=7;j++){
            for(int k=j+1;k<=7;k++){
                int x = i^j^k;
                if(x == 0) cout << i << " " << j << " "<< k << "\n"
            }
        }
    }
}
