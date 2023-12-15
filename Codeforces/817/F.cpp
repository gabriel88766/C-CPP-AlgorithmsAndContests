#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int M = 36000000; //M > 60*N
bool st1[M], st2[M];
char lz[M];
int lc[M], cnt = 1; 
ll MAX_LL = 1000000000000000002LL;


void push(ll l, ll r, int p){
    if(lz[p]){
        if(lz[p] == 1) st1[p] = st2[p] = 1;
        if(lz[p] == 2) st1[p] = st2[p] = 0;
        if(lz[p] == 3){
            bool n1, n2;
            if(st2[p]) n1 = 0; 
            else n1 = 1;
            if(st1[p]) n2 = 0;
            else n2 = 1;
            st1[p] = n1;
            st2[p] = n2;
        }
        if(l != r){
            if(!lc[p]){
                lc[p] = ++cnt;
                ++cnt;
            }
            if(lz[p] == 1 || lz[p] == 2){
                lz[lc[p]] = lz[p]; 
                lz[lc[p]+1] = lz[p];
            }else{
                lz[lc[p]] ^= 3;
                lz[lc[p]+1] ^= 3;
            }
        } 
        lz[p] = 0;
    }
}

void update(ll i, ll j, int type, ll l = 1LL, ll r = MAX_LL, int p = 1){
    push(l, r, p);
    if(j < l || i > r) return;
    if(l >= i && r <= j) {lz[p] = type; push(l, r, p); return;}
    ll m = (l+r)/2;
    if(!lc[p]){ 
        lc[p] = ++cnt;
        ++cnt;
    }
    update(i, j, type, l, m, lc[p]);
    update(i, j, type, m+1, r, lc[p]+1);
    st1[p] = st1[lc[p]] & st1[lc[p]+1]; // has all
    st2[p] = st2[lc[p]] | st2[lc[p]+1]; // has at least 1
}

ll query(ll l = 1LL, ll r = MAX_LL, int p = 1){
    if(l == r) return l;
    if(!lc[p]) return l;
    ll m = (l + r) / 2;
    push(l, r, p);
    push(l, m, lc[p]);
    if(!st1[lc[p]]) return query(l, m, lc[p]);
    else{
        return query(m+1, r, lc[p]+1);
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
        ll type, l, r;
        cin >> type >> l >> r;
        update(l, r, type);
        cout << query() << "\n";
    }
}
