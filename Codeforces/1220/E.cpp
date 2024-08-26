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
    vector<int> qnt;
    int c;
    void add(const string &s){
        int cur = 0;
        for(int i = 0; i < s.size(); i++){
            if(trie[cur][s[i]-'a']) cur = trie[cur][s[i]-'a'];
            else cur = trie[cur][s[i]-'a'] = ++c;
        }
        isFinal[cur] = true;
        qnt[cur]++;
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
                        qnt[trie[u][i]] += qnt[trie[v][i]];
                    }
                }
            }
        }
    }
    Aho(vector<string> &v, int maxlen){
        c = 0;
        len = maxlen;
        isFinal = vector<bool>(maxlen, false);
        qnt = vector<int>(maxlen, 0);
        trie = vector<vector<int>>(maxlen, vector<int>(26, 0));
        slink = vector<int>(maxlen, 0);
        for(auto x : v) add(x);
        addLink();
    }
    //mark all reachable states in the trie
    vector<int> CheckText(string &s){
        vector<int> st;
        int cur = 0;
        for(int i=0;i<s.size();i++){
            while(cur && !trie[cur][s[i]-'a']) cur = slink[cur];
            cur = trie[cur][s[i]-'a'];
            st.push_back(cur);
        }
        return st;
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
    vector<string> v(n), v2(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
        v2[i] = v[i];
        reverse(v2[i].begin(), v2[i].end());
    }
    Aho hoho(v, 200005);
    Aho hoho2(v2, 200005);
    ll ans = 0;
    auto vt = hoho.CheckText(s);
    vector<ll> pr(s.size()), su(s.size());
    for(int i=0;i<s.size();i++){
        //current state = vt[i] 
        pr[i] = hoho.qnt[vt[i]];
    }
    reverse(s.begin(), s.end());
    vt = hoho2.CheckText(s);
    for(int i=0;i<s.size();i++){
        su[s.size()-i-1] = hoho2.qnt[vt[i]];
    }
    for(int i=0;i<s.size()-1;i++){
        ans += pr[i]*su[i+1];
    }
    cout << ans << "\n";
}
