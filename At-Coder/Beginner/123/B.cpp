#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int v[5];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int ans = 0;
    vector<int> rs;
    for(int i=0;i<=4;i++){
        cin >> v[i];
        ans += v[i];
        rs.push_back((200 - v[i]) % 10);
    }
    sort(rs.begin(), rs.end(), greater<int>());
    for(int i=1;i<=4;i++) ans += rs[i];
    cout << ans << "\n";
}
