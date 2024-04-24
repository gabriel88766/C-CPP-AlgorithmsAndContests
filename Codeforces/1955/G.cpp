#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 1e6+5;
vector<int> divs[N];
void init(){
    for(ll i=1; i<N; i++){
        for(ll j=i;j<N;j+=i){
            divs[j].emplace_back(i);
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> v[i][j];
            }
        }
        int g = gcd(v[0][0], v[n-1][m-1]);
        
        int ans = 1;
        for(auto div : divs[g]){
            queue<pair<int,int>> q;
            q.push({0, 0});
            bool ok = false;
            vector<vector<bool>> vis(n, vector<bool>(m));
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
            if(ok) ans = max(ans, div);
        }
        cout << ans << "\n";


    }
}
