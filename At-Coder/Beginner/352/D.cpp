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
    vector<int> v(n+1), ind(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        ind[v[i]] = i;
    }
    set<int> indx;
    int ans = INF_INT;
    for(int i=1;i<=n;i++){
        indx.insert(ind[i]);
        if(i > k) indx.erase(ind[i-k]);
        int l = *indx.begin();
        int h = *prev(indx.end());
        if(i >= k) ans = min(ans, h - l);
    }
    cout << ans << "\n";
}
