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
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int ans = INF_INT;
    //1st pos  o...OXO..OXOO..
    vector<int> qt;
    for(int i=0;i<n;i++){
        qt.push_back(v[i]/2 + v[i]%2);
    }
    sort(qt.begin(), qt.end());
    ans = min(ans, qt[0] + qt[1]);
    //2nd pos O...OXXO....O
    for(int i=1;i<n;i++){
        if(max(v[i], v[i-1]) <= 2*min(v[i], v[i-1])) ans = min(ans, (v[i-1]+v[i])/3 + ((v[i-1]+v[i])%3 ? 1 : 0));
        else ans = min(ans, max(v[i], v[i-1])/2 + max(v[i], v[i-1])%2);
    }
    //3rd pos O...XOX...O
    for(int i=1;i<n-1;i++){
        int dif = abs(v[i+1]-v[i-1]);
        int minv = min(v[i+1], v[i-1]);
        ans = min(ans, dif/2 + dif%2 + minv);
    }
    cout << ans << "\n";
}
