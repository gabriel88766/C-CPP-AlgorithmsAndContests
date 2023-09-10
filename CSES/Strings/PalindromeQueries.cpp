#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+10;
const int nMOD = 3; //change nMOD if needed;
ll pVal; 
const ll MOD[] = {(ll)1e9+7, (ll)1e9+9, (ll)1e9+21, (ll)1e9+33, (ll)1e9+87, (ll)1e9+93, (ll)1e9+97};
ll pot[N][nMOD];
ll invpot[N][nMOD];
char inited = false;

int n;
ll bit[2][N][nMOD];
 
vector<ll> query(int t, int l, int r){ // sum in range [1, b]
    vector<ll> ans(nMOD, 0);
    for(int i = r; i > 0; i -= i & -i){
        for(int j = 0; j < nMOD; j++){
            ans[j] = (ans[j] + bit[t][i][j]) % MOD[j];
        }
    }
    for(int i = l-1; i > 0; i -= i & -i){
        for(int j = 0; j < nMOD; j++){
            ans[j] = (ans[j]+MOD[j]-bit[t][i][j]) % MOD[j];
        }
    }
    for(int j = 0; j < nMOD; j++){
        ans[j] = (ans[j] * invpot[l-1][j]) % MOD[j];
    } 
    return ans;
}
 
void add(int t, int b, vector<ll> value){ //add value to position b
    for(int i = b; i <= n; i += i & -i){
        for(int j = 0; j < nMOD; j++){
            bit[t][i][j] = (value[j] + MOD[j] + bit[t][i][j]) % MOD[j];
        }
    }
}


ll binpow(ll a, ll b, ll m){
    ll ans = 1;
    while(b > 0){
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

void init(int n){
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    //pVal = uniform_int_distribution<int>(257, 1000000000)(rng); //greater than alphabet
    pVal = 257;
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

void add(int t, int pos, ll x){
    vector<ll> v(nMOD);
    for(int j=0;j<nMOD;j++){
        v[j] = (x * pot[pos-1][j]) % MOD[j];
    }
    add(t, pos, v);
}

void initBit(int t, string &s){
    for(int i = 0; i < s.size(); i++){
        add(t, i+1, s[i]);
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int m;
    string s, t;
    init(N);
    cin >> n >> m >> s;
    t = s;
    reverse(t.begin(), t.end());
    initBit(0, s);
    initBit(1, t);
    for(int i=0;i<m;i++){
        int tq;
        cin >> tq;
        if(tq == 1){
            int p;
            char c;
            cin >> p >> c;
            vector<ll> v(nMOD);
            add(0, p, -s[p-1]);
            add(0, p, c);
            s[p-1] = c;
            int p2 = n-p+1;
            add(1, p2, -t[p2-1]);
            add(1, p2, c);
            t[p2-1] = c;
        }else{
            int a, b;
            cin >> a >> b;
            int len = b-a+1;
            int p2 = n-b+1;
            auto v1 = query(0, a, b);
            auto v2 = query(1, p2, p2+len-1);
            if(query(0, a, b) == query(1, p2, p2+len-1)) cout << "YES\n";
            else cout << "NO\n";
        }

    }
}
