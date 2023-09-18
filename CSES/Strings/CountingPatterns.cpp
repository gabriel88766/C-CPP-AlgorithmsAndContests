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
    vector<int> h;
    vector<bool> isFinal;
    int c = 0;
    void add(const string &s){
        int cur = 0;
        for(int i = 0; i < s.size(); i++){
            if(trie[cur][s[i]-'a']) cur = trie[cur][s[i]-'a'];
            else cur = trie[cur][s[i]-'a'] = ++c;
            h[cur] = i+1;
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
        h = vector<int>(maxlen, 0);
        trie = vector<vector<int>>(maxlen, vector<int>(26, 0));
        slink = vector<int>(maxlen, 0);
        for(auto x : v) add(x);
        addLink();
    }
    //count occurences of all reachable states in the trie
    vector<int> CountPatterns(string &s){
        vector<int> dp(len, 0);
        set<pair<int,int>> st; // :(
        int cur = 0;
        dp[0] = 1;
        for(int i=0;i<s.size();i++){
            while(cur && !trie[cur][s[i]-'a']) cur = slink[cur];
            cur = trie[cur][s[i]-'a'];
            if(!dp[cur]){
                dp[cur] = 1;
                st.insert({h[cur], cur});
            }else dp[cur]++;
        }
        while(!st.empty()){
            int u = (*prev(st.end())).second;
            st.erase(prev(st.end()));
            if(slink[u]){
                if(!st.count({h[slink[u]], slink[u]})){
                    st.insert({h[slink[u]], slink[u]});
                }
            }
            dp[slink[u]] += dp[u];
        }
        return dp;
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
    auto res = hoho.CountPatterns(s);
    
    for(int i=0;i<n;i++){
        cout << res[hoho.get(v[i])] << "\n";
    }
}
