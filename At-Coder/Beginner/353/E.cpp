#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 1002*1002; //substrings of a string of len 1505

int cntn = 0;
int trie[N][26];
int cnt[N];
// h[N];

int add(int node, char c){
    c -= 'a';
    if(trie[node][c]) return trie[node][c];
    else return trie[node][c] = ++cntn;
}

//example add string
void add(string s){
    int curn = 0;
    cnt[curn]++;
    for(auto c : s){
         curn = add(curn, c);
         cnt[curn]++;
    }
}

ll ans = 0;
void dfs(int u){
    for(int j=0;j<26;j++){
        if(trie[u][j]){
            // h[trie[u][j]] = h[u] + 1;
            dfs(trie[u][j]);
        }
    }
    if(cnt[u] > 1 && u != 0){
        ll xx = cnt[u];
        xx *= (cnt[u] - 1);
        xx /= 2;
        ans += xx;
    }

}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<string> vs(n+1);
    for(int i=1;i<=n;i++){
        cin >> vs[i];
        add(vs[i]);
    }
    dfs(0);
    // h[0] = 0;
    cout << ans << "\n";

}
