#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Mint{
    int v;
    // static const int MOD = MOD_val;
    Mint(){ v = 0;}
    Mint(int u){ 
        v = u % MOD;
        if (v < 0) v += MOD;
    }
    Mint pow(ll u) const{
        Mint ans = 1;
        Mint aux = *this;
        while(u){
            if(u & 1) ans *= aux;
            aux *= aux;
            u >>= 1;
        }
        return ans;
    }
    friend Mint operator* (Mint a, Mint const &b){ return a *= b;}
    friend Mint operator/ (Mint a, Mint const &b){ return a /= b;}
    friend Mint operator+ (Mint a, Mint const &b){ return a += b;}
    friend Mint operator- (Mint a, Mint const &b){ return a -= b;}
    Mint& operator*= (const Mint &u){ v = ((ll)u.v * v) % MOD; return *this;}
    Mint& operator+= (const Mint &u){ v = (v+u.v >= MOD ? v+u.v-MOD : v+u.v); return *this;}
    Mint& operator-= (const Mint &u){ v = (v-u.v < 0 ? v-u.v+MOD : v-u.v); return *this;}
    Mint& operator/= (const Mint &u){ (*this) *= u.pow(MOD-2); return *this;}
    bool operator== (const Mint &u) const { return v == u.v;}
    bool operator!= (const Mint &u) const { return v != u.v;}
    friend ostream& operator<<(ostream& os, const Mint& num){
        os << num.v;
        return os;
    }
};

const int N = 2e5+3;
constexpr int BLOCK = 500;

int pos[N];
vector<pair<int, int>> vxx;

Mint inv[N];
Mint v[N];
Mint bl[N/BLOCK+1];
ll va[N];
ll sum[N/BLOCK+1];
int n;

Mint query(int a, int b){
    if(a > b) return 1;
    int l = (a/BLOCK+1)*BLOCK;
    int r = (b/BLOCK)*BLOCK;
    Mint ans = 1;
    if(r <= l){
        for(int i=a;i<=b;i++) ans *= v[i];
    }else{
        for(int i=a;i<l;i++) ans *= v[i];
        for(int i=r;i<=b;i++) ans *= v[i];
        l /= BLOCK, r /= BLOCK;
        for(int i=l;i<r;i++){
            ans *= bl[i];
        }
    }
    return ans;
}

ll ts = 0;

void update(int pos, Mint val, int val2){ //PURS
    bl[pos/BLOCK] *= val;
    v[pos] *= val;
    ts += val2;
    va[pos] += val2;
    sum[pos/BLOCK] += val2;
}



struct Query{
    int l, r, i;
    ll k;
    bool operator< (const Query u) const {
        if(l/BLOCK != u.l/BLOCK) return l/BLOCK < u.l/BLOCK;
        else return r < u.r;
    }
};

template<typename T, void (*erase)(), void (*insert)(int), void (*remove)(int), T (*get)(ll)>
struct Mo{
    vector<Query> vq;
    vector<T> ans;
    static constexpr int sqrtN = BLOCK; //adjust accordingly with Q value. Compile time to increase performance
    Mo(vector<Query> &allq){ 
        vq = allq;
        sort(vq.begin(), vq.end());
        ans.resize(allq.size());
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
            for(int i=blk;i<x.l;i++){ 
                remove(i);
            }
            ans[x.i] = get(x.k);
            for(int i=blk;i<x.l;i++){ //O(sqrt(N))
                insert(i);
            }      
        }
    }
};  

vector<Query> vx;

void erase(){
    for(int i=1;i<=n;i++){
        v[i] = 1;
        bl[i/BLOCK] = 1;
        va[i] = 0;
        sum[i/BLOCK] = 0;
    }
    ts = 0;
}
void insert(int p){
    if(p == 0) return;
    update(pos[p], vxx[pos[p]].first, vxx[pos[p]].first - 1);
}

void remove(int p){
    if(p == 0) return;
    update(pos[p], inv[pos[p]], -vxx[pos[p]].first + 1);
}

Mint get(ll k){
    if(ts <= k) return 1;
    else{
        int blk = 0;
        ll cs = 0;
        while(cs + sum[blk] <= k){
            cs += sum[blk++];
        }
        int el = blk * BLOCK;
        while(cs + va[el] <= k){
            cs += va[el++];
        }
        Mint ans = v[el] - (k - cs);
        ans *= query(el + 1, n);
        return ans;
    }
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int q;
    cin >> n >> q;
    vxx.resize(n+1);
    for(int i=1;i<=n;i++){
        cin >> vxx[i].first;
        vxx[i].second = i;
    }
    sort(vxx.begin(), vxx.end());
    for(int i=1;i<=n;i++){
        pos[vxx[i].second] = i;
        inv[i] = Mint(1) / vxx[i].first;
    }
    for(int i=0;i<q;i++){
        int l, r;
        ll k;
        cin >> l >> r >> k;
        vx.push_back({l, r, i, k});
    }
    Mo<Mint, erase, insert, remove, get> mo(vx);
    mo.solve();
    for(int i=0;i<q;i++){
        cout << mo.ans[i] << "\n";
    }
}
