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
        int n;
        cin >> n;
        vector<int> v(n);
        int c1 = 0, c2 = 0;
        for(int i=0;i<n;i++){
            cin >> v[i];
            if(v[i] % 2) c1++;
            else c2++;
        }
        if(n % 2){
            if(abs(c1 - c2) == 1){
                ll ans = 0;
                if(c1 > c2){
                    //begin odd, change to begin even
                    for(int i=0;i<n;i++) v[i] += 1;
                }
                int p = 0;
                for(int i=0;i<n;i++){
                    if(!(v[i] % 2)){
                        ans += abs(p-i);
                        p += 2;
                    }
                }
                cout << ans << "\n";
            }else cout << "-1\n";
        }else{
            if(c1 == c2){
                //solve 2 possibilities
                ll ans = INF_LL;
                ll ans1 = 0, ans2 = 0;
                int p = 0;
                for(int i=0;i<n;i++){
                    if(!(v[i] % 2)){
                        ans1 += abs(p-i);
                        p += 2;
                    }
                }
                p = 0;
                for(int i=0;i<n;i++){
                    if(v[i] % 2){
                        ans2 += abs(p-i);
                        p += 2;
                    }
                }
                ans = min(ans1, ans2);
                cout << ans << "\n";
            }else cout << "-1\n";
        }
    }
}
