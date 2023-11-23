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
        vector<int> v(n+1), suf(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        bool ok = false;
        int ind = 0;
        for(int i=n;i>=1;i--){
            if(i == n) suf[i] = v[i];
            else{
                int dif = v[i] - suf[i+1];
                if(dif < 0){
                    ind = i;
                    break;
                }
                suf[i] = dif;
            }
        }
        int cur = 0;
        for(int i = 1;i<n;i++){
            if(i+2 > ind){
                //check swap
                int dif = v[i+1] - cur;
                if(dif >= 0){
                    dif = v[i] - dif;
                    if(dif >= 0){
                        if(dif == 0 && i+1 == n) ok = true;
                        else if(dif == suf[i+2]) ok = true;
                    }
                }
            }
            cur = v[i] - cur;
            if(cur < 0) break;
        }
        if(cur >= 0){
            //no swap
            cur = v[n] - cur;
            if(cur == 0) ok = true;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
