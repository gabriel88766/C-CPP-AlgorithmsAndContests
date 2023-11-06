#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+6;
int  st[4*N], lz[4*N];
int v[N];
int m = 200005;
int n, d, w;

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

ll query(int i, int j, int l = 1, int r = m, int p = 1){
    push(l, r, p);
    if(j < l || i > r) return 0; //identity element
    if(j >= r && i <= l) return st[p];
    return max(query(i, j, l, (l + r)/2, 2 * p), query(i, j, (l + r)/2 + 1, r, 2 * p + 1)); //some operation
}

void update(int i, int j, int value, int l = 1, int r = m, int p = 1){
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
    //freopen("in", "r", stdin); //test input
    cin >> n >> d >> w;
    vector<pair<int,int>> ap(n);
    for(int i=0;i<n;i++) cin >> ap[i].first >> ap[i].second;
    sort(ap.begin(), ap.end());
    int p1 = 0, p2 = 0;
    //sliding window
    int ans = 0;
    for(int i=1;i<=200000;i++){
        while(p1 < n && ap[p1].first < (i+d)){
             update(ap[p1].second-w+1, ap[p1].second, 1);
             p1++;
        }
        while(p2 < n && ap[p2].first < i){
             update(ap[p2].second-w+1, ap[p2].second, -1);
             p2++;
        }
        ans = max(ans, st[1]);
    }
    cout << ans << "\n";
}
