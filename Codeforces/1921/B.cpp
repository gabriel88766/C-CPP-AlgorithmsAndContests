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
        string s1, s2;
        cin >> n >> s1 >> s2;
        int mt = 0;
        int q1 = 0, q2 = 0;
        for(int i=0;i<n;i++){
            if(s1[i] == '1' && s2[i] == '1') mt++;
            if(s1[i] == '1') q1++;
            if(s2[i] == '1') q2++;
        }
        int minq = min(q1, q2), maxq = max(q1, q2);
        int ans = maxq - minq;
        ans += minq - mt;
        cout << ans << "\n";
    }
}
