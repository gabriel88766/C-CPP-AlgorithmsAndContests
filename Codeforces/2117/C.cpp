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
        int ans = 0, n;
        cin >> n;
        set<int> pt, npt, xtr;
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            if(i == 1){
                ans++;
                pt.insert(x);
            }else{
                if(pt.count(x)) npt.insert(x);
                else xtr.insert(x);
                if(pt.size() == npt.size()){
                    ans++;
                    npt.clear();
                    for(auto &x : xtr) pt.insert(x);
                    xtr.clear();
                }
            }
        }
        cout << ans << "\n";
    }
}
