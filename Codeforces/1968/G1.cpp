#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+10;
const int nMOD = 1; //change nMOD if needed;
ull pVal; 
const ull MOD[] = {(ull)1e9+7, (ull)1e9+9, (ull)1e9+21, (ull)1e9+33, (ull)1e9+87, (ull)1e9+93, (ull)1e9+97};
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void init(int n){
    inited = true;
    
    pVal = uniform_int_distribution<int>(257, 1000000000)(rng); //greater than alphabet
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
    void inithash(int maxl, int strlen){
        if(!inited) init(maxl);
        hash.assign(strlen+1, vector<ull> (nMOD, 0));
    }
    Hash(string &s, int maxlen, int strlen){ // maxlen > nmax
        inithash(maxlen, strlen);
        for(int i=1;i<=s.size();i++){
            for(int j=0;j<nMOD;j++){
                hash[i][j] = (hash[i-1][j] + pot[i-1][j] * s[i-1]) % MOD[j];
            }
        }
        len = s.size();
    }
    void subHash(vector<ull> &ans, int l, int r){ //O(1)
        for(int i=0;i<nMOD;i++) ans[i] = ((hash[r][i]-hash[l-1][i]+MOD[i]) * invpot[l-1][i]) % MOD[i];
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


bool isEqual(vector<ull> &h1, vector<ull> &h2){
    for(int i=0;i<nMOD;i++) if(h1[i] != h2[i]) return false;
    return true;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, l, r;
        cin >> n >> l >> r;
        string s;
        cin >> s;
        Hash hs(s, 200005, s.size());
        int lo = 0, hi = n;
        vector<ull> v1(nMOD), v2(nMOD);
        while(lo != hi){
            int mid = lo + (hi - lo + 1)/2;
            int cnt = 1;
            int last = 1;
            hs.subHash(v1, 1, mid);
            for(int i=mid+1;i<=n;i++){
                if(i < last + mid) continue;
                if(i + mid - 1 > n) break;
                hs.subHash(v2, i, i+mid-1);
                if(isEqual(v1, v2)){
                    cnt++;
                    last = i;
                }
            }
            if(cnt >= l) lo = mid;
            else hi = mid - 1;
        }
        cout << lo << "\n";
    }
}
