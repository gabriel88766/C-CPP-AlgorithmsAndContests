#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> tg[N];
vector<pair<int,int>> vq[N];


map<int, int> ans[N];
int ansq[N];

//usually unnecessary
const int M = 40000000; //M > 90*N!
int st[M], lz[M];
int lc[M], rc[M], cnt = 1; 
int MAX_INT = 1e9;


void push(int l, int r, int p){
    if(lz[p]){
        st[p] += (ll)(r - l + 1) * lz[p]; //RMQ = lz, RSQ, = (r-l+1)*lz
        if(l != r){
            if(!lc[p]) lc[p] = ++cnt;
            if(!rc[p]) rc[p] = ++cnt;
            lz[lc[p]] += lz[p]; // += increment = update
            lz[rc[p]] += lz[p];
        } 
        lz[p] = 0;
    }
}

void update(int i, int j, int add, int l = 1, int r = MAX_INT, int p = 1){
    push(l, r, p);
    if(j < l || i > r) return;
    if(l >= i && r <= j) {lz[p] = add; push(l, r, p); return;}
    int mid = (l+r)/2;
    if(!lc[p]) lc[p] = ++cnt;
    update(i, j, add, l, mid, lc[p]);
    if(!rc[p]) rc[p] = ++cnt; 
    update(i, j, add, mid+1, r, rc[p]);
    st[p] = st[lc[p]] + st[rc[p]];
}

int query(int a, int b, int l = 1, int r = MAX_INT, int p = 1){
    push(l, r, p);
    if(b < l || a > r) return 0;
    if(l >= a && b >= r) return st[p];
    if(!lc[p]) lc[p] = ++cnt;
    if(!rc[p]) rc[p] = ++cnt; 
    return query(a,b,l,(l+r)/2,lc[p]) + query(a,b,(l+r)/2+1,r,rc[p]);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int t, p;
        cin >> t >> p;
        tg[p].push_back(t);
    }
    int q;
    cin >> q;

    vector<int> ord;
    for(int i=1;i<=n;i++) ord.push_back(i);
    sort(ord.begin(), ord.end(), [&](int u, int v){
        return tg[u].size() > tg[v].size();
    });
    map<int,int> rod;
    for(int i=0;i<n;i++){
        rod[ord[i]] = i;
    }

    for(int i=0;i<q;i++){
        int a, b;
        cin >> a >> b;
        if(rod[a] > rod[b]) swap(a, b);
        vq[a].push_back({b, i});
    }

    for(int i=1;i<=n;i++){
        int lt = 0, s = 0;
        for(auto tn: tg[i]){
            if(s){
                update(lt, tn-1, 1);
            }
            s^=1;
            lt = tn;
        }
        for(auto [b, j] : vq[i]){
            if(ans[i].count(b)) ansq[j] = b;
            else{
                int lt = 0, s = 0;
                int cans = 0;
                for(auto tn: tg[b]){
                    if(s){
                        cans += query(lt, tn );
                    }
                    s^=1;
                    lt = tn;
                }
                ansq[j] = ans[i][b] = cans;
            }
        }
        lt = 0, s = 0;
        for(auto tn: tg[i]){
            if(s){
                update(lt, tn-1, -1);
            }
            s^=1;
            lt = tn;
        }
    }

    for(int i=0;i<q;i++){
        cout << ansq[i] << "\n";
    }
}
