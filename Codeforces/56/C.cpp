#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

string s;
int cnt = 0;
map<int, string> mp;
vector<int> adj[2000];
int pos = 0;
void make_tree(int u){
    string name = "";
    while(s[pos] >= 'A' && s[pos] <= 'Z'){
        name += s[pos++];
        mp[u] = name;
    }
    if(s[pos] == ':'){
        pos++;
        while(s[pos] != '.'){
            int v = ++cnt;
            adj[u].push_back(v);
            make_tree(v);
            if(s[pos] == ',') pos++;
        }
    }
    if(s[pos] == '.') pos++;
}

int dfs(int u, int x){
    int val = 0;
    for(auto v : adj[u]){
        if(v != x && mp[v] == mp[x]) val++;
        val += dfs(v, x);
    }
    return val;

}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> s;
    make_tree(++cnt);
    int ans = 0;
    for(int i=1;i<=cnt;i++){
        ans += dfs(i, i);
    }
    cout << ans << "\n";
}
