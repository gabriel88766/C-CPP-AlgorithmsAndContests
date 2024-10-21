#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


ll binpow(ll a, ll  b, ll  m){
    a %= m;
    ll ans = 1;
    while(b > 0){
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

ll divmod(ll a, ll b, ll m){
    return (a * binpow(b, m-2, m)) % m;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e6+5;
int cnt[N];
int lp[N]; // 0 if prime, 1 if not prime
vector<ll> pr[N];
const int nMOD = 3;
const ll aMOD[] = {(ll)1e9+7, (ll)1e9+9, (ll)1e9+123};
ll h[nMOD][N], iv[nMOD][N];
void sieve(){
    for(ll i=2; i<N; i++){
        if(!lp[i]){
            for(ll j = i; j < N; j += i){
                if(!lp[j]) lp[j] = i;
            }
            for(int j=0;j<nMOD;j++){
                h[j][i] = uniform_int_distribution<int>(2, 1000000000)(rng);
                iv[j][i] = divmod(1, h[j][i], aMOD[j]);
            }
        }
    }
    for(int i=2;i<N;i++){
        int cp = lp[i], cnt = 1;
        int aux = i;
        while(aux != 1){
            aux /= cp;
            if(lp[aux] == cp) cnt++;
            else{
                cnt %= 3;
                for(int j=0;j<cnt;j++) pr[i].push_back(cp);
                cp = lp[aux];
                cnt = 1;
            }
            
        }
        
    }
}

//hashhhh!!!
ll ch[nMOD][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    sieve();
    int  n, q;
    cin >> n >> q;
    ch[0][0] = ch[1][0] = ch[2][0]  = 1;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        for(int j=0;j<nMOD;j++) ch[j][i] = ch[j][i-1];
        for(auto x : pr[x]){
            cnt[x]++;
            if(cnt[x] == 3) cnt[x] = 0;
            for(int j=0;j<nMOD;j++){
                if(cnt[x] == 0){
                    ch[j][i] = (ch[j][i] * iv[j][x]) % aMOD[j];
                    ch[j][i] = (ch[j][i] * iv[j][x]) % aMOD[j];
                }else{
                    ch[j][i] = (ch[j][i] * h[j][x]) % aMOD[j];
                }
            }
        }
    }
    


    for(int i=1;i<=q;i++){
        int a, b;
        cin >> a >> b;
        bool ok = true;
        for(int j=0;j<nMOD;j++){
            if(ch[j][a-1] != ch[j][b]) ok = false;
        }
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }
    
}
