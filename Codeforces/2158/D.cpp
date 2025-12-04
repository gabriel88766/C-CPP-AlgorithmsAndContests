
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

string str[] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011",
                    "1100", "1101", "1110", "1111"};
pair<int, int> adj[16][16];
int dist[16][16];
int par[16][16];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    //init!
    for(int i=0;i<16;i++){
        for(int l=0;l<=2;l++){
            for(int r = l + 1; r <= 3; r++){
                string cs = str[i].substr(l, r - l + 1);
                string rev = cs;
                reverse(cs.begin(), cs.end());
                
                if(rev == cs){
                    string ns = str[i];
                    for(int u = l; u <= r; u++){
                        if(ns[u] == '0') ns[u] = '1';
                        else ns[u] = '0';
                    }
                    for(int u=0;u<16;u++){
                        if(str[u] == ns){
                            adj[i][u] = {l, r};
                        }
                    }
                }
            }
        }
    }
    memset(dist, 63, sizeof(dist));
    for(int i = 0; i < 16; i++){
        queue<int> q;
        q.push(i);
        dist[i][i] = 0;
        while(q.size()){
            auto u = q.front();
            q.pop();
            for(int j=0;j<16;j++){
                if(adj[u][j] != make_pair(0, 0) && dist[i][j] > dist[i][u] + 1){
                    dist[i][j] = dist[i][u] + 1;
                    par[i][j] = u;
                    q.push(j);
                }
            }
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        string s, g;
        cin >> n >> s >> g;
        vector<pair<int, int>> ans;
        auto change = [&](){
            auto [l, r] = ans.back();
            assert(l != r);
            for(int u=l-1;u<=r-1;u++){
                if(s[u] == '1') s[u] = '0';
                else s[u] = '1';
            }
        };
        for(int i=0;i<=n-5;i++){
            if(s[i] != g[i]){
                string cs = s.substr(i, 4);
                int cn = -1;
                for(int u=0;u<16;u++) if(cs == str[u]) cn = u;
                int nn = -1;
                for(int u=0;u<16;u++){
                    if((cn & 8) == (u & 8)) continue;
                    if(nn == -1 || dist[cn][u] < dist[cn][nn]) nn = u;
                }
                assert(nn != -1 && dist[cn][nn] <= 2);
                if(adj[cn][nn] == make_pair(0, 0)){
                    int im = par[cn][nn];
                    ans.push_back({adj[cn][im].first + i + 1, adj[cn][im].second + i + 1});
                    change();
                    ans.push_back({adj[im][nn].first + i + 1, adj[im][nn].second + i + 1});
                    change();
                }else{
                    ans.push_back({adj[cn][nn].first + i + 1, adj[cn][nn].second + i + 1});
                    change();
                }
            }
        }
        //to finish, must choose {n-4 n-3 n-2 n-1}
        vector<int> path;
        string cn = s.substr(n - 4, 4);
        string fn = g.substr(n - 4, 4);
        int cnn = -1, fnn = -1;
        for(int u = 0; u < 16; u++){
            if(cn == str[u]) cnn = u;
            if(fn == str[u]) fnn = u;
        }
        path.push_back(fnn);
        while(fnn != cnn){
            path.push_back(par[cnn][fnn]);
            fnn = par[cnn][fnn];
        }
        reverse(path.begin(), path.end());
        for(int u=1;u<path.size();u++){
            int i1 = path[u-1];
            int i2 = path[u];
            ans.push_back({n-3 + adj[i1][i2].first, n - 3 + adj[i1][i2].second});
            change();
        }
        assert(s == g);
        cout << ans.size() << "\n";
        for(auto [x, y] : ans){
            cout << x << " " << y << "\n";
        }
    }
}
