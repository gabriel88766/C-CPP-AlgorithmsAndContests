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
        vector<int> d(n);
        for(int i=0;i<n;i++) cin >> d[i];
        int lx = 0, rx = 0;
        vector<pair<int, int>> inp(n);
        for(int i=0;i<n;i++){
            cin >> inp[i].first >> inp[i].second;
        }
        bool ok = true;
        vector<pair<int, int>> cv;
        for(int i=0;i<n;i++){
            auto [l, r] = inp[i];
            if(d[i] == -1) rx++;
            else if(d[i] == 1) lx++, rx++;
            lx = max(lx, l);
            rx = min(rx, r);
            cv.push_back({lx, rx});
            if(rx < lx){
                ok = false;
                break;
            }
        }
        if(ok){
            int val = cv[n-1].second;
            for(int i=n-1;i>=0;i--){
                int l_l = i == 0 ? 0 : cv[i-1].first;
                int l_r = i == 0 ? 0 : cv[i-1].second;
                if(val - 1 >= l_l && (d[i] == -1 || d[i] == 1)) d[i] = 1, val--;
                else d[i] = 0;
                assert(val >= l_l && val <= l_r);
            }
            for(int i=0;i<n;i++) cout << d[i] << " ";
            cout << "\n";
        }else cout << "-1\n";
    }
}
 