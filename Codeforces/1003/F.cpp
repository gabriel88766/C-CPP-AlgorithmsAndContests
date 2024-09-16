#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+5; //substrings of a string of len 1505

int cntn = 0;
int trie[N][26];

int add(int node, char c){
    c -= 'a';
    if(trie[node][c]) return trie[node][c];
    else return trie[node][c] = ++cntn;
}

//example add string
int add(string s){
    int curn = 0;
    for(auto c : s) curn = add(curn, c);
    return curn;
}

int src = 0, dst = 100000;
vector<int> adj[N];
int indg[N];
int sz[N];
int dp[N];
int nd[305];
int plen[305];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        string s;
        cin >> s;
        nd[i] = add(s);
        plen[i] = s.size();
        plen[i] += plen[i-1];
        if(i > 1) plen[i]++;
    }
    //300*300*300 is allowed
    //node [i, d] = i*n + d
    
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int d=1;;d++){
                if(i+d-1 == j) break;
                if(j + d - 1 > n) break;
                if(nd[i+d-1] == nd[j+d-1]){
                    indg[j*n+d]++;
                    adj[i*n+d].push_back(j*n+d);
                }else break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int d=1;d<=n;d++){
            if(i + d - 1 > n) break;
            sz[i*n+d] = plen[i+d-1] - plen[i-1] - (i == 1 ? 0 : 1) - d;
            adj[src].push_back(i*n+d);
            if(indg[i*n+d]){ adj[i*n+d].push_back(dst);}
        }
    }
    for(int i=0;i<99999;i++){
        for(auto j : adj[i]){
            dp[j] = max(dp[j], dp[i] + sz[i]);
        }
    }
    cout << plen[n] - dp[dst] << "\n";
}
