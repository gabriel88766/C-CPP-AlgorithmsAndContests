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
        int a, b;
        cin >> a >> b;
        int x1 = 31 - __builtin_clz(a), x2 = 31 - __builtin_clz(b);
        if(x1 < x2) cout << "-1\n";
        else{
            vector<int> ans;
            for(int j=x2;j>=0;j--){
                if((b & (1 << j)) && (!(a & (1 << j)))){
                    ans.push_back(1 << j);
                    a ^= (1 << j);
                }
            }
            for(int j=x1;j>=0;j--){
                if((a & (1 << j)) && (!(b & (1 << j)))){
                    ans.push_back(1 << j);
                    a ^= (1 << j);
                }
            }
            assert(a == b);
            cout << ans.size() << "\n";
            for(auto x : ans) cout << x << " ";
            cout << "\n";
        }
    }
}
