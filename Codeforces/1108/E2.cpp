#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+6;
ll st[4*N], lz[4*N];
ll v[N];
int n;

void build(int l = 1, int r = n, int p = 1){
    if(l == r){ st[p] = v[l]; return; }
    build(l, (l+r)/2, 2 * p);
    build((l+r)/2 + 1, r, 2 * p + 1);
    st[p] = max(st[2 * p], st[2 * p + 1]); //some operation
}

void push(int l, int r, int p){
    if(lz[p]){ //0 can be assigned? change!
        st[p] += lz[p]; //RMQ = lz, RSQ, = (r-l+1)*lz
        if(l != r){
            lz[2 * p] += lz[p]; // += increment = update
            lz[2 * p + 1] += lz[p];
        } 
        lz[p] = 0;
    }
}

ll query(int i, int j, int l = 1, int r = n, int p = 1){
    push(l, r, p);
    if(j < l || i > r) return -INF_LL; //identity element
    if(j >= r && i <= l) return st[p];
    return max(query(i, j, l, (l + r)/2, 2 * p), query(i, j, (l + r)/2 + 1, r, 2 * p + 1)); //some operation
}

void update(int i, int j, ll value, int l = 1, int r = n, int p = 1){
    push(l, r, p);
    if(j < l || i > r) return;
    if(l >= i && r <= j) {lz[p] = value; push(l, r, p); return;}
    update(i, j, value, l, (l + r)/2, 2 * p);
    update(i, j, value, (l + r)/2 + 1, r, 2 * p + 1);
    st[p] = max(st[2 * p], st[2 * p + 1]); //some operation
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int  m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> v[i];
    build();
    vector<pair<int,int>> seg(m+1);
    for(int i=1;i<=m;i++) cin >> seg[i].first >> seg[i].second;
    set<int> ss, anss;
    
    int maxv = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
             if(seg[j].first == i){
                update(seg[j].first, seg[j].second, -1);
                ss.insert(j);
             }
        }
        int curv = query(1,n) - query(i,i);
        if(curv > maxv){
            maxv = curv;
            anss = ss;
        }
        for(int j=1;j<=m;j++){
            if(seg[j].second == i){
                update(seg[j].first, seg[j].second, 1);
                ss.erase(j);
            }
        }
    }
    cout << maxv << "\n";
    cout << anss.size() << "\n";
    for(auto it = anss.begin(); it != anss.end(); ++it) cout << *it << " ";
}
