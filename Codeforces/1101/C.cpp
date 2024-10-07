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
        vector<tuple<int,int,int>> vt(n);
        for(int i=0;i<n;i++){
            int a, b;
            cin >> a >> b;
            vt[i] = {a, b, i};
        }
        sort(vt.begin(), vt.end());
        int ind = -1, gr = 0;
        for(int i=0;i<n;i++){
            auto [a, b, c] = vt[i];
            if(i > 0){
                //check
                if(a > gr){
                    ind = i;
                    break;
                }
            }
            gr = max(gr, b);
        }
        if(ind == -1) cout << "-1\n";
        else{
            vector<int> ans(n);
            for(int i=0;i<ind;i++){
                auto [a, b, c] = vt[i];
                ans[c] = 1;
            }
            for(int i=ind;i<n;i++){
                auto [a, b, c] = vt[i];
                ans[c] = 2;
            }
            for(int i=0;i<n;i++) cout << ans[i] << " ";
            cout << "\n";
        }
    }   
}
