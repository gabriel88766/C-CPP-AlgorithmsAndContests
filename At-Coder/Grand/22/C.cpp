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
    int m;
    cin >> m;
    vector<int> a(m+1), b(m+1);
    for(int i=1;i<=m;i++){
        cin >> a[i];
    }
    for(int i=1;i<=m;i++){
        cin >> b[i];
    }
    ll ans = 0;
    for(int i=1;i<=50;i++) ans += 1LL << i;
    //check if ok at all
    bitset<51> rc[51];
    auto make_rc = [&](ll ans){
        for(int j=0;j<=50;j++) for(int k=0;k<=50;k++) rc[j][k] = 0;
        rc[0][0] = 1;
        for(int j=1;j<=50;j++){
            rc[j][j] = 1;
            for(int x = 1; x <= 50; x++){
                if(ans & (1LL << x)){
                    rc[j] |= rc[j % x];
                }
            }
        }
    };
    make_rc(ans);
    for(int j=1;j<=m;j++){
        if(!rc[a[j]][b[j]]){
            cout << "-1\n";
            return 0;
        }
    }
    for(int i=50;i>=1;i--){
        //test if without i it is still possible
        ll nans = ans ^ (1LL << i);
        make_rc(nans);
        bool ok = true;
        for(int j=1;j<=m;j++){
            if(!rc[a[j]][b[j]]){
                ok = false;
            }
        }
        if(ok) ans = nans;
    }
    cout << ans << "\n";
}
