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
    set<pair<int, int>> st;
    int n;
    cin >> n;
    vector<pair<int, int>> vp(n+1);
    for(int i=1;i<=n;i++){
        cin >> vp[i].first >> vp[i].second;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == j) continue;
            int x = vp[i].first - vp[j].first;
            int y = vp[i].second - vp[j].second;
            int g = gcd(abs(x), abs(y));
            x /= g;
            y /= g;
            st.insert({x, y});
        }
    }
    cout << st.size() << "\n";
}
