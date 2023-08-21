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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v((n*(n-1))/2);
        for(int i=0;i<v.size();i++) cin >> v[i];
        sort(v.begin(), v.end());
        int cur = 0;
        vector<int> ans;
        for(int i=n-1;i>=1;i--){
            ans.push_back(v[cur]);
            cur += i;
        }
        ans.push_back(ans.back());
        for(auto x : ans) cout << x << " ";
        cout << "\n";
    }
}
