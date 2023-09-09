#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct thisAns{
    int a, b, c, d;
};

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
        vector<int> a(n+1, 0);
        for(int i=1;i<=n;i++) cin >> a[i];
        if(n == 1){
            cout << "0\n";
            continue;
        }
        vector<thisAns> ans;
        int val = INF_INT, ind = -1;
        for(int i=1;i<=n;i++){
            if(a[i] < val){
                val = a[i];
                ind = i;
            }
        }
        if(ind != 1) ans.push_back({1, ind, val, INF_INT});
        for(int i=2;i<=n;i++){
            ans.push_back({1, i, val, val+i-1});
        }
        cout << ans.size() << "\n";
        for(auto x : ans){
            cout << x.a << " " << x.b << " " << x.c << " " << x.d << "\n";
        }
    }
}
