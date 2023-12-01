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
        if(n == 1){
            cout << "0\n";
        }else{
            int mine = *min_element(v.begin(), v.end());
            int maxe = *max_element(v.begin(), v.end());
            if(mine == maxe) cout << "0\n";
            else{
                vector<int> ans;
                while(mine != maxe){
                    int x;
                    if(mine % 2) x = 1;
                    else x = 0;
                    ans.push_back(x);
                    maxe = (maxe + x)/2;
                    mine = (mine + x)/2;
                }
                cout << ans.size() << "\n";
                if(ans.size() <= n){
                     for(auto x: ans) cout << x << " ";
                     cout << "\n";
                }
            }
        }
    }
}
