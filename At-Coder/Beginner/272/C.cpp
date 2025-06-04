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
    vector<int> ev, od;
    int n;
    cin >> n;
    int ans = -1;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(x % 2) od.push_back(x);
        else ev.push_back(x);
    }
    sort(ev.begin(), ev.end(), greater<int>());
    sort(od.begin(), od.end(), greater<int>());
    if(ev.size() >= 2) ans = max(ans, ev[0] + ev[1]);
    if(od.size() >= 2) ans = max(ans, od[0] + od[1]);
    cout << ans << "\n";
}
