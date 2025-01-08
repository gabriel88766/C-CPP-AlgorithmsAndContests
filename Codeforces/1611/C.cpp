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
        vector<int> vx;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            vx.push_back(x);
        }
        if(vx[0] == n){
            cout << vx[0] << " ";
            for(int i=n-1;i>=1;i--) cout << vx[i] << " ";
            cout << "\n";
        }else if(vx.back() == n){
            for(int i=n-2;i>=0;i--) cout << vx[i] << " ";
            cout << vx[n-1] << "\n";
        }else cout << "-1\n";

    }
}
