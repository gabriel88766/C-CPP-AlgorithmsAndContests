#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test inpu
    int n, k, t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        if(!(k % 2) && n%2){
            cout << "NO\n";
            continue;
        }
        vector<int> ans;
        if(k%2 && !(n%2)){
            if((2 * k) > n){
                cout << "NO\n";
                continue;
            }else{
                for(int i=1;i<k;i++){
                    ans.push_back(2);
                    n -= 2;
                }
                ans.push_back(n);
            }
        }else{
            if(k > n){
                cout << "NO\n";
                continue;
            }else{
                for(int i=1;i<k;i++){
                    ans.push_back(1);
                    n --;
                }
                ans.push_back(n);
            }
        }
        cout << "YES\n";
        for(int i=0;i<ans.size();i++) cout << ans[i] << " ";
        cout << "\n";
    }
}
