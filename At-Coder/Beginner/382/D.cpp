#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<vector<int>> ans;
vector<int> cur;
void solve(int &n, int &m){
    if(cur.size() == n){
        ans.push_back(cur);
        return;
    }
    int mc, bg;
    if(!cur.size()){
        bg = 1;
        mc = m - (n-1) * 10;
    }else{
        bg = cur.back() + 10;
        mc = m - (n - cur.size() - 1) * 10;
    }
    for(int j=bg;j<=mc;j++){
        cur.push_back(j);
        solve(n, m);
        cur.pop_back();
    }

}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    solve(n, m);
    cout << ans.size() << "\n";
    for(auto x : ans){
        for(auto y : x) cout << y << " ";
        cout << "\n";
    }
}
