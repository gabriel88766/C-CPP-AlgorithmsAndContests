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
        int co = 0;
        int c1 = 0, c0 = 0;
        int n;
        cin >> n;
        for(int i=0;i<n;i++){
            string s;
            cin >> s;
            for(auto c : s){
                if(c == '1') c1++;
                else c0++;
            }
            if(s.size() % 2) co++;
        }
        if(c1 % 2 && c0 % 2){
            if(co) cout << n << "\n";
            else cout << n-1 << "\n";
        }else cout << n << "\n"; 
    }
}
