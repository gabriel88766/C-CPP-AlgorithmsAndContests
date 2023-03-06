#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+10;
const int nMOD = 3; //change nMOD if needed, use pVal 1e9+123 or something like this if int
ull pVal;
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
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    pVal = uniform_int_distribution<int>(257, 1000000000)(rng);
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
        hash.assign(n+1, vector<ull> (nMOD, 0));
    }
    Hash(string &s){ // maxlen > nmax
        inithash(s.size());
        for(int i=1;i<=s.size();i++){
            for(int j=0;j<nMOD;j++){
                hash[i][j] = (hash[i-1][j] + pot[i-1][j] * s[i-1]) % MOD[j];
            }
        }
        len = s.size();
    }
    ull *subHash(ull *ans, int l, int r){ //O(1)
        if(l > r) return ans;
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

void combine(ull *ans, ull *h1, ull *h2, int lenh1){
    for(int i=0;i<nMOD;i++){
        ans[i] = (h1[i] + h2[i] * pot[lenh1][i]) % MOD[i];
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    init(N);
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        Hash h(s);
        int ansn = 0;
        map<ull,ull> mp[nMOD];
        for(int i=0;i<(n-1);i++){
            ull ans[nMOD], h1[nMOD], h2[nMOD];
            for(int j=0;j<nMOD;j++) h1[j] = h2[j] = ans[j] = 0;
            combine(ans, h.subHash(h1, 1, i), h.subHash(h2, i+3, n), i);
            int cnt = 0;
            for(int j=0;j<nMOD;j++){
                if(!mp[j].count(ans[j])){
                    mp[j][ans[j]]++;
                    cnt++;
                }
            }
            if(cnt){
                ansn++;
            }
        }
        cout << ansn << "\n";
    }
}
