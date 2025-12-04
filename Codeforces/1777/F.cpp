#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 6200000, M = 30; // log aMax * Q (2e5 * 19, for example)
int cnt = 0;
int trie[N][2]; 
int *pv[200005][31];
int sz[N];

void insert(int num, int j){
    int cur = 0;
    pv[j][M] = &sz[cur];
    for(int i=M-1;i >= 0; i--){
        // sz[cur]++;
        if(trie[cur][(num & (1 << i)) >> i]){
            cur = trie[cur][(num & (1 << i)) >> i];
        }else cur = trie[cur][(num & (1 << i)) >> i] = ++cnt;
        pv[j][i] = &sz[cur];
    }
    // sz[cur]++;
}

void clear(){
    for(int i=0;i<=cnt;i++){
        sz[i] = trie[i][0] = trie[i][1] = 0;
    }
    cnt = 0;
}


int maxxor(int num){
    int cur = 0;
    int key = 0;
    for(int i=M-1;i>=0;i--){
        int b = (num & (1 << i)) >> i;
        if(trie[cur][b^1] && sz[trie[cur][b^1]]){
            cur = trie[cur][b^1];
            if(b^1) key ^= (1 << i);
        }else{
            cur = trie[cur][b];
            if(b) key ^= (1 << i);
        }
    }
    return key ^ num;
}

int ps[200005];
int n;
//BELOW A new Mo template
constexpr int BLOCK = 500;
struct Query{
    int l, r, c, d, e;
    bool operator< (const Query u) const {
        if(l/BLOCK != u.l/BLOCK) return l/BLOCK < u.l/BLOCK;
        else return r < u.r;
    }
};

template<typename T, void (*erase)(), void (*insert)(int), void (*remove)(int), T (*get)(int)>
struct Mo{
    vector<Query> vq;
    int ans = 0;
    static constexpr int sqrtN = BLOCK; //adjust accordingly with Q value. Compile time to increase performance
    Mo(vector<Query> &allq){ 
        vq = allq;
        sort(vq.begin(), vq.end());
    }
    void solve(){ 
        int blk = -1, p = 0;
        ll cur = 0;
        for(auto x : vq){
            if((x.l/sqrtN)*sqrtN != blk){
                cur = 0;
                blk = p = (x.l/sqrtN)*sqrtN; //first element of block
                erase(); //once each block O(N * sqrtN) overall
            }
            while(p <= x.r){ //from 0 to n, sqrt(N) times
                insert(p++); //insert information about p;
            }
            for(int i=blk;i<x.l;i++){ //O(sqrt(N))
                remove(i);
            }
            for(int j = x.c; j <= x.d; j++){
                int cur = get(x.e ^ ps[j]);
                ans =  max(ans, cur);
            }
            for(int i=blk;i<x.l;i++){ //O(sqrt(N))
                insert(i);
            }      
        }
    }
};  

//These functions must be changed.
vector<Query> vx;
// int v[N], cnt[N]; //data stored

void erase(){
    //erase the whole DS; must be O(n) most of times
    for(int i=0;i<=n;i++){
        for(int j=0;j<=30;j++){
            *pv[i][j] = 0;
        }
    }
}
void insert(int p){
    //insert index p, must be O(1) most of times
    for(int j=0;j<=30;j++){
        *pv[p][j] = *pv[p][j] + 1;
    }
}

void remove(int p){
    //remove index p, must be O(1) most of times
    for(int j=0;j<=30;j++){
        *pv[p][j] = *pv[p][j] - 1;
    }
}

//must be same return type
int get(int j){
    //LOGIC to get the answer to determined index.
    //Up to O(sqrt(n))
    return maxxor(j);
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        vector<pair<int, int>> vp;
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            ps[i] = ps[i-1] ^ x;
            vp.push_back({x, i});
        }
        sort(vp.begin(), vp.end(), greater<pair<int, int>>());
        set<int> bds;
        bds.insert(0);
        bds.insert(n+1);
        vx.clear();
        
        vector<tuple<int, int, int, int, int>> qr;
        for(auto [a, b] : vp){
            auto it = bds.lower_bound(b);
            int l = *prev(it) + 1;
            int r = *it - 1;
            int sz1 = b - l + 1;
            int sz2 = r - b + 1;
            if(sz1 < sz2){
                vx.push_back({b, r, l-1, b-1, a});
            }else{
                vx.push_back({l-1, b-1, b, r, a});
            }
            bds.insert(b);
        }
        Mo<int, erase, insert, remove, get> mo(vx);
        //solve
        for(int i=0;i<=n;i++){
            insert(ps[i], i);
        }
        mo.solve();
        cout << mo.ans << "\n";

        clear();
    }
}
