#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+5;
int lp[N];
void sieve(){
    for(ll i=2; i<N; i++){
        if(lp[i] == 0){
            for(int j=i;j<N;j+=i){
                if(!lp[j]) lp[j] = i;
            }
        }
    }
}

int v[105][105];
bool vis[105][105];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    sieve();
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> v[i][j];
            }
        }
        int g = gcd(v[0][0], v[n-1][m-1]);
        
        auto bfs = [&](int div){
            queue<pair<int,int>> q;
            q.push({0, 0});
            bool ok = false;
            for(int i=0;i<n;i++) for(int j=0;j<m;j++) vis[i][j] = false;
            while(!q.empty()){
                auto [x, y] = q.front();
                q.pop();
                if(x == n-1 && y == m-1) ok = true;
                else{
                    if(x != n-1){
                        if(!vis[x+1][y] && !(v[x+1][y] % div)){
                             q.push({x+1, y});
                             vis[x+1][y] = true;
                        }
                    }
                    if(y != m-1){
                        if(!vis[x][y+1] && !(v[x][y+1] % div)){
                            q.push({x, y+1});
                            vis[x][y+1] = true;
                        }
                    }
                }
            }
            return ok;
        };
        vector<int> fs;
        auto aux = g;
        while(aux != 1){
            if(!fs.size() || fs.back() != lp[aux]) fs.push_back(lp[aux]);
            aux /= lp[aux];
        }
        queue<int> q;
        map<int, bool> visx;
        q.push(1);
        visx[1] = true;
        int ans = 1;
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            ans = max(ans, u);
            for(auto x : fs){
                if(g/x >= u){
                    int v = u * x;
                    if(g % v) continue;
                    if(visx.count(v)) continue;
                    if(bfs(v)){
                        q.push(v);
                        visx[v] = true;
                    }
                }
            }
        }
        cout << ans << "\n";


    }
}
