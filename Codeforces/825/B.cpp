#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool check(int x){
    return x < 10 && x >= 0;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    vector<string> v(10);
    for(int i=0;i<10;i++) cin >> v[i];
    bool ok = false;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
            for(int k=0;k<=4;k++){
                if(check(j+k)){
                    if(v[i][j+k] == 'X') cnt1++;
                    else if(v[i][j+k] == 'O') cnt1 = -INF_INT;
                }else cnt1 = -INF_INT;

                if(check(i+k)){
                    if(v[i+k][j] == 'X') cnt2++;
                    else if(v[i+k][j] == 'O') cnt2 = -INF_INT;
                }else cnt2 = -INF_INT;

                if(check(i+k) && check(j+k)){
                    if(v[i+k][j+k] == 'X') cnt3++;
                    else if(v[i+k][j+k] == 'O') cnt3 = -INF_INT;
                }else cnt3 = -INF_INT;

                if(check(i+k) && check(j-k)){
                    if(v[i+k][j-k] == 'X') cnt4++;
                    else if(v[i+k][j-k] == 'O') cnt4 = -INF_INT;
                }else cnt4 = -INF_INT;
                
            }
            if(cnt1 == 4 || cnt2 == 4 || cnt3 == 4 || cnt4 == 4) ok = true;
        }
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
}
