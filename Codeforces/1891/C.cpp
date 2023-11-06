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
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        sort(v.begin(), v.end());
        int p1 = 0, p2 = n-1;
        ll ans = 0;
        int ch = 0;
        while(p1 < p2){
            if(v[p1] + ch <= v[p2]){
                ch += v[p1];
                ans += v[p1];
                p1++;
            }else{
                int cur = v[p2] - ch;
                v[p1] -= cur;
                ans += cur + 1;
                p2--;
                ch = 0;
            }
        }
        int dif = v[p1] - ch;
        ch += dif/2;
        if(ch){
            ans += dif/2 + 1;
            v[p1] -= (dif/2) + ch;
        }
        if(v[p1]) ans++;
        cout << ans << "\n";

    }
}
