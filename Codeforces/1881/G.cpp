#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;
 
const int N = 2e5+6;
ll st[4*N], lz[4*N];
int n;
 
void clear(int l = 1, int r = n, int p = 1){
    if(l == r){ st[p] = 0; return; }
    clear(l, (l+r)/2, 2 * p);
    clear((l+r)/2 + 1, r, 2 * p + 1);
    st[p] = 0; //some operation
}
void clear2(int l = 1, int r = n, int p = 1){
    if(l == r){ lz[p] = 0; return; }
    clear2(l, (l+r)/2, 2 * p);
    clear2((l+r)/2 + 1, r, 2 * p + 1);
    lz[p] = 0; //some operation
}
 
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
string s;
 
bool check(int i, int j){
    int x1 = s[i];
    int x2 = s[j];
    x1 += query(i, i);
    x2 += query(j, j);
    return (x1%26) == (x2%26);
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
        cin >> s;
        s = " " + s;
        set<int> s2, s3;
        for(int i=2;i<=n-1;i++){
            if(s[i-1] == s[i+1]) s3.insert(i);
        }
        for(int i=1;i<=n-1;i++){
            if(s[i] == s[i+1]) s2.insert(i);
        }
        for(int i=0;i<m;i++){
            int q, x, l, r;
            cin >> q >> l >> r;
            if(q == 1){
                cin >> x;
                update(l, r, x%26);
                //change l, and r s3
                //change r s2
                
                if(r != n){
                    if(check(r, r+1)) s2.insert(r);
                    else s2.erase(r);
                }
                if(l != 1){
                    if(check(l-1, l)) s2.insert(l-1);
                    else s2.erase(l-1);
                }
                if(l != 1 && l != n){
                    if(check(l-1, l+1)) s3.insert(l);
                    else s3.erase(l);
                }
                if(r != n && l != r){
                    if(check(r-1, r+1)) s3.insert(r);
                    else s3.erase(r);
                }
                if(l > 2){
                    if(check(l-2, l)) s3.insert(l-1);
                    else s3.erase(l-1);
                }
                if(r < (n-1)){
                    if(check(r, r+2)) s3.insert(r+1);
                    else s3.erase(r+1);
                }
                
            }else{
                auto x1 = s2.lower_bound(l);
                auto x2 = s3.lower_bound(l+1);
                bool ok = true;
                if(x1 != s2.end() && *x1 < r) ok = false;
                if(x2 != s3.end() && *x2 < r) ok = false;
                if(ok) cout << "YES\n";
                else cout << "NO\n";
            }
        }
 
 
        clear();
        clear2();
    }
}