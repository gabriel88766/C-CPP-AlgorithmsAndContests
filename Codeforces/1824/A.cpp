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
        int n, m;
        cin >> n >> m;
        vector<int> v;
        int c1 = 0, c2 = 0;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            if(x == -1) c1++;
            else if(x == -2) c2++;
            else v.push_back(x);
        }
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        int ans = v.size() + max(c1, c2);
        ans = min(ans, m);
        int sz = v.size();
        for(int i=0;i<v.size();i++){
            int cur = min(v[i]-1, i + c1) + 1;
            cur += min(m-v[i], sz-i-1 + c2);
            ans = max(ans, cur);
        }
        cout << ans << "\n";
    }
}
