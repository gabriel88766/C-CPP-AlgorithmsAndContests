#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+10;
const int nMOD = 2, pVal = 257; //change nMOD if needed, use pVal 1e9+123 or something like this if int
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
    void pop_back(){ 
        for(int i=0;i<nMOD;i++){
            hash[len][i] = 0;
        }
        len--;
    }
    void push_back(char c){
        len++; 
        for(int i=0;i<nMOD;i++){
            hash[len][i] =  (hash[len-1][i] + c * pot[len][i]) % MOD[i];
        }
    }
};


bool isEqual(ull *h1, ull *h2){
    for(int i=0;i<nMOD;i++) if(h1[i] != h2[i]) return false;
    return true;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s;
    cin >> s;
    int n = s.size();
    Hash h(s, N);
    ull ans1[nMOD], ans2[nMOD];
    vector<int> ans;
    for(int i=1;i<=n;i++){
        bool ok = true;
        for(int j=i+1;j<=n;j+=i){
            if(!isEqual(h.subHash(ans1, 1, min(i, n-j+1)), h.subHash(ans2, j, min(j+i-1, n)))){
                ok = false;
                break;
            }
        }
        if(ok) ans.emplace_back(i);
    }
    for(int i=0;i<ans.size();i++) cout << ans[i] << " ";
}
