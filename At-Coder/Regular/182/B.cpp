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
        int n, k;
        cin >> n >> k;
        vector<int> vx(n, 1);
        int mx = (1 << k) - 1;
        for(int i=0;2*i+1<=mx && i < n;i++){
            int num = 2*i + 1;
            while(2*num <= mx) num *= 2;
            vx[i] = num;
        }
        for(auto x : vx) cout << x << " ";
        cout << "\n";
    }
}
