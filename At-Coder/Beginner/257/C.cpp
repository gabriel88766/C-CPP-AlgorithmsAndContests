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
    string s;
    cin >> n >> s;
    vector<int> v1, v0;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(s[i] == '1') v1.push_back(x);
        else v0.push_back(x);
    }
    sort(v1.begin(), v1.end());
    sort(v0.begin(), v0.end());
    int ans = v0.size(); //all children ok
    for(int i=0;i<v1.size();i++){
        //children weight less than v1[i];
        int cur = v1.size() - i;
        auto it = lower_bound(v0.begin(), v0.end(), v1[i]);
        cur += it - v0.begin();
        ans = max(ans, cur);
    }
    cout << ans << "\n";
}
