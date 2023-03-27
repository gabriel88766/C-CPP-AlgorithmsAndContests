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
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> v(n);
    vector<int> u;
    for(int i=0;i<n;i++) {cin >> v[i].first; v[i].second = i+1;}
    sort(v.begin(), v.end(), greater<pair<int,int>>());
    int ans = 0;
    for(int i=0;i<k;i++){
        ans += v[i].first;
        u.push_back(v[i].second);
    }
    sort(u.begin(), u.end());
    int cur = 0;
    cout << ans << "\n";
    for(int i=1;i<=k;i++){
        if(i != k) cout << u[i-1]-cur << " ";
        else cout << n-cur << " ";
        cur = u[i-1];
    }
}
