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
        int p, s;
        cin >> p >> s;
        if(p == 1){
            //make square 200x200
            cout << 800 * s << "\n";
            for(int i=0;i<200;i++) cout << 0 << " " << i << "\n";
            for(int i=1;i<200;i++) cout << i << " " << 0 << "\n";
            int mss = 800*s - 399;
            for(int i=1;i<200;i++){
                for(int j=1;j<200;j++){
                    if(mss){
                        cout << i << " " << j << "\n";
                        mss--;
                    }
                }
            }
        }else if(2*s >= p){
            int xp = p, xs = s;
            while(xp % 4 != 0) xp*=2, xs*=2;
            while((xp/4)*(xp/4) < xs) xp*=2, xs *= 2;
            int pp = xp / 4;
            cout << xs << "\n";
            for(int i=0;i<pp;i++) cout << 0 << " " << i << "\n";
            for(int i=1;i<pp;i++) cout << i << " " << 0 << "\n";
            xs -= 2*pp - 1;
            for(int i=1;i<pp;i++){
                for(int j=1;j<pp;j++){
                    if(xs){
                        cout << i << " " << j << "\n";
                        xs--;
                    }
                }
            }
        }else{
            int g = gcd(p, s);
            s /= g, p /= g;
            if(p > 2*(s+1)) cout << "-1\n";
            else{
                if(p < 2*(s+1)) p*= 2, s *= 2;
                assert(p == 2*(s+1));
                cout << s << "\n";
                for(int i=0;i<s;i++) cout << 0 << " " << i << "\n";
            }
        }
    }
}
