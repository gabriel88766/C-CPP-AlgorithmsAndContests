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
    bool rev = false;
    cin >> n >> m;
    if(n > m){
        swap(n, m);
        rev = true;
    }
    int cx = m;
    vector<pair<int,int>> ans;
    for(int i=n;i>=1;i--){
        for(int j=cx;j>=max(cx-2,1);j--){
            ans.push_back({i, j});
        }
        if(i != n && i % 2 == n % 2){
            for(int j=cx-3;j>=max(1, cx-4);j--){
                ans.push_back({i, j});
            }
        }
        if(i == 1){
            for(int j=ans.back().second - 1; j>=1;j--) ans.push_back({i, j});
        }
        if(i != n && i % 2 == n % 2) cx -= 2;
    }
    if(rev){
        for(auto &[a, b] : ans) swap(a, b);
    }
    cout << ans.size() << "\n";
    for(auto [a, b] : ans) cout << a << " " << b << "\n";
}
