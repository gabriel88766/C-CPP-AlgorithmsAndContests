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
    int n, r;
    cin >> n >> r;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    int cnt = 0;
    vector<bool> ison(n+1, false);
    bool ok;
    for(int i=1;i<=n;i++){
        ok = false;
        int li = max(1, i-r+1);
        int ri = min(n, i+r-1);
        for(int j=li;j<=ri;j++) if(ison[j]) ok = true;
        if(ok) continue;
        for(int j=ri;j>=li;j--){
            if(v[j] == 1){
                ison[j] = true;
                cnt++;
                ok = true;
                break;
            }
        }
        if(!ok) break;
    }
    if(ok) cout << cnt << "\n";
    else cout << "-1\n";
}
