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
        int ans = 1;
        for(int i=0;i<n;i++){
            cin >> v[i];
            if(i >= 1 && v[i] != v[i-1]) ans++;
        }
        bool ok1 = false, ok2 = false;
        for(int i=1;i<n-1;i++){
            if(v[i] == v[i-1] && v[i+1] != v[i] && (i + 2 == n || v[i+2] != v[i])) ok1 = true;
            if(v[i] == v[i+1] && v[i-1] != v[i] && (i - 2 == -1 || v[i-2] != v[i])) ok1 = true;
        }
        for(int i=2;i<n-1;i++){
            if(v[i-2] == v[i-1] && v[i-1] != v[i] && v[i] == v[i+1]) ok2 = true;
        }
        if(ok2) ans += 2;
        else if(ok1) ans += 1;

        cout << ans << "\n";
        
    }
}
