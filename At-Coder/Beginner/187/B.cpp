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
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i].first >> v[i].second;
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            auto [a, b] = v[i];
            auto [c, d] = v[j];
            int d1 = abs(c-a);
            int d2 = abs(b-d);
            if(d2 <= d1) ans++;
        }
    }
    cout << ans << "\n";
}
