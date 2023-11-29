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
    vector<pair<int,int>> ans;
    int l = 1;
    map<int,int> mp;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        mp[x]++;
        if(mp[x] == 2){
            ans.push_back({l, i});
            mp.clear();
            l = i+1;
        }
    }
    if(ans.size()){
        ans.back().second = n;
        cout << ans.size() << "\n";
        for(auto [x, y] : ans) cout << x << " " << y << "\n";
    }else cout << "-1\n";
    
}
