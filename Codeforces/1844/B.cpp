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
        if(n == 1) cout << "1\n";
        else if(n == 2) cout << "2 1\n";
        else{
            vector<int> ans(n);
            ans[0] = 2;
            ans[n-1] = 3;
            ans[n/2] = 1;
            int num = 3;
            for(int i=0;i<n;i++){
                if(ans[i] == 0){
                    ans[i] = ++num;
                }
            }
            for(int i=0;i<n;i++) cout << ans[i] << " ";
            cout << "\n";
        }
    }
}
