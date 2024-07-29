#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;



const int N = 2e5+6;
pair<int, int> st[4*N];
int lz[4*N];
int n;

void clear(int l = 1, int r = n, int p = 1){
    lz[p] = 0;
    if(l == r){ st[p] = {0, 1}; return; }
    clear(l, (l+r)/2, 2 * p);
    clear((l+r)/2 + 1, r, 2 * p + 1);
    st[p] = {0, r-l+1}; 
}

void push(int l, int r, int p){
    if(lz[p]){ //0 can be assigned? change!
        st[p].first +=  lz[p]; //RMQ = lz, RSQ, = (r-l+1)*lz
        if(l != r){
            lz[2 * p] += lz[p]; // += increment = update
            lz[2 * p + 1] += lz[p];
        } 
        lz[p] = 0;
    }
}

pair<int, int> query(int i, int j, int l = 1, int r = n, int p = 1){
    push(l, r, p);
    if(j < l || i > r) return {INF_INT, 1}; //identity element
    if(j >= r && i <= l) return st[p];
    auto p1 = query(i, j, l, (l + r)/2, 2 * p) ;
    auto p2 = query(i, j, (l + r)/2 + 1, r, 2 * p + 1);
    if(p1.first < p2.first) return p1;
    else if(p1.first > p2.first) return p2;
    else return {p1.first, p1.second+p2.second};
}

void update(int i, int j, int value, int l = 1, int r = n, int p = 1){
    push(l, r, p);
    if(j < l || i > r) return;
    if(l >= i && r <= j) {lz[p] = value; push(l, r, p); return;}
    update(i, j, value, l, (l + r)/2, 2 * p);
    update(i, j, value, (l + r)/2 + 1, r, 2 * p + 1);
    if(st[2*p].first < st[2*p+1].first) st[p] = st[2*p];
    else if(st[2*p].first > st[2*p+1].first) st[p] = st[2*p+1];
    else{
        st[p] = st[2*p];
        st[p].second += st[2*p+1].second;
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int m;
        cin >> n >> m;
        vector<vector<int>> adj(n+1), adjr(n+1);
        for(int i=0;i<m;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adjr[b].push_back(a);
        }
        int ans = n;
        clear();
        //at first all are a-b, except 1-b, those are b=>1
        for(int i=2;i<=n;i++){
            for(auto b : adj[i]){
                update(i, b-1, 1);
            }
        }
        for(auto b : adj[1]){
            update(b, n, 1);
        }
        ans = min(ans, n-query(1, n).second);
        for(int i=2;i<=n;i++){  
            for(auto b : adj[i]){
                update(b, n, 1);
                update(1, i-1, 1);
                update(i, b-1, -1);
            }
            for(auto b : adjr[i]){
                update(i, n, -1);
                if(b > 1) update(1, b-1, -1);
                update(b, i-1, 1);
            }
            ans = min(ans, n-query(1, n).second);
        }
        cout << ans << "\n";
    }
}
