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
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        bool hb = false;
        for(auto c : s) if(c == 'B') hb = true;
        if(hb){
            //brute force allowed;
            for(int i=0;i<q;i++){
                int x;
                cin >> x;
                int ans = 0;
                while(x){
                    for(auto c : s){
                        ans++;
                        if(c == 'A') x--;
                        else x /= 2;
                        if(x == 0) break;
                    }
                }
                cout << ans << "\n";
            }
        }else{
            for(int i=0;i<q;i++){
                int x;
                cin >> x;
                cout << x << "\n";
            }
        }
    }
}
