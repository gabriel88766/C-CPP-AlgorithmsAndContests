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
    int n, q;
    cin >> n >> q;
    vector<ll> a(n+1), ps(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        ps[i] = ps[i-1] + a[i];
    }
    for(int i=1;i<=q;i++){
        int tq;
        cin >> tq;
        if(tq == 1){
            int x;
            cin >> x;
            ps[x] -= a[x];
            swap(a[x], a[x+1]);
            ps[x] += a[x];
        }else{
            int l, r;
            cin >> l >> r;
            cout << ps[r] - ps[l-1] << "\n";
        }
    }
}
