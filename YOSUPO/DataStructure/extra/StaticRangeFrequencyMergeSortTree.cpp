#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//MergeSortTree no update
const int N = 5e5+6;
vector<int> st[4*N];
int v[N];
int n;


void build(int l = 1, int r = n, int p = 1){ //O(n log n) pushback
    if(l == r){ st[p].push_back(v[l]); return; }
    build(l, (l+r)/2, 2 * p);
    build((l+r)/2 + 1, r, 2 * p + 1);
    int p1 = 0, p2 = 0;
    while(p1 < st[2*p].size() && p2 < st[2*p+1].size()){
        if(st[2*p][p1] < st[2*p+1][p2]) st[p].push_back(st[2*p][p1++]);
        else st[p].push_back(st[2*p+1][p2++]);
    }
    while(p1 < st[2*p].size()) st[p].push_back(st[2*p][p1++]);
    while(p2 < st[2*p+1].size()) st[p].push_back(st[2*p+1][p2++]);
}

int query(int i, int j, int x, int l = 1, int r = n, int p = 1){ //O(log^2 n)
    if(j < l || i > r) return 0; //identity element
    if(j >= r && i <= l){
        return upper_bound(st[p].begin(), st[p].end(), x) - lower_bound(st[p].begin(), st[p].end(), x);
    }
    return query(i, j, x, l, (l + r)/2, 2 * p) + query(i, j, x, (l + r)/2 + 1, r, 2 * p + 1); //some operation
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int q;
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> v[i];
    if(n == 0){
        for(int i=0;i<q;i++){
            int l, r, x;
            cin >> l >> r >> x;
            cout << "0\n";
        }
        return 0;
    }
    build();
    for(int i=0;i<q;i++){
        int l, r, x;
        cin >> l >> r >> x;
        if(l == r) cout << "0\n";
        else{
            ++l;
            cout << query(l, r, x) << "\n";
        }
    }
}
