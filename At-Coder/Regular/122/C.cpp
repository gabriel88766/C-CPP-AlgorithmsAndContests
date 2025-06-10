#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll fib[105];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    fib[0] = fib[1] = 1;
    for(int i=2;i<=88;i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    ll n = 1000000000000000000LL;
    cin >> n;
    if(n <= 130){
        cout << n << "\n";  
        while(n--) cout << "1\n";
        return 0;
    }
    vector<int> idx;
    vector<int> ans;
    int fi = -1;
    for(int i=88;i>=0;i--){
        if(n >= fib[i]) {
            if(fi == -1) fi = i;
            n -= fib[i];
            idx.push_back(fi - i);
        }
    }
    // cout << fi << "\n";
    ll x = 0, y = 0, p = 0;
    for(int i=0;i<fi-1;i++){
        if(p < idx.size() && idx[p] == i){
            if(x > y){
                ans.push_back(1);
                x++;
            }else{
                ans.push_back(2);
                y++;
            }
            p++;
        }
        if(x > y){
            ll z = x + y;
            y = z;
            ans.push_back(4);
        }else{
            ll z = x + y;
            x = z;
            ans.push_back(3);
        }
        // cout << max(x, y) << " " << fib[i] << "\n";
    }
    if(p < idx.size()){
        ans.push_back(1);
        x++;
    }
    // cout << x << " " << y << endl;
    ans.push_back(3);
    x = x + y;
    // cout << x << "\n";
    // assert(x == n);;
    cout << ans.size() << "\n";
    for(auto &x : ans) cout << x << "\n";
}
