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
    s = " " + s;
    vector<int> ps(n+1);
    for(int i=1;i<=n;i++){
        if(s[i] == 'x') ps[i] = 1;
        ps[i] += ps[i-1];
    }
    int tt = 0, ans = 0;
    for(int i=1;i<=n;i++){
        if(s[i] == 'o') tt++;
        //find largest x, such that ps[x] - ps[i] <= tt, except if tt = 0;
        if(tt == 0) cout << i << "\n";
        else{
            ans = max(ans, i);
            while(ans < n && ps[ans + 1] - ps[i] < tt) ans++;
            cout << min(ans + 1, n) << "\n";
        }
    }
}
