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
    //freopen("in",  "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for(int i=0;i<m;i++) cin >> a[i];
    sort(a.begin(), a.end());
    int l = 0;
    vector<int> v;
    a.push_back(n+1);
    for(int i=0;i<=m;i++){
        if(a[i] != l+1){
            v.push_back(a[i] - l - 1);
        }
        l = a[i];
    }
    int x = *min_element(v.begin(), v.end());
    int ans = 0;
    for(auto y : v) ans += (y+x-1)/x;
    cout << ans << "\n";

}
