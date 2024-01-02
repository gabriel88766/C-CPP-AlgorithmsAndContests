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
        vector<pair<int,int>> vp(n);
        for(int i=0;i<n;i++) cin >> vp[i].first;
        for(int i=0;i<n;i++) cin >> vp[i].second;
        sort(vp.begin(), vp.end());
        int r = 1, c = 1;
        ll ans = 0;
        for(int i=0;i<n;i++){
            if(vp[i].first == r && vp[i].second == c){
                assert(i == 0);
                continue;
            }
            int dif = vp[i].second - c;
            int dr = vp[i].first - r;
            int mv = (r+c) % 2 ? dr : dr - 1;
            if(mv + c < vp[i].second) ans += vp[i].second - c;
            else{
                ans += (mv+c - vp[i].second + 1)/2;
            }

            r = vp[i].first, c = vp[i].second;
        }
        cout << ans << "\n";
    }
}   
