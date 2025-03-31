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
    set<int> s;
    vector<int> c1(n), c2(n);
    for(int i=0;i<n;i++){
        s.insert(v[i]);
        c1[i] = s.size();
    }
    s.clear();
    for(int i=n-1;i>=0;i--){
        s.insert(v[i]);
        c2[i] = s.size();
    }
    int ans = 0;
    for(int i=0;i<n-1;i++){
        ans = max(ans, c1[i] + c2[i+1]);
    }
    cout << ans << "\n";
}
