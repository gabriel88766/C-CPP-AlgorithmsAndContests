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
    vector<string> v(8);
    for(int i=0;i<8;i++) cin >> v[i];
    vector<bool> rr(8, true), cr(8, true);
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(v[i][j] == '#'){
                rr[i] = false;
                cr[j] = false;
            }
        }
    }
    int a = 0, b = 0;
    for(int i=0;i<8;i++){
        if(rr[i]) a++;
        if(cr[i]) b++;
    }
    cout << a*b << "\n";
}
