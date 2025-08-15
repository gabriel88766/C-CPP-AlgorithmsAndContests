#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1002*402; //substrings of a string of len 1505

int cntn = 0;
int trie[N][27];
int lab[N];
int mp[256]; //mapping letter to position in trie

int add(int node, char c){
    if(trie[node][mp[c]]) return trie[node][mp[c]];
    else return trie[node][mp[c]] = ++cntn;
}

int get(string s){
    int curn = 0;
    for(auto c : s){
        if(trie[curn][mp[c]]) curn = trie[curn][mp[c]];
        else{
            curn = -1;
            break;
        }
    }
    if(curn == -1) return -1;
    else return lab[curn];
}

//example add string
void add(string s, int num){
    int curn = 0;
    for(auto c : s) curn = add(curn, c);
    lab[curn] = num;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(char a = 'a';a<='z';a++) mp[a] = a - 'a';
    mp['_'] = 26;
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> pat(n+1);
    for(int i=1;i<=n;i++){
        cin >> pat[i];
        add(pat[i], i);
    }
    bool ok = true;
    vector<vector<int>> adj(n+1);
    vector<int> in(n+1);
    for(int i=1;i<=m;i++){
        string s;
        int j;
        cin >> s >> j;
        bool mat = true;
        for(int u=0;u<k;u++){
            if(s[u] == pat[j][u] || pat[j][u] == '_'); //ok
            else{ 
                mat = false;
            }
        }
        if(!mat) ok = false;
        else{
            for(int u=0;u<16;u++){
                string cs = s;
                for(int v=0;v<4;v++){
                    if(u & (1 << v)) cs[v] = '_';
                }
                if(cs == pat[j]) continue;
                int vx = get(cs);
                if(vx != -1){
                    //string in trie
                    adj[j].push_back(vx);
                    in[vx]++;
                }
            }
        }
    }
    if(ok){
        queue<int> q;
        vector<int> ans;
        for(int i=1;i<=n;i++){
            if(in[i] == 0){
                ans.push_back(i);
                q.push(i);
            }
        }
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            for(auto v : adj[u]){
                assert(v <= n && v >= 1);
                in[v]--;
                if(in[v] == 0){
                    q.push(v);
                    ans.push_back(v);
                }
            }
        }
        if(ans.size() == n){
            cout << "YES\n";
            for(auto x : ans) cout << x << " ";
            cout << "\n"; 
        }else cout << "NO\n";
    }else cout << "NO\n";
}
