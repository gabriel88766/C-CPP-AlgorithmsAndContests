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
    int n, m;
    cin >> n >> m;
    ll sum = 0;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
        sum += v[i];
    }
    sort(v.begin(), v.end());
    ll cs = 0, ans = sum, lst = -2;
    for(int i=0;i<2*n;i++){
        if(i == 0 || (v[i%n] != lst && (lst + 1) % m != v[i%n])){
            lst = v[i%n];
            cs = v[i%n];
        }else{
            cs += v[i%n];
            lst = v[i%n];
        }
        // cout << cs << " ";
        ans = min(ans, sum - cs);
    }
    ans = max(ans, 0LL);
    cout << ans << "\n";

    
}
