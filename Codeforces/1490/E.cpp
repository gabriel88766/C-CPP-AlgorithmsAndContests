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
        vector<pair<int,int>> vp;
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            vp.push_back({x, i});
        }
        sort(vp.begin(), vp.end());
        int lo = 0, hi = vp.size() - 1;//FF...TTTTT bin search
        while(lo != hi){
            int mid = lo + (hi - lo)/2;
            ll sum = 0;
            for(int i=0;i<=mid;i++){
                sum += vp[i].first;
            }
            bool ok = true;
            for(int i=mid+1;i<vp.size();i++){
                if(sum < vp[i].first){
                    ok = false;
                    break;
                }else sum += vp[i].first;
            }
            if(ok) hi = mid;
            else lo = mid + 1;
        }
        vector<int> ans;
        for(int i=lo;i<vp.size();i++) ans.push_back(vp[i].second);
        sort(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for(auto x : ans) cout << x << " ";
        cout << "\n";
    }
}
