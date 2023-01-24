#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<int> v[100005];
map<int,int> mp;
//int invmp[100005];
int n, cnt = 0;

const int N = 1e5+10;
const ull nMOD = 5, pVal = 1e9+97; //change nMOD if needed
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
    Hash(vector<ull> v, int maxlen){ // maxlen > nmax
        inithash(maxlen);
        for(int i=1;i<=v.size();i++){
            for(int j=0;j<nMOD;j++){
                hash[i][j] = (hash[i-1][j] + pot[i][j] * v[i-1]) % MOD[j];
            }
        }
        len = v.size();
    }
    ull *subHash(ull *ans, int l, int r){
        for(int i=0;i<nMOD;i++) ans[i] = ((hash[r][i]-hash[l-1][i]+MOD[i]) * invpot[l][i]) % MOD[i];
        return ans;
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
    //freopen("in", "r", stdin); test input
    vector<pair<int,int>> vp; //len, index
    cin >> n;
    vector<ull> u(n); 
    for(int i=1;i<=n;i++){
        ll aux;
        cin >> aux;
        u[i-1] = aux;
        if(!mp[aux]){
            mp[aux] = ++cnt;
            //invmp[cnt] = aux;
        }
        v[mp[aux]].push_back(i);
    }
    Hash hash(u, N);
    ull h1[5], h2[5];
    for(int i=1;i<=cnt;i++){
        for(int j=0;j<(v[i].size()-1);j++){
            vp.push_back({v[i][j+1]-v[i][j], v[i][j]});
        }
    }
    sort(vp.begin(), vp.end());
    int begin = 0;
    for(auto x : vp){
        if(x.second < (begin+1)) continue;
        int ind1 = x.second, ind2 = x.second + x.first;
        if((ind2 + x.first -1) > n) continue;
        if(isEqual(hash.subHash(h1, ind1, ind2-1), hash.subHash(h2, ind2, ind2+x.first-1))){
            begin = ind2-1;            
        }
    }

    cout << n-begin  << "\n";
    for(int i = begin; i<n;i++) cout << u[i] << " ";
}
