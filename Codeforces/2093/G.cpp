#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 6200005, M = 30; // log aMax * Q (2e5 * 19, for example)
int cnt = 0;
int trie[N][2];
int sz[N], mn[N];

bool get(int num){
    int cur = 0;
    for(int i=M-1;i >= 0; i--){
        if(trie[cur][(num & (1 << i)) >> i]){
            cur = trie[cur][(num & (1 << i)) >> i];
        }else return false;
    }
    return true;
}
void insert(int num, int idx){
    if(get(num)) return;
    int cur = 0;
    for(int i=M-1;i >= 0; i--){
        mn[cur] = min(mn[cur], idx);
        sz[cur]++;
        if(trie[cur][(num & (1 << i)) >> i]){
            cur = trie[cur][(num & (1 << i)) >> i];
        }else cur = trie[cur][(num & (1 << i)) >> i] = ++cnt;
    }
    mn[cur] = min(mn[cur], idx);
    sz[cur]++;
}

void remove(int num){
    if(!get(num)) return;
    vector<int> adj = {0};
    int cur = 0;
    for(int i=M-1;i>=0;i--){
        sz[cur]--;
        cur = trie[cur][(num & (1 << i)) >> i];
        adj.push_back(cur);
    }
    sz[cur]--;
    cur = 0;
    for(int i=M-1;i>=0;i--){
        int nxt = trie[cur][(num & (1 << i)) >> i];
        if(sz[nxt] == 0){
            trie[cur][(num & (1 << i)) >> i] = 0;
        }
        cur = nxt;
    }
    reverse(adj.begin(), adj.end());
    for(auto &x : adj){
        if(trie[x][0] && trie[x][1]) mn[x] = min(mn[trie[x][0]], mn[trie[x][1]]);
        else if(trie[x][0]) mn[x] = mn[trie[x][0]];
        else if(trie[x][1]) mn[x] = mn[trie[x][1]];
        else mn[x] = INF_INT;
    }
}

int k;

int getK(int num, int cur = 0, int b = M-1){
    if(b == -1){
        return mn[cur];
    }
    int ofs = 1 << b;
    int mxx = (num ^ ofs) | (ofs - 1);
    int mnx = (num ^ ofs) & (~(ofs - 1));
    int mxnx = num | (ofs - 1);
    int mnnx = num & (~(ofs - 1));
    int ans = INF_INT;
    if(k <= mnx){
        if(trie[cur][1]) ans = min(ans, mn[trie[cur][1]]);
    }else if(k <= mxx){
        if(trie[cur][1]) ans = min(ans, getK(num ^ ofs, trie[cur][1], b-1));
    }
    if(k <= mnnx){
        if(trie[cur][0]) ans = min(ans, mn[trie[cur][0]]);
    }else if(k <= mxnx){
        if(trie[cur][0]) ans = min(ans, getK(num, trie[cur][0], b-1));
    }
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    memset(mn, 63, sizeof(mn));
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n >> k;
        map<int, vector<int>> mp;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++){
            cin >> v[i];
        }
        for(int i=n;i>=1;i--){
            mp[v[i]].push_back(i);
        }
        for(auto &[x, v] : mp){
            insert(x, v.back());
        }
        int ans = INF_INT;
        for(int i=1;i<=n;i++){
            int x = getK(v[i]);
            if(x != INF_INT) ans = min(ans, x - i + 1);
            remove(v[i]);
            mp[v[i]].pop_back();
            if(mp[v[i]].size()) insert(v[i], mp[v[i]].back());
        }
        if(ans == INF_INT) ans = -1;
        cout << ans << "\n";
        //clear
        for(int i=0;i<=cnt;i++){
            mn[i] = INF_INT;
            trie[i][0] = trie[i][1] = 0;
            sz[i] = 0;
        }
        cnt = 0;
    }
}
