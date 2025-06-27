#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


struct Aho{ //declare once! too much memory
    int len;
    vector<vector<int>> trie;
    vector<int> slink;
    vector<bool> isDesc;
    vector<bool> vis;
    int c = 0;
    void add(const string &s){
        int cur = 0;
        for(int i = 0; i < s.size(); i++){
            if(trie[cur][s[i]-'a']) cur = trie[cur][s[i]-'a'];
            else cur = trie[cur][s[i]-'a'] = ++c;
        }
        isDesc[cur] = true;
    }
    int get(const string &s){
        int cur = 0;
        for(int i = 0; i < s.size(); i++) cur = trie[cur][s[i]-'a'];
        return cur;
    }
    void addLink(){
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int i=0;i<26;i++){
                if(trie[u][i]){
                    q.push(trie[u][i]);
                    if(u){
                        int v = slink[u];
                        while(v && !trie[v][i]) v = slink[v];
                        slink[trie[u][i]] = trie[v][i];
                    }
                }
            }
        }
    }

    bool dfs(int u){
        if(vis[u] || isDesc[u]) return isDesc[u];
        vis[u] = true;
        return isDesc[u] = dfs(slink[u]);
    }

    //mark all descendants of a final node.
    void markDesc(vector<string> &v){
        for(int i=0;i<v.size();i++){
            int cn = get(v[i]);
            isDesc[cn] = true;
        }
        for(int i=0;i<isDesc.size();i++){
            if(dfs(i)) isDesc[i] = true;
        }
    }
    Aho(vector<string> &v, int maxlen){
        len = maxlen;
        trie = vector<vector<int>>(maxlen, vector<int>(26, 0));
        slink = vector<int>(maxlen, 0);
        isDesc = vector<bool>(maxlen, false);
        vis = vector<bool>(maxlen, false);
        for(auto x : v) add(x);
        addLink();
        markDesc(v);
    }
};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s;
    int n;
    cin >> s >> n;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    Aho hoho(v, 500001);
    int ans = 0;
    int cn = 0;
    for(int i=0;i<s.size();i++){
        while(cn && (!hoho.trie[cn][s[i]-'a'])) cn = hoho.slink[cn];
        cn = hoho.trie[cn][s[i]-'a'];
        if(hoho.isDesc[cn]){
            ans++;
            cn = 0;
        }
    }
    cout << ans << "\n";
}
