#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll p2[62];
map<char, string> mp = {{'A', "BC"}, {'B', "CA"}, {'C', "AB"}};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s;
    cin >> s;
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        ll t, k;
        cin >> t >> k;
        k--;
        //A → BC, B → CA, C → AB
        //CBBAACCCCC
        char cx;
        if(t >= 61){
            ll off = t - 60;
            int x = s[0]-'A';
            x += off % 3;
            x %= 3;
            cx = 'A' + x;
            t = 60;
        }else {
            ll p = 0;
            for(int j=59;j>=t;j--){
                p <<= 1;
                if(k & (1LL << j)) p += 1;
            }
            assert(p < s.size());
            cx = s[p];
        }
        
        for(int j=t-1;j>=0;j--){
            if(k & (1LL << j)) cx = mp[cx][1];
            else cx = mp[cx][0];
        }
        cout << cx << "\n";
    }
}
