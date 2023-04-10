#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+6;
int  st[4*N][26];
int n;

ll query(int i, int j, int letter, int l = 1, int r = n, int p = 1){
    if(j < l || i > r) return 0; //identity element
    if(j >= r && i <= l) return st[p][letter];
    return query(i, j, letter, l, (l + r)/2, 2 * p) + query(i, j, letter, (l + r)/2 + 1, r, 2 * p + 1); //some operation
}

void update(int i, int letter, int value, int l = 1, int r = n, int p = 1){
    if(i < l || i > r) return;
    if(l == r) {st[p][letter] = value; return;}
    update(i, letter, value, l, (l + r)/2, 2 * p);
    update(i, letter, value, (l + r)/2 + 1, r, 2 * p + 1);
    st[p][letter] = st[2 * p][letter] + st[2 * p + 1][letter]; //some operation
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s;
    cin >> s;
    n = s.size();
    for(int i=1;i<=n;i++){
        update(i, s[i-1]-'a', 1);
    }
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int t;
        cin >> t;
        if(t == 1){
            int pos;
            char c;
            cin >> pos >> c;
            update(pos, s[pos-1]-'a', 0);
            update(pos, c-'a', 1);
            s[pos-1] = c;
        }else{
            int l, r;
            cin >> l >> r;
            int ans = 0;
            for(int j=0;j<26;j++){
                if(query(l, r, j) != 0) ans++;
            }
            cout << ans << "\n";
        }
    }
}
