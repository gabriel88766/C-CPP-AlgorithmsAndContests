#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 2e5+5;
int mi[N], lp[N];
ll ans[N];
ll aux[N];
ll aux2[N];
vector<pair<int,int>> pr[N];
void sieve(){
    for(ll i=1;i<N;i++) mi[i] = 1;
    for(ll i=2; i<N; i++){
        if(!lp[i]){
            for(ll j=i;j<N;j+=i){
                mi[j] *= -1;
                if(!lp[j]) lp[j] = i;
            }
            for(ll j = i*i; j < N; j += i*i){
                mi[j] = 0;
            }
        }
    }
    for(int i=2;i<N;i++){
        int aux = i;
        int llp = -1;
        vector<int> cp;
        while(aux != 1){
            if(llp != lp[aux]){
                llp = lp[aux];
                cp.push_back(llp);
            }
            aux /= llp;
        }
        for(int j=1;j<(1 << cp.size());j++){
            int cf = 1;
            for(int k=0;k<cp.size();k++){
                if(j & (1 << k)) cf *= cp[k];
            }
            if(__builtin_popcount(j) % 2) pr[i].push_back({cf, 1});
            else pr[i].push_back({cf, -1});
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    sieve();
    int n;
    cin >> n;
    vector<int> p(n+1);
    for(int i=1;i<=n;i++) cin >> p[i];

    for(int i=2;i<=n;i++){
        vector<int> cur;
        for(int j=i;j<=n;j+=i) cur.push_back(p[j]);
        //solve for this cur

        for(auto &x : cur){
            for(auto &[y, s] : pr[x]){
                aux2[y]++;
                aux[i] += aux2[y] * s;
            }
        }
        

        for(auto &x : cur){
            for(auto &[y, s] : pr[x]){
                aux2[y] = 0;
            }
        }

    }
    ll tt = 0;
    for(int i=2;i<=n;i++){
        for(int j=1;i*j<=n;j++){
            ans[i] += mi[j] * aux[i*j];
        }
        tt += ans[i];
    }
    cout << tt << "\n";
}
