#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
   
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 1);
    for(int i=1;i<=500;i++){
        shuffle(ans.begin(), ans.end(), rng);
        bool ok = true;
        for(int j=0;j<n;j++){
            if(ans[j] == a[j] || ans[j] == b[j]) ok = false;
        }
        if(ok){
            for(auto &x: ans) cout << x << " ";
            cout << "\n";
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";//I guess...
}
