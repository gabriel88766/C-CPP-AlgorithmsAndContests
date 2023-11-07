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
        string s;
        cin >> n >> s;
        bool okA = false, okB = false;
        for(int x=1;x<=n;x++){
            int c1 = 0, c2 = 0, ca = 0, cb = 0;
            bool la, lb;
            for(int i=0;i<n;i++){
                if(s[i] == 'B') cb++;
                else ca++;
                if(ca == x || cb == x){
                    if(ca == x){
                         c1++;
                         la = true;
                         lb = false;
                    }else{
                         c2++;
                         la = false;
                         lb = true;
                    }
                    ca = cb = 0;
                }
            }
            if(ca == 0 && cb == 0){
                if(c1 != c2){
                    if(c1 > c2 && la) okA = true;
                    else if(c1 < c2 && lb ) okB = true;
                }
            }
        }
        if(okA && okB) cout << "?\n";
        else if(okA) cout << "A\n";
        else cout << "B\n";
    }
}
