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
    map<int,int> mp;
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        mp[v[i]]++;
    }
    int num = 0, maxv = 0;
    for(auto x: mp){
        if(maxv < x.second){
            maxv = x.second;
            num = x.first;
        }
    }
    int ind;
    for(int i=n;i>=1;i--){
        if(v[i] == num){
            ind = i;
            break;
        }
    }
    vector<pair<int,int>> ans;
    if(ind < n){
        for(int i=ind+1;i<=n;i++){
            ans.push_back({i, i-1});
        }
    }
    for(int i=ind-1;i>=1;i--){
        if(v[i] != num) ans.push_back({i, i+1});
    }
    cout << ans.size() << "\n";
    for(int i=0;i<ans.size();i++){
        if(v[ans[i].first] < num) cout << "1 ";
        else cout << "2 ";
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
}
 