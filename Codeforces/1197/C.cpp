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
    int wt = n-k;
    vector<int> dif;
    int lst = -1;
    for(int i=0;i<n;i++){
        int cur;
        cin >> cur;
        if(i != 0) dif.push_back(cur - lst);
        lst = cur;
    }
    sort(dif.begin(), dif.end());
    ll ans = 0;
    for(int i=0;i<wt;i++) ans += dif[i];
    cout << ans << "\n";
}
