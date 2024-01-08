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
        string s;
        cin >> s;
        int n = s.size();
        int p1 = 0, p2 = n-1, p = n-1;
        bool ok = true;
        while(p2 >= p1){
            char c = 'a' + p;
            if(s[p1] == c){
                p1++;
                p--;
            }else if(s[p2] == c){
                p2--;
                p--;
            }else{
                ok = false;
                break;
            }
        }   
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
