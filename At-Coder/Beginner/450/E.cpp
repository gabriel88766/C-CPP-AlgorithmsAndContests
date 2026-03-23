#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string a, b;
    cin >> a >> b;
    int q;
    cin >> q;
    vector<vector<ll>> ca(a.size() + 1, vector<ll>(26)), cb(b.size() + 1, vector<ll>(26));
    for(int i=1;i<=a.size();i++){
        ca[i][a[i-1]-'a']++;
        for(int j=0;j<26;j++) ca[i][j] += ca[i-1][j];
    }
    for(int i=1;i<=b.size();i++){
        cb[i][b[i-1]-'a']++;
        for(int j=0;j<26;j++) cb[i][j] += cb[i-1][j];
    }
    auto query = [&](ll n, int c){
        vector<ll> qnt(120), qnt2(120);
        qnt[1] = a.size();
        qnt2[1] = ca[a.size()][c];
        qnt[2] = b.size();
        qnt2[2] = cb[b.size()][c];   
        int nx;
        for(int i=3;;i++){
            if(i == 120) assert(false);
            qnt[i] = qnt[i-1] + qnt[i-2];
            qnt2[i] = qnt2[i-1] + qnt2[i-2];
            if(qnt[i] >= n){
                nx = i;
                break;
            }
        }
        function<ll(ll,int,int)> aux = [&](ll n, int x, int c){
            if(x == 2 || x == 1){
                if(n == qnt[x]) return qnt2[x];
                if(n >=  qnt[x]){
                    assert(x == 2);
                    return qnt2[x] + aux(n - qnt[x], x-1, c);
                }else{
                    if(x == 2) return cb[n][c];
                    else return ca[n][c];
                }
            }
            if(qnt[x] == n) return qnt2[x];
            if(n == 0) return 0LL;
            if(qnt[x-1] <= n) return qnt2[x-1] + aux(n - qnt[x-1], x-2, c);
            else {
                return aux(n, x-1, c);
            }
        };
        return aux(n, nx, c);
    };
    for(int i=1;i<=q;i++){
        ll l, r;
        char c;
        cin >> l >> r >> c;
        ll ans = query(r, c-'a');
        if(l != 1) ans -= query(l-1, c-'a');
        cout << ans << "\n";
    }
}
 