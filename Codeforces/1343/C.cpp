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
        vector<pair<int,int>> in;
        int sg = 0;
        int l = 0;
        for(int i=0;i<n;i++){
            if(i == 0){
                if(v[i] > 0) sg = 1;
                else sg = -1;
            }else{
                if(v[i] > 0){
                    if(sg == -1){
                        in.push_back({l, i-1});
                        l = i;
                        sg = 1;
                    }
                }else{
                    if(sg == 1){
                        in.push_back({l, i-1});
                        l = i;
                        sg = -1;
                    }
                }
            }
        }
        in.push_back({l, n-1});
        ll ans = 0;
        for(auto x : in){
            ans += *max_element(v.begin()+x.first, v.begin()+x.second+1);
        }
        cout << ans << "\n";
    }
}
