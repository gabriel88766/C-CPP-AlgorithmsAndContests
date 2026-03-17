#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

template<typename T, T (*op)(T, T), T (*nullel)()>
struct SegmentTreeLazy{
    vector<T> st;
    vector<int> lz;
    int n;
    SegmentTreeLazy(vector<T> &v){
        n = v.size();
        st.resize(4*n);
        lz.assign(4*n, 0);
        build(v, 0, n-1, 1);
    }
    SegmentTreeLazy(ll sz){
        n = sz;
        st.assign(4*n, 0);
        lz.assign(4*n, 0);
    }
    void build(vector<T> &v, int l, int r, int p){
        if(l == r){ st[p] = v[l]; return; }
        build(v, l, (l+r)/2, 2 * p);
        build(v, (l+r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); 
    }

    void push(int l, int r, int p){
        if(lz[p] != 0){ //0 can be assigned? change!
            st[p].first += lz[p];
            if(l != r){
                lz[2 * p] += lz[p]; // += increment = update
                lz[2 * p + 1] += lz[p];
            } 
            lz[p] = 0;
        }
    }

    T query(int i, int j, int l, int r, int p){
        push(l, r, p);
        if(j < l || i > r) return nullel();
        if(j >= r && i <= l) return st[p];
        return op(query(i, j, l, (l + r)/2, 2 * p), query(i, j, (l + r)/2 + 1, r, 2 * p + 1)); 
    }
    T query(int i, int j){
        return query(i, j, 0, n-1, 1);
    }
    void update(int i, int j, int val, int l, int r, int p){
        push(l, r, p);
        if(j < l || i > r) return;
        if(l >= i && r <= j) {lz[p] = val; push(l, r, p); return;}
        update(i, j, val, l, (l + r)/2, 2 * p);
        update(i, j, val, (l + r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); 
    }
    void update(int i, int j, int val){
        update(i, j, val, 0, n-1, 1);
    }
};

pair<int, int> op(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first) return make_pair(a.first, a.second + b.second);
    else return min(a, b);
}

pair<int, int> el(){
    return {INF_INT, INF_INT};
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int H, W, h, w, n;
    cin >> H >> W >> h >> w >> n;
    int mh = H - h + 1;
    int mw = W - w + 1;
    map<int, vector<pair<int, int>>> mpp, mpl;
    vector<tuple<int, int, int, int>> prcs;
    vector<int> cds;
    cds.push_back(1);
    cds.push_back(mw + 1);
    for(int i=1;i<=n;i++){
        int r, c;
        cin >> r >> c;
        int minh = max(1, r - h + 1);
        int minw = max(1, c - w + 1);
        int maxh = min(mh, r);
        int maxw = min(mw, c);
        prcs.push_back({minh, maxh, minw, maxw});
        cds.push_back(maxw + 1);
        cds.push_back(minw);
    }
    sort(cds.begin(), cds.end());
    cds.resize(unique(cds.begin(), cds.end()) - cds.begin());
    vector<pair<int, int>> seed;
    for(int i=1;i<cds.size();i++){
        seed.push_back({0, cds[i] - cds[i-1]});
    }
    SegmentTreeLazy<pair<int, int>, op, el> st(seed);
    vector<int> iph;
    iph.push_back(1);
    iph.push_back(mh + 1);
    for(auto [minh, maxh, minw, maxw] : prcs){
        int cl = lower_bound(cds.begin(),cds.end(), minw) - cds.begin();
        int cr = lower_bound(cds.begin(), cds.end(), maxw + 1) - cds.begin() - 1;
        mpp[minh].push_back({cl, cr});
        mpl[maxh + 1].push_back({cl, cr});
        iph.push_back(minh);
        iph.push_back(maxh + 1);
    }
    sort(iph.begin(), iph.end());
    iph.resize(unique(iph.begin(), iph.end()) - iph.begin());
    ll ans = 0;
    for(int i=1;i<iph.size();i++){
        if(mpp.count(iph[i-1])){
            for(auto [l, r] : mpp[iph[i-1]]){
                st.update(l, r, 1);
            }
        }
        if(mpl.count(iph[i-1])){
            for(auto [l, r] : mpl[iph[i-1]]){
                st.update(l, r, -1);
            }
        }
        if(st.st[1].first == 0) ans += ((ll)st.st[1].second) * (iph[i] - iph[i-1]);
    }
    cout << ans << "\n";
}
