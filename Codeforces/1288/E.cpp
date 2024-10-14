#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

template<typename T, T (*op)(T, T), T (*nullel)()>
struct SegmentTree{
    vector<T> st;
    int n;
    SegmentTree(vector<T> &v){
        n = v.size();
        st.resize(2*n);
        build(v);
    }
    SegmentTree(ll sz){
        n = sz;
        st.resize(2*n);
    }
    void build(vector<T> &v){
        for(int i=n;i<2*n;i++) st[i] = v[i-n];
        for(int i=n-1;i>=1;i--) st[i] = op(st[2*i], st[2*i+1]); //merge op
    }
    T query(int l, int r){
        T ans = nullel();
        l += n, r += n;
        while(l <= r){
            int no = l, c = 1;
            while(!(no & 1) && (r-l+1) >= (c << 1)){
                c <<= 1;
                no >>= 1;
            }
            ans = op(ans, st[no]); //merge op
            l += c;
        }
        return ans;
    }
    void update(int l, T val){
        l += n;
        st[l] = val; //assign or increment?
        while(l > 1){
            l >>= 1;
            st[l] = op(st[2*l], st[2*l+1]); //merge op
        }
    }
};

int op(int a, int b){
    return a + b;
}

int el(){
    return 0;
}



const int N = 3e5+3;
const int sqrtN = 600;
int cnt[N];
int minv[N], maxv[N], v[N], vis[N];
int cans = 0;
int n;

struct Query{
    int l, r, i;
    bool operator< (const Query u) const {
        if(l/sqrtN != u.l/sqrtN) return l/sqrtN < u.l/sqrtN;
        else return r < u.r;
    }
};
vector<Query> vq;
void erase(){
    for(int i=1;i<=n;i++){
        cnt[i] = 0;
    }
    cans = 0;
}

void Mo(){ //This is an example, function need to be changed, but idea remains.
    int blk = -1, p = 0;
    ll cur = 0;
    for(auto x : vq){
        if((x.l/sqrtN)*sqrtN != blk){
            cur = 0;
            blk = p = (x.l/sqrtN)*sqrtN; //first element of block
            erase(); //once each block O(N)
        }
        while(p <= x.r){ //from 0 to n, sqrt(N) times
            cnt[v[p]]++;
            if(cnt[v[p]] == 1) cans++;
            p++;
        }
        ll sub = 0;
        for(int i=blk;i<x.l;i++){ //O(sqrt(N))
            cnt[v[i]]--;
            if(cnt[v[i]] == 0) cans--;
        }
        maxv[x.i] = max(maxv[x.i], cans+1);
        for(int i=blk;i<x.l;i++){ //O(sqrt(N))
            cnt[v[i]]++;
            if(cnt[v[i]] == 1) cans++;
        }      
    }
}



vector<int> oc[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) minv[i] = i;
    SegmentTree<int, op, el> st(n+1);
    for(int i=1;i<=m;i++){
        cin >> v[i];
        oc[v[i]].push_back(i);
        if(!vis[v[i]]){
            maxv[v[i]] = st.query(v[i], n) + v[i];
            vis[v[i]] = true;
            st.update(v[i], 1);
        }
        minv[v[i]] = 1;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            maxv[i] = st.query(i, n) + i;
        }
        for(int j=0;j<oc[i].size();j++){
            if(j == oc[i].size() - 1){
                if(oc[i][j] != m) vq.push_back({oc[i][j]+1, m, i});
            }else if(oc[i][j] != oc[i][j+1] - 1) vq.push_back({oc[i][j]+1, oc[i][j+1]-1, i});
        }
    }
    sort(vq.begin(), vq.end());
    Mo();
    //I can solve using Mo. need ??
    for(int i=1;i<=n;i++){
        cout << minv[i] << " " << maxv[i] << "\n";
    }

}
