#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    string s, t;
    cin >> n;
    cin >> s >> t;
    if(s == t){
        cout << "0\n";
        return 0;
    }
    vector<vector<int>> pl(26);
    for(int i=0;i<s.size();i++){
        pl[s[i]-'a'].push_back(i);
    }
    vector<int> adj(26, -1), indg(26, 0);
    bool ok = true;
    for(int i=0;i<26;i++){
        if(pl[i].size()){
            char c = t[pl[i][0]];
            for(int j=1;j<pl[i].size();j++){
                if(c != t[pl[i][j]]) ok = false;
            }
            indg[c - 'a']++;
            adj[i] = c-'a';
        }
    }
    if(ok){
        bool cok = false;
        for(int i=0;i<26;i++){
            if(indg[i] == 0) cok = true;
        }
        ok = cok;
    }
    if(ok){
        //solve
        vector<bool> vis(26, false);
        int ans = 0;
        for(int i=0;i<26;i++){
            if(vis[i]) continue;
            if(adj[i] == i){
                vis[i] = true;
                continue;
            }
            int cur = i;
            int cnt = 0;
            while(adj[cur] != -1){
                cur = adj[cur];
                cnt++;
                if(cur == i || cnt > 26) break;
            }
            bool chk = false;
            if(cur == i && adj[cur] != -1){
                ans += cnt;
                vis[cur] = true;
                if(indg[cur] > 1) chk = true;
                while(adj[cur] != i){
                    cur = adj[cur];
                    if(indg[cur] > 1) chk = true;
                    vis[cur] = true;
                }
                if(!chk) ans++;
            }
        }
        for(int i=0;i<26;i++){
            if(!vis[i]){
                if(adj[i] != -1) ans++;
            }
        }
        cout << ans << "\n";
    }else cout << "-1\n";
}
