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
        int n, k;
        cin >> n >> k;
        int ch = -1;
        vector<int> v(n);
        for(int i=1;i<=n;i++){
            cin >> v[i-1];
            if(i == k) ch = v[i-1];
        }
        sort(v.begin(), v.end());
        bool ok = true;
        // cout << ch << " ";
        for(int i=0;i<n;i++){
            if(v[i] <= ch) continue;
            assert(i != 0);
            if(v[i] - v[i-1] > ch) ok = false;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
