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
        int n, m;
        cin >> n >> m;
        bool ok = true;
        vector<pair<int,int>> vp;
        for(int i=0;i<m;i++){
            int r, c;
            cin >> r >> c;
            vp.push_back({c, r});
        }
        if(m % 2){
            cout << "NO\n";
            continue;
        }
        sort(vp.begin(), vp.end());
        int b = 0;
        int olr = 0;
        int fb = -1;
        for(int i=0;i<m;i++){
            auto [c, r] = vp[i];
            if(c == fb && r == 2){
                ok = false;
                break;
            }
            if(!olr){
                olr = r;
            }else{
                if((c - b - (r == olr ? 1 : 0)) % 2){
                    ok = false;
                    break;
                }
                fb = c;
                olr = 0;
            }
            b = c;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}