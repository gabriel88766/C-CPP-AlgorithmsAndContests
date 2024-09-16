#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int M = 20;
const int N = 2e5+3;
int jp[N][M], a[N];
int vis[N], ans[N];
int cg[N];
/*
int p[N], lp[N]; 
void sieve(){
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = i*i; j < N; j += i){
                p[j] = 1; //marking all multiples of i as not prime
            }
            for(ll j = i; j < N; j += i){
                if(!lp[j]) lp[j] = i;
            }
        }
    }
}*/
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    //sieve();
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> jp[i][0];
    for(int j=1;j<M;j++){
        for(int i=1;i<=n;i++){
            jp[i][j] = jp[jp[i][j-1]][j-1];
        }
    }
    for(int i=1;i<=n;i++) cin >> a[i];
    set<int> us;
    for(int i=1;i<=n;i++){
        if(!(vis[i])){
            vector<int> cur;
            cur.push_back(i);
            while(jp[cur.back()][0] != i){
                cur.push_back(jp[cur.back()][0]);
            }
            for(auto x : cur) vis[x] = true;
            int len = cur.size();
            vector<int> pcg;
            if(!us.count(len)){
                map<int, int> mp;
                for(auto x : us){
                    int val = gcd(len, x);
                    int ccg = cg[x] % val;
                    if(val != 1){
                        if(mp.count(val)) assert(mp[val] == ccg);
                        else mp[val] = ccg;
                    }
                }
                for(int j=0;j<len;j++){
                    bool ok = true;
                    for(auto [k, v] : mp){
                        if(j % k != v) ok = false;
                    }
                    if(ok) pcg.push_back(j);
                }
                pair<int,int> bst = {INF_INT, INF_INT};
                for(auto x : pcg){
                    if(a[cur[x]] < bst.first){
                        bst = {a[cur[x]], x};
                    }
                }
                cg[len] = bst.second;
                us.insert(len);
            }
            for(auto x : cur){
                ans[x] = x;
                for(int j=0;j<M;j++){
                    if(cg[len] & (1 << j)) ans[x] = jp[ans[x]][j];
                }
                ans[x] = a[ans[x]];
            }
        }
    }
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
    cout << "\n";
}
