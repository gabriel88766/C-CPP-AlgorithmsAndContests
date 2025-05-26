#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
ll der[N], ans[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    set<int> xl;
    xl.insert(0);
    xl.insert(n+1);
    vector<pair<int, int>> v;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        v.push_back({x, i});
    }
    sort(v.begin(), v.end(), greater<pair<int,int>>());
    vector<tuple<int, int, int>> vals;
    for(auto &[x, j] : v){
        auto it = xl.lower_bound(j);
        auto it2 = prev(it);
        int sz = *it - *it2 - 1;
        int pos = j - *it2;
        vals.push_back({x, sz, pos});
        xl.insert(j);
    }
    for(auto &[a, b, c] : vals) {
        // cout << a << " " << b << " " << c << "\n";
        int mx = min(c, b - c + 1);
        int start = 1;
        int stop_gr = mx + 1;
        int start2 = b - mx + 2;
        int stop_2 = b + 2;
        der[start] += a;
        der[stop_gr] -= a;
        der[start2] -= a;
        der[stop_2] += a;
        // for(int i=1;i<=n+1;i++) cout << der[i] << " ";
        // cout << "\n";
    }


    for(int i=2;i<=n;i++) der[i] += der[i-1];
    // for(int i=1;i<=n+1;i++) cout << der[i] << " ";
        // cout << "\n";
    for(int i=1;i<=n;i++){
        ans[i] = ans[i-1] + der[i];
        cout << ans[i] << "\n";
    }


}
