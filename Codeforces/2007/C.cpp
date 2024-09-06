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
        int n, a, b;
        cin >> n >> a >> b;
        int g = gcd(a, b);
        vector<int> vr;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            vr.push_back(x % g);
        }
        sort(vr.begin(), vr.end());
        vr.resize(unique(vr.begin(), vr.end()) - vr.begin());
        int ans = INF_INT;
        for(int i=0;i<vr.size();i++){
            //sequency starts in vr[i] and ends in vr[i-1];
            if(i == 0){
                int cur = vr.back() - vr[0];
                ans = min(ans, cur);
            }else{
                int cur = vr[i-1] - vr[i] + g;
                ans = min(ans, cur);
            }
        }
        cout << ans << "\n";
    }
}
