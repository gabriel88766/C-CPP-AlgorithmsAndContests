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
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    vector<int> ps(n+1);
    bool done = false;
    for(int i=2;i<=n;i++){
        if(v[i] > v[i-1]){
            done = false;
            ps[i] = 1;
        }else if(!done){
            done = true;
            ps[i] = 1;
        }
        ps[i] += ps[i-1];
    }


    for(int i=1;i<=q;i++){
        int l, r;
        cin >> l >> r;
        int ans = 1;
        ans += ps[r] - ps[l];
        if(l + 1 <= r && ps[l+1] == ps[l]) ans++;
        cout << ans << "\n";        
    }
}
