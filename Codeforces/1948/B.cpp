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
        bool ok = true;
        int n;
        cin >> n;
        vector<string> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        int cur = INF_INT;
        for(int i=n-1;i>=0;i--){
            if(stoi(v[i]) <= cur) cur = stoi(v[i]);
            else{
                //must split!
                if(v[i].size() == 1){
                    //can't
                    ok = false;
                    break;
                }else{
                    //can
                    int i1 = v[i][0] - '0';
                    int i2 = v[i][1] - '0';
                    if(i1 <= i2 && i2 <= cur){
                        //it's fine!
                        cur = i1;
                    }else{
                        //dammit!
                        ok = false;
                        break;
                    }
                }
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
