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
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    s = " " + s + " ";
    vector<int> pr(n+2, 0), su(n+2, 0);
    for(int i=1;i<=n;i++){
        pr[i] = pr[i-1];
        if(pr[i] < m && s[i] == t[pr[i]]) pr[i]++;
    }
    for(int i=n;i>=1;i--){
        su[i] = su[i+1];
        if(su[i] < m && s[i] == t[m-su[i]-1]) su[i]++;
    }
    int ans = 0;
    for(int i=n+1;i>=2;i--){
        int r = m - su[i];
        int lo = 0, hi = i-1;
        while(lo != hi){
            int mid = lo + (hi - lo )/2;
            if(pr[mid] >= r) hi = mid;
            else lo = mid + 1;
        }
        ans = max(ans, i-lo-1);
    }
    cout << ans << "\n";
}
