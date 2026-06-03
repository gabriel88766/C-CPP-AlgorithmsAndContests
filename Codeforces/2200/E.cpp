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
        cin >> n;
        bool ok = true;
        bool ok2 = true;
        bool ok3 = true;
        int lp = 0;
        int lv = 0;
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            if(x < lv) ok2 = false;
            lv = x;
            vector<int> pr;
            for(int i=2;i*i<=x;i++){
                if(x % i == 0){
                    pr.push_back(i);
                    while(x % i == 0){
                        x /= i;
                    }
                }
            }
            if(x != 1) pr.push_back(x);
            if(pr.size() >= 2){
                ok = false;
            }else{
                int cp;
                if(pr.size() == 1) cp = pr[0];
                else cp = 1;
                if(cp < lp){
                    ok3 = false;
                }
                lp = cp;
            }
        }
        if((ok && ok3) || ok2) cout << "Bob\n";
        else cout << "Alice\n";
    }
}
