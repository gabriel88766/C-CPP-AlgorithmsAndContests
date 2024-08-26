#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+2;
const int nMOD = 3; //change nMOD if needed;
ull pVal; 
const ull MOD[] = {(ull)1e9+7, (ull)1e9+9, (ull)1e9+21, (ull)1e9+33, (ull)1e9+87, (ull)1e9+93, (ull)1e9+97};
ull pot[N][nMOD];
ull invpot[N][nMOD];
ull hs[N][26][nMOD];
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
    pVal = uniform_int_distribution<int>(5, 1000000000)(rng); //greater than alphabet
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

int nxt[N][26];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = " " + s;
    init(n+2);
    for(int i=1;i<=n;i++){
        for(int k=0;k<nMOD;k++){
            for(int j=0;j<26;j++) hs[i][j][k] = hs[i-1][j][k];
            hs[i][s[i]-'a'][k] += pot[i][k];
            hs[i][s[i]-'a'][k] %= MOD[k];
        }
    }
    
    for(int i=n;i>=1;i--){
        if(i == n) for(int j=0;j<26;j++) nxt[i][j] = -1;
        else for(int j=0;j<26;j++) nxt[i][j] = nxt[i+1][j];
        nxt[i][s[i]-'a'] = i;
    }

    for(int i=0;i<q;i++){
        int x, y, len;
        cin >> x >> y >> len;
        vector<pair<int, int>> chk;
        for(int j=0;j<26;j++){
            int it = nxt[x][j];
            if(it != -1 && it < x + len){
                int dif = it - x;
                chk.push_back({s[it]-'a', s[y+dif] - 'a'});
            }
        }
        bool ok = true;
        for(auto [u, v] : chk){
            bool cok = true;
            for(int j=0;j<nMOD;j++){
                ull h1 = hs[x+len-1][u][j] + MOD[j] - hs[x-1][u][j];
                ull h2 = hs[y+len-1][v][j] + MOD[j] - hs[y-1][v][j];
                h1 *= invpot[x][j];
                h2 *= invpot[y][j];
                h1 %= MOD[j];
                h2 %= MOD[j];
                if(h1 < 0) h1 += MOD[j];
                if(h2 < 0) h2 += MOD[j];
                if(h1 != h2) cok = false;
            }
            if(!cok) ok = false;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }

}
