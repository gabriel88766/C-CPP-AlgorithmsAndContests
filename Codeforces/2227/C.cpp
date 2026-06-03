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
        vector<int> v1, v2, v3, v6;
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            if(x % 6 == 0) v6.push_back(x);
            else if(x % 3 == 0) v3.push_back(x);
            else if(x % 2 == 0) v2.push_back(x);
            else v1.push_back(x);
        }
        for(auto x : v6) cout << x << " ";
        for(auto x : v2) cout << x << " ";
        for(auto x : v1) cout << x << " ";
        for(auto x : v3) cout << x << " ";
        cout << "\n";
    }
}
