#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+6;
ll st[4*N], lz[4*N];
int n;

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
    if(j < l || i > r) return 0; //identity element
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


struct domino{
    int x, h, index;
    bool operator< (const  domino &p) const {
        return x < p.x;
    }
};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n;
    vector<domino> v(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i].x >> v[i].h;
        v[i].index = i;
    }
    sort(v.begin()+1, v.end());
    vector<int> ans(n+1, 0);
    for(int i = n; i >= 1; i--){
        int p = i;
        for(int j = n/2; j >= 1; j /= 2){
            while(p + j <= n && v[p+j].x < (v[i].x + v[i].h)) p += j;
        }
        update(i, n, 1);
        int val = query(i, p);
        ans[v[i].index] = val;
        update(i, i, val-1);
    }
    for(int i = 1;i <= n; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
}
