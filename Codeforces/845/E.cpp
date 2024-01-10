#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Square{
    int xmin, xmax, ymin, ymax;
};
int n, m;

struct Event{
    int i, l, r;
    bool operator< (const Event &ev) const {
        return i < ev.i;
    }
};



template<typename T, T (*op)(T, T), T (*nullel)()>
struct SegmentTreeLazy{
    vector<T> st, lz;
    int n;
    SegmentTreeLazy(vector<T> &v){
        n = v.size();
        st.resize(4*n);
        lz.assign(4*n, nullel());
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
            st[p] += lz[p]; //RMQ = lz, RSQ, = (r-l+1)*lz
            if(l != r){
                lz[2 * p] += lz[p]; // += increment = update
                lz[2 * p + 1] += lz[p];
            } 
            lz[p] = 0;
        }
    }

    ll query(int i, int j, int l, int r, int p){
        push(l, r, p);
        if(j < l || i > r) return nullel();
        if(j >= r && i <= l) return st[p];
        return op(query(i, j, l, (l + r)/2, 2 * p), query(i, j, (l + r)/2 + 1, r, 2 * p + 1)); 
    }
    T query(int i, int j){
        return query(i, j, 0, n-1, 1);
    }
    void update(int i, int j, T val, int l, int r, int p){
        push(l, r, p);
        if(j < l || i > r) return;
        if(l >= i && r <= j) {lz[p] = val; push(l, r, p); return;}
        update(i, j, val, l, (l + r)/2, 2 * p);
        update(i, j, val, (l + r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); 
    }
    void update(int i, int j, T val){
        update(i, j, val, 0, n-1, 1);
    }
};

int op(int a, int b){
    return min(a, b);
}

int el(){
    return INF_INT;
}

pair<int,int> searchX(vector<Square> &vsq){ //f1 = 0 for x, 1 for y, f2 = 0 for min, 1 for max
    int cur = 1; //from 1 to n
    vector<int> cds;
    for(auto x : vsq){
        cds.push_back(x.ymin);
        cds.push_back(x.ymax);
    }
    sort(cds.begin(), cds.end());
    cds.resize(unique(cds.begin(), cds.end()) - cds.begin());
    map<int,int> ord;
    for(int i=0;i<cds.size();i++){
        ord[cds[i]] = i;
    }
    vector<Event> sum, sub;
    for(auto x : vsq){
        sum.push_back({x.xmin, x.ymin, x.ymax});
        sub.push_back({x.xmax+1, x.ymin, x.ymax});
    }
    sort(sum.begin(), sum.end());
    sort(sub.begin(), sub.end());
    int xmin = n+1, xmax = 0;
    SegmentTreeLazy<int, op, el> st(cds.size());
    int p1 = 0, p2 = 0;
    while(cur != (n+1)){
        if(p1 < sum.size() && cur == sum[p1].i){
            st.update(ord[sum[p1].l], ord[sum[p1].r], 1);
            p1++;
        }else if(p2 < sub.size() && cur == sub[p2].i){
            st.update(ord[sum[p2].l], ord[sum[p2].r], -1);
            p2++;
        }else{
            int nxt = 0;
            if(p1 < sum.size() && p2 < sub.size()) nxt = min(sum[p1].i, sub[p2].i);
            else if(p1 < sum.size()) nxt = sum[p1].i;
            else if(p2 < sub.size()) nxt = sub[p2].i;
            if(st.query(0, cds.size()-1) == 0){
                xmin = min(xmin, cur);
                xmax = max(xmax, nxt-1);
            }
            if(nxt == 0) break;
            cur = nxt;
        }
    }
    return make_pair(xmin, xmax);
}


pair<int,int> searchY(vector<Square> &vsq){ //f1 = 0 for x, 1 for y, f2 = 0 for min, 1 for max
    int cur = 1; //from 1 to m
    vector<int> cds;
    for(auto x : vsq){
        cds.push_back(x.xmin);
        cds.push_back(x.xmax);
    }
    sort(cds.begin(), cds.end());
    cds.resize(unique(cds.begin(), cds.end()) - cds.begin());
    map<int,int> ord;
    for(int i=0;i<cds.size();i++){
        ord[cds[i]] = i;
    }
    vector<Event> sum, sub;
    for(auto x : vsq){
        sum.push_back({x.ymin, x.xmin, x.xmax});
        sub.push_back({x.ymax+1, x.xmin, x.xmax});
    }
    sort(sum.begin(), sum.end());
    sort(sub.begin(), sub.end());
    int ymin = m+1, ymax = 0;
    SegmentTreeLazy<int, op, el> st(cds.size());
    int p1 = 0, p2 = 0;
    while(cur != (m+1)){
        if(cur == sum[p1].i){
            st.update(ord[sum[p1].l], ord[sum[p1].r], 1);
            p1++;
        }else if(cur == sub[p2].i){
            st.update(ord[sum[p2].l], ord[sum[p2].r], -1);
            p2++;
        }else{
            int nxt = min(sum[p1].i, sub[p2].i);
            if(st.query(0, cds.size()-1) == 0){
                ymin = min(ymin, cur);
                ymax = max(ymax, nxt-1);
            }
            cur = nxt;
        }
    }
    return make_pair(ymin, ymax);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int,int>> v(k);
    for(int i=0;i<k;i++){
        cin >> v[i].first >> v[i].second;
    }
    int lo = 0, hi = 1e9;
    while(lo != hi){
        int mid = lo + (hi - lo)/2;
        vector<Square> vsq(k);
        for(auto x : v){
            int xlaf = min(x.first - mid, 1);
            int xraf = max(x.first + mid, n);
            int ylaf = min(x.second - mid, 1);
            int yraf = max(x.second + mid, m);
            vsq.push_back({xlaf, xraf, ylaf, yraf});
        }
        int lx = 1, rx = n+1;
        auto [xmin, xmax] = searchX(vsq);
        auto [ymin, ymax] = searchY(vsq);
        cout << mid << " " << xmin << " " << xmax << " " << ymin << " " << ymax << "\n";
        if(max(xmax-xmin, ymax-ymin) > 2*mid) lo = mid + 1;
        else hi = mid;
        
    }
    cout << lo << "\n";
}
