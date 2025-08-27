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
    int t, x;
    cin >> t;
    while(t--){
        string s, os, ord;
        cin >> x >> s >> x >> os >> ord;
        for(int i=0;i<ord.size();i++){
            if(ord[i] == 'D'){
                s = s + os[i];
            }else{
                s = os[i] + s;
            }
        }
        cout << s << "\n";
    }
}
