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
    vector<bool> isFinal;
    int c = 0;
    void add(const string &s){
        int cur = 0;
        for(int i = 0; i < s.size(); i++){
            if(trie[cur][s[i]-'a']) cur = trie[cur][s[i]-'a'];
            else cur = trie[cur][s[i]-'a'] = ++c;
        }
        isFinal[cur] = true;
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
    Aho(vector<string> &v, int maxlen){
        len = maxlen;
        isFinal = vector<bool>(maxlen, false);
        trie = vector<vector<int>>(maxlen, vector<int>(26, 0));
        slink = vector<int>(maxlen, 0);
        for(auto x : v) add(x);
        addLink();
    }
    //mark all reachable states in the trie
    vector<bool> CheckText(string &s){
        vector<bool> canReach(len, false);
        queue<int> q;
        int cur = 0;
        canReach[0] = true;
        for(int i=0;i<s.size();i++){
            while(cur && !trie[cur][s[i]-'a']) cur = slink[cur];
            cur = trie[cur][s[i]-'a'];
            if(!canReach[cur]){
                canReach[cur] = true;
                q.push(cur);
            }
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(!canReach[slink[u]]){
                q.push(slink[u]);
                canReach[slink[u]] = true;
            }
        }
        return canReach;
    }
};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    Aho hoho(v, 500005);
    auto res = hoho.CheckText(s);
    
    for(int i=0;i<n;i++){
        if(res[hoho.get(v[i])]) cout << "YES\n";
        else cout << "NO\n";
    }
}
