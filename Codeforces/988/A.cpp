#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, k;
    cin >> n >> k;
    map<int,int> mp;
    vector<int> v(n);
    vector<int> ans;
    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=0;i<n;i++){
        if(!mp[v[i]]){
            mp[v[i]] = 1;
            ans.push_back(i+1);
        }
    }
    if(ans.size()>=k){
        cout << "YES\n";
        for(int i=0;i<k;i++) cout << ans[i]<< " ";
    }else cout << "NO";
}
