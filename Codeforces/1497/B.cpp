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
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> v(n);
        vector<int> mod(m);
        for(int i=0;i<n;i++){
            cin >> v[i];
            mod[v[i]%m]++;
        }
        ll ans = 0;
        for(int i=0;i<m;i++){
            int p = i ? m-i : 0;
            if(p == i){
                if(mod[i]) ans++;
            }else{
                if(mod[i] && mod[p]){
                    ans++;
                    int minv = min(mod[i], mod[p]);
                    mod[i] -= minv;
                    mod[p] -= minv;
                    if(mod[i] || mod[p]){
                        if(mod[i]) mod[i]--;
                        else mod[p]--;
                    }
                }
                ans += mod[i];
            }
        }
        cout << ans << "\n";
    }
}
