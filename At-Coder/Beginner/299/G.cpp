#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 200005; 
vector<int> ap[N];
int st[4*N];
int v[N];
int n;

void build(int l = 1, int r = n, int p = 1){
    if(l == r){ st[p] = v[l]; return; }
    build(l, (l+r)/2, 2 * p);
    build((l+r)/2 + 1, r, 2 * p + 1);
    st[p] = min(st[2 * p], st[2 * p + 1]); //some operation
}

ll query(int i, int j, int l = 1, int r = n, int p = 1){
    if(j < l || i > r) return INF_INT; //identity element
    if(j >= r && i <= l) return st[p];
    return min(query(i, j, l, (l + r)/2, 2 * p), query(i, j, (l + r)/2 + 1, r, 2 * p + 1)); //some operation
}

void update(int i, int value, int l = 1, int r = n, int p = 1){
    if(i < l || i > r) return;
    if(l == r) {st[p] = value; return;}
    update(i, value, l, (l + r)/2, 2 * p);
    update(i, value, (l + r)/2 + 1, r, 2 * p + 1);
    st[p] = min(st[2 * p], st[2 * p + 1]); //some operation
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    set<int> lap;
    int m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> v[i];
        ap[v[i]].push_back(i);
    }
    for(int i=1;i<=m;i++){
        lap.insert(ap[i].back());
    }
    build();
    int l = 1, r = *lap.begin();
    vector<int> ans;
    for(int i=1;i<=m;i++){
        int x = query(l, r);
        ans.push_back(x);
        bool ok = false;
        for(int j=0;j<ap[x].size();j++){
            if(!ok){
                if(ap[x][j] >= l){
                    l = ap[x][j];
                    ok = true;
                }
            }
            update(ap[x][j], INF_INT);
        }   
        lap.erase(ap[x].back());
        r = *lap.begin();
    }
    for(auto x : ans) cout << x << " ";
}
