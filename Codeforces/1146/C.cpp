#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int ask(int u, vector<int> v){
    cout << 1 << " " << v.size() << " " << u << " ";
    for(auto x : v) cout << x << " ";
    cout << "\n";
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}
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
        if(n == -1) return 0;
        int lo = 2, hi = n;
        vector<int> vx;
        for(int i=2;i<=n;i++) vx.push_back(i);
        int xx = ask(1, vx); 
        while(lo != hi){
            int mid = lo + (hi - lo) / 2;
            vector<int> vx;
            for(int i=2;i<=mid;i++) vx.push_back(i);
            int now = ask(1, vx);
            if(now == xx) hi = mid;
            else lo = mid + 1;
        }
        vector<int> av;
        for(int i=1;i<=n;i++){
            if(i == lo) continue;
            av.push_back(i);
        }
        int ans = ask(lo, av);
        cout << "-1 " << ans << "\n";
        cout.flush();
    }
}
