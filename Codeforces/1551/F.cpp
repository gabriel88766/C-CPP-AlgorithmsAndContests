#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Mint{
    ll v;
    //static const int MOD = MOD_val;
    Mint(){ v = 0;}
    Mint(ll u){ v = (u >= 0 ? u % MOD : u % MOD + MOD);}
    Mint pow(ll u){
        Mint ans = 1;
        Mint aux = *this;
        while(u){
            if(u & 1) ans *= aux;
            aux *= aux;
            u >>= 1;
        }
        return ans;
    }
    friend Mint operator* (Mint a, Mint const &b){ return a *= b;}
    friend Mint operator/ (Mint a, Mint const &b){ return a /= b;}
    friend Mint operator+ (Mint a, Mint const &b){ return a += b;}
    friend Mint operator- (Mint a, Mint const &b){ return a -= b;}
    Mint operator*= (Mint u){ v = (u.v * v) % MOD; return *this;}
    Mint operator+= (Mint u){ v = (v+u.v >= MOD ? v+u.v-MOD : v+u.v); return *this;}
    Mint operator-= (Mint u){ v = (v-u.v < 0 ? v-u.v+MOD : v-u.v); return *this;}
    Mint operator/= (Mint u){ (*this) *= u.pow(MOD-2); return *this;}
    bool operator== (Mint u){ return v == u.v;}
    bool operator!= (Mint u){ return v != u.v;}
    friend ostream& operator<<(ostream& os, const Mint& num){
        os << num.v;
        return os;
    }
};

const int N = 105;
int d[N];
vector<int> adj[N];
int n, k;


Mint fat[N], invfat[N];
void init(){ //MOD must be prime
    fat[0] = invfat[N-1] = 1;
    for(int i=1;i<N;i++){
        fat[i] = fat[i-1]*i;
    }
    invfat[N-1] = 1/fat[N-1];
    for(int i=N-2;i>=0;i--) invfat[i] = invfat[i+1] * (i + 1);
}
Mint nCr(ll a, ll b){
    return fat[a]*invfat[a-b]*invfat[b];
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    init();
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i=1;i<=n;i++) adj[i].clear();
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        if(k == 2){
            cout << (n * (n-1))/2 << "\n";
            continue;
        }
        
        Mint ans = 0;
        
        for(int i=1;i<=n;i++){
            if(adj[i].size() < k) continue;
            vector<vector<int>> dcnt(adj[i].size(), vector<int>(n+1, 0));
            memset(d, 63, sizeof(d));
            d[i] = 0;
            for(int j=0;j<adj[i].size();j++){
                queue<int> q;
                q.push(adj[i][j]);
                d[adj[i][j]] = 1;
                while(!q.empty()){
                    auto u = q.front();
                    q.pop();
                    dcnt[j][d[u]]++;
                    for(auto v : adj[u]){
                        if(d[v] > d[u] + 1){
                            d[v] = d[u] + 1;
                            q.push(v);
                        }
                    }
                }
            }
            for(int j=1;j<=n;j++){
                int cnt = 0;
                vector<int> v;
                for(int c=0;c<adj[i].size();c++){
                    if(dcnt[c][j] > 0){
                        cnt++;
                        v.push_back(dcnt[c][j]);
                    }
                }
                if(cnt >= k){
                    vector<vector<Mint>> dp(v.size()+1, vector<Mint>(k+1));
                    dp[0][0] = 1;
                    for(int x=1;x<=v.size();x++){
                        dp[x][0] = 1;
                        for(int y=1;y<=k;y++){
                            dp[x][y] = dp[x-1][y] + dp[x-1][y-1]*v[x-1];
                        }
                    }
                    ans += dp[v.size()][k];
                }else break;
            }

        }





        cout << ans << "\n";
    }

}
