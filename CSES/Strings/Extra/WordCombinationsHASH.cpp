#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5005;
vector<int> adj[N];
ll dp[N];

const int nMOD = 3, pVal = 257; //change nMOD if needed, use pVal 1e9+123 or something like this if int
const ull MOD[] = {(int)1e9+7, (int)1e9+9, (int)1e9+21, (int)1e9+33, (int)1e9+87, (int)1e9+93, (int)1e9+97};
ull pot[N][nMOD];
ull invpot[N][nMOD];
char inited = false;

ull binpow(ull a, ull b, ull m){
    ull ans = 1;
    while(b > 0){
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

void init(int n){
    inited = true;
    for(int i=0;i<nMOD;i++){
        pot[0][i] = 1, pot[1][i] = pVal;
        invpot[0][i] = 1, invpot[1][i] = binpow(pVal, MOD[i]-2, MOD[i]);
    }  
    for(int i=2;i<n;i++) 
        for(int j=0;j<nMOD;j++){
            pot[i][j] = (pot[i-1][j] * pVal) % MOD[j]; 
            invpot[i][j] = (invpot[i-1][j] * invpot[1][j]) % MOD[j];
        } 
}

struct Hash{ //1-indexed
    vector<vector<ull>> hash;
    int len = 0;
    void inithash(int n){
        if(!inited) init(n);
        hash.assign(n, vector<ull> (nMOD, 0));
    }
    Hash(string &s, int maxlen){ // maxlen > nmax
        inithash(maxlen);
        for(int i=1;i<=s.size();i++){
            for(int j=0;j<nMOD;j++){
                hash[i][j] = (hash[i-1][j] + pot[i-1][j] * s[i-1]) % MOD[j];
            }
        }
        len = s.size();
    }
    ull *subHash(ull *ans, int l, int r){ //O(1)
        for(int i=0;i<nMOD;i++) ans[i] = ((hash[r][i]-hash[l-1][i]+MOD[i]) * invpot[l-1][i]) % MOD[i];
        return ans;
    }
};

void calcHash(ull *hash, string s){ //only calc hash of whole string
    for(int i=0;i<nMOD;i++) hash[i] = 0;
    for(int i=1;i<=s.size();i++){
        for(int j=0;j<nMOD;j++){
            hash[j] = (hash[j] + pot[i-1][j] * s[i-1]) % MOD[j];
        }
    }
}

map<ull, int> mp[5005][nMOD];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin); //test input
    string s;
    int n;
    dp[0] = 1;
    cin >> s;
    cin >> n;
    Hash h1(s, N);
    ull hx[nMOD];
    
    for(int i=0;i<n;i++){
        string aux;
        cin >> aux;
        if(aux.size() > s.size()) continue;
        calcHash(hx, aux);
        for(int i=0;i<nMOD;i++) mp[aux.size()][i][hx[i]]++;
    }
    for(int i=0;i<s.size();i++){
        for(int j=1;j<s.size();j++){
            if(i+j > s.size()) break;
            bool ok = true;
            h1.subHash(hx, i+1, i+j);
            for(int k=0;k<nMOD;k++) {
                if(!ok) break;
                ok = (mp[j][k].count(hx[k]) == 0 ? false : true);
            }
            if(ok) dp[i+j] = (dp[i+j] + dp[i]) % MOD[0];
        }
    }
    cout << dp[s.size()];

}
