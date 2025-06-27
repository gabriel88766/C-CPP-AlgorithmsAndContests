#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll a[6], b[6];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    
    int t;
    cin >> t;
    while(t--){
        for(int i=1;i<=5;i++) cin >> a[i];
        for(int i=1;i<=5;i++) cin >> b[i];
        ll mn = min(b[5], a[5]);
        b[5] -= mn;
        a[5] -= mn;
        bool ok = true;
        if(a[5]) ok = false;
        else{
            //a[5] == 0
            if(b[5] + b[4] >= a[4]){
                //make both a[4] and a[3] zero
                if(b[5] + b[4] + b[3] >= a[4] + a[3]){
                    //make both a[4] and a[3] and a[2] zero
                    //TODO this check : we can make both a[4] and a[3] and a[2] zero
                    ll mn = min(a[2], b[2]);
                    a[2] -= mn;
                    b[2] -= mn;
                    mn = min(a[3], b[3]);
                    a[3] -= mn;
                    b[3] -= mn; //Should I??
                    if(a[2] != 0 && a[3] != 0){
                        ll df = b[5] + b[4] - a[4];
                        ll tw = min(b[5], df); // 3 2 or 2 2
                        ll on = df - tw; // 2 2 or 3

                        //a1 + a2 <= tw
                        //a3 + a4 <= on
                        //a1 + a4 = a[3]
                        //a1 + 2*a2 + 2*a3 = a[2]
                        // cout << 2*df + b[3] << " " << tw << " " << a[3] + a[2] << " -- ";
                        if(tw + on >= a[3]){
                            // ll dif = tw + on - a[3];
                            ll c2 = 0;
                            if(a[3] >= tw){
                                c2 += tw;
                                c2 += (tw + on - a[3]) * 2;
                            }else{
                                c2 += a[3];
                                c2 += (tw - a[3]) * 2;
                                c2 += on * 2;
                            }
                            if(c2 < a[2]) ok = false;
                        }else ok = false;
                        // else
                    }else if(a[2]){
                        if(2*(b[5] + b[4] - a[4]) + b[3] >= a[2]);
                        else ok = false;
                    }//else if(a[3]){
                     // ok..
                    // }//else ok
                    // if(a[2] != 0){
                    
                    // }
                    //END TODO
                    //make all zero is possible?
                    if(5*b[5] + 4*b[4] + 3*b[3] + 2*b[2] + b[1] >= 5*a[5] + 4*a[4] + 3*a[3] + 2*a[2] + a[1]);
                    else ok =false;
                }else ok = false;
            }else ok = false;
        }

        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }
}   
