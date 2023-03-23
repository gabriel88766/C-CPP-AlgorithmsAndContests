#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+6;
ll st[4*N], lz[4*N];
ll v[N], ans[N];
int n;

void push(int l, int r, int p){
    if(lz[p]){ //0 can be assigned? change!
        st[p] += (ll)(r - l + 1) * lz[p]; //RMQ = lz, RSQ, = (r-l+1)*lz
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
    return query(i, j, l, (l + r)/2, 2 * p) + query(i, j, (l + r)/2 + 1, r, 2 * p + 1); //some operation
}

void update(int i, int j, ll value, int l = 1, int r = n, int p = 1){
    push(l, r, p);
    if(j < l || i > r) return;
    if(l >= i && r <= j) {lz[p] = value; push(l, r, p); return;}
    update(i, j, value, l, (l + r)/2, 2 * p);
    update(i, j, value, (l + r)/2 + 1, r, 2 * p + 1);
    st[p] = st[2 * p] + st[2 * p + 1]; //some operation
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    vector<pair<pair<int,int>, int>> vq;
    int  q;
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=1;i<=q;i++){
        int a,b;
        cin >> a >> b;
        vq.push_back({{a, b}, i});
    }
    sort(vq.begin(), vq.end(), greater<pair<pair<int,int>,int>>());
    int bp = 0;
    stack<pair<int,int>> stn;
    for(int i=n;i>=1;i--){
        if(!stn.empty()){
            while(!stn.empty() && v[i] > stn.top().first){
                int l = stn.top().second, r;
                ll val = v[i] - stn.top().first;
                stn.pop();
                if(!stn.empty()) r = stn.top().second-1;
                else r = n;
                update(l, r, val);
            }
        }
        stn.push({v[i], i});
        while(bp < q && vq[bp].first.first == i){
            ans[vq[bp].second] = query(vq[bp].first.first, vq[bp].first.second);
            bp++;
        }
    }
    for(int i=1;i<=q;i++) cout << ans[i] << "\n";
}