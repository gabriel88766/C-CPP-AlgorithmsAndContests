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
        string l, r;
        cin >> l >> r;
        bool dif = false;
        int ans = 0;
        for(int i=0;i<l.size();i++){
            if(dif){
                if(l[i] == '9' && r[i] == '0'){
                    ans++;
                }else break;
            }else{
                if(l[i] == r[i]){
                    ans += 2;
                }else if(r[i] > l[i] + 1) break;
                else{
                    dif = true;
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }   
}
