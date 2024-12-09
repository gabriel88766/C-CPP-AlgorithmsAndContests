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
        vector<int> cd(10, 0);
        string s;
        cin >> s;
        for(auto c : s){
            cd[c-'0']++;
        }
        int cr = 0;
        for(int i=1;i<=8;i++){
            cr = (cr + cd[i] * i) % 9;
        }
        //2 -> 4 sum 2
        //3 -> 9 sum 6
        bool ok = false;
        for(int i=0;i<=min(8, cd[2]); i++){
            for(int j=0;j<=min(2, cd[3]); j++){
                int cur = (cr + i*2 + j*6) % 9;
                if(cur == 0) ok = true;
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
