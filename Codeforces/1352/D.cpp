#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a = 0, b = 0, m = 0, bp = 0, ep = n-1, lm = 0;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        char am = 1;
        while(ep >= bp){
            int cs = 0;
            if(am){
                while(ep >= bp){
                    cs += v[bp++];
                    if(cs > lm) break;
                }
                lm = cs;
                a += cs;
                m++;
            }else{
                while(ep >= bp){
                    cs += v[ep--];
                    if(cs > lm) break;
                }
                lm = cs;
                b += cs;
                m++;
            }
            am ^= 1;
        }
        cout << m << " " << a << " " << b << "\n";
    }
}
