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
    int h,w,n;
    cin >> h >> w >> n;
    string s;
    cin >> s;
    vector<string> gr(h);
    for(int i=0;i<h;i++) cin >> gr[i];

    int ans = 0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            int curi = i, curj = j;
            bool ok = true;
            if(gr[curi][curj] == '#') ok = false;
            else{
                for(int k=0;k<n;k++){
                    if(s[k] == 'L') curj--;
                    else if(s[k] == 'R') curj++;
                    else if(s[k] == 'U') curi--;
                    else if(s[k] == 'D') curi++;
                    if(curi < 0 || curi >= h || curj < 0 || curj >= w || gr[curi][curj] == '#'){
                        ok = false;
                        break;
                    }
                }
            }
            if(ok) ans++;
        }
    }
    cout << ans << "\n";
}
