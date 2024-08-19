#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 6200000, M = 30; // log aMax * Q (2e5 * 19, for example)
int c1 = 0, c2 = 0;
int trie[2][N][2];
int sz[2][N];
const int Ng = 2e5+1;
vector<int> adj[Ng], adjw[Ng];
int h[Ng], xv[Ng];

bool get(int t, int num){
    int cur = 0;
    for(int i=M-1;i >= 0; i--){
        if(trie[t][cur][(num & (1 << i)) >> i]){
            cur = trie[t][cur][(num & (1 << i)) >> i];
        }else return false;
    }
    return true;
}
void insert(int t, int num){
    auto &c = (t == 0 ? c1 : c2);
    int cur = 0;
    for(int i=M-1;i >= 0; i--){
        sz[t][cur]++;
        if(trie[t][cur][(num & (1 << i)) >> i]){
            cur = trie[t][cur][(num & (1 << i)) >> i];
        }else cur = trie[t][cur][(num & (1 << i)) >> i] = ++c;
    }
    sz[t][cur]++;
}

void remove(int t, int num){
    int cur = 0;
    for(int i=M-1;i>=0;i--){
        sz[t][cur]--;
        cur = trie[t][cur][(num & (1 << i)) >> i];
    }
    sz[t][cur]--;
    cur = 0;
    for(int i=M-1;i>=0;i--){
        int nxt = trie[t][cur][(num & (1 << i)) >> i];
        if(sz[t][nxt] == 0){
            trie[t][cur][(num & (1 << i)) >> i] = 0;
        }
        cur = nxt;
    }
}

int maxxor(int t, int num){
    int cur = 0;
    int key = 0;
    for(int i=M-1;i>=0;i--){
        int b = (num & (1 << i)) >> i;
        if(trie[t][cur][b^1]){
            cur = trie[t][cur][b^1];
            if(b^1) key ^= (1 << i);
        }else{
            cur = trie[t][cur][b];
            if(b) key ^= (1 << i);
        }
    }
    return key ^ num;
}

void clear(int n){
    for(int i=0;i<=c1;i++){
        trie[0][i][0] = trie[0][i][1] = sz[0][i] = 0;
    }
    for(int i=0;i<=c2;i++){
        trie[1][i][0] = trie[1][i][1] = sz[1][i] = 0;
    }
    c1 = c2 = 0;
    for(int i=1;i<=n;i++){
        adj[i].clear();
        adjw[i].clear();
        h[i] = xv[i] = 0;
    }
}

void dfsi(int u, int p){
    h[u] = h[p] + 1;
    for(int i=0;i<adj[u].size();i++){
        if(adj[u][i] != p){
            xv[adj[u][i]] = xv[u]  ^ adjw[u][i];
            dfsi(adj[u][i], u);
        }
    }
    insert(h[u] % 2, xv[u]);
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i=1;i<n;i++){
            int a, b, w;
            cin >> a >> b >> w;
            adj[a].push_back(b);
            adj[b].push_back(a);
            adjw[a].push_back(w);
            adjw[b].push_back(w);
        }
        h[0] = -1;
        dfsi(1, 0);
        int msk = 0, p = 0;
        for(int i=0;i<m;i++){
            char c;
            cin >> c;
            if(c == '^'){
                int x;
                cin >> x;
                msk ^= x;
            }else{
                int u, x;
                cin >> u >> x;
                remove(h[u] % 2, xv[u]);
                int ans1, ans2;
                int par = h[u] % 2;
                ans1 = maxxor(par, x^xv[u]);
                ans2 = maxxor(par^1, x^msk^xv[u]);
                cout << max(ans1, ans2) << " ";
                insert(h[u] % 2, xv[u]);
            }
        }
        cout << "\n";
        clear(n);
    }
}
