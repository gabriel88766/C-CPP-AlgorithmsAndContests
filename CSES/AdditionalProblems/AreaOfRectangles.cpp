#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Event{
    int x, l, r;
    bool operator< (const Event &ev) const {
        return x < ev.x;
    }
};
const int mid = 1000003;
const int N = 2000006;

pair<int, int> st[4*N];
int lz[4*N];
int n;

void build(int l = 1, int r = n, int p = 1){
    if(l == r){ st[p] = {0, 1}; return; }
    build(l, (l+r)/2, 2 * p);
    build((l+r)/2 + 1, r, 2 * p + 1);
    st[p] = {0, r-l+1}; //some operation
}

void push(int l, int r, int p){
    if(lz[p]){ //0 can be assigned? change!
        st[p] = {st[p].first + lz[p], st[p].second}; //RMQ = lz, RSQ, = (r-l+1)*lz
        if(l != r){
            lz[2 * p] += lz[p]; // += increment = update
            lz[2 * p + 1] += lz[p];
        } 
        lz[p] = 0;
    }
}

pair<int,int> query(int i, int j, int l = 1, int r = n, int p = 1){
    push(l, r, p);
    if(j < l || i > r) return {INF_INT, 0}; //identity element
    if(j >= r && i <= l) return st[p];
    auto p1 =  query(i, j, l, (l + r)/2, 2 * p);
    auto p2 = query(i, j, (l + r)/2 + 1, r, 2 * p + 1); 
    if(p1.first == p2.first) return make_pair(p1.first, p1.second+p2.second);
    else return min(p1, p2);
}

void update(int i, int j, int value, int l = 1, int r = n, int p = 1){
    push(l, r, p);
    if(j < l || i > r) return;
    if(l >= i && r <= j) {lz[p] = value; push(l, r, p); return;}
    update(i, j, value, l, (l + r)/2, 2 * p);
    update(i, j, value, (l + r)/2 + 1, r, 2 * p + 1);
    if(st[2*p].first == st[2*p+1].first) st[p] = {st[2*p].first, st[2*p].second + st[2*p+1].second};
    else st[p] = min(st[2 * p], st[2 * p + 1]); //some operation
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int m;
    cin >> m;
    vector<Event> ev1, ev2;
    vector<ll> cds;
    for(int i=1;i<=m;i++){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ev1.push_back({x1, y1, y2});
        ev2.push_back({x2, y1, y2});
        cds.push_back(x1);
        cds.push_back(x2);
    }
    sort(cds.begin(), cds.end());
    cds.resize(unique(cds.begin(), cds.end()) - cds.begin());
    sort(ev1.begin(), ev1.end());
    sort(ev2.begin(), ev2.end());
    int p1 = 0, p2 = 0;
    ll ans = 0;
    n = N-1;
    build();
    for(int i=0;i<cds.size();i++){
        if(i){
            auto val = query(1, N-1);
            ll tt = N-1 - val.second;
            ans += tt * (cds[i] - cds[i-1]);
        }
        while(p1 < ev1.size() && ev1[p1].x <= cds[i]){
            auto [xx, l, r] = ev1[p1];
            update(mid+l, mid+r-1, 1);
            p1++;
        }
        while(p2 < ev2.size() && ev2[p2].x <= cds[i]){
            auto [xx, l, r] = ev2[p2];
            update(mid+l, mid+r-1, -1);
            p2++;
        }
    }
    cout << ans << "\n";
    
}
