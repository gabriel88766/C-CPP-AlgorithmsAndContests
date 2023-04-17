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
    bool ispos;
    int maxv = 0;
    int n, ind;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(abs(a[i]) > maxv){
            ispos = a[i] > 0;
            maxv = abs(a[i]);
            ind = i;
        }
    }
    if(maxv == 0) cout << "0\n";
    else{
        vector<pair<int,int>> ans;
        if(ispos){
            if(a[1] < 0) ans.push_back({ind, 1});
            ans.push_back({ind, 1});
            for(int i=2;i<=n;i++){
                if(a[i] < 0) ans.push_back({i-1, i});
                ans.push_back({i-1, i});
            }
        }else{
            if(a[n] > 0) ans.push_back({ind, n});
            ans.push_back({ind, n});
            for(int i=n-1;i>=1;i--){
                if(a[i] > 0) ans.push_back({i+1, i});
                ans.push_back({i+1, i});
            }
        }
        cout << ans.size() << "\n";
        for(auto x: ans) cout << x.first << " " << x.second << "\n";
    } 
}
