#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int query(int a, int b){
    cout << "? " << a << " " << b << "\n";
    cout.flush();
    int ans;
    cin >> ans;
    if(ans == a*b) return 0; // b < x
    else if(ans == a*(b+1)) return 1; //a < x <= b
    else return 2; // x <= a 
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int lo = 2, hi = 999;
        while(lo != hi){
            int m, m1, m2;
            if(hi == lo + 1){
                m1 = lo, m2 = lo+1;
                int ans = query(m1, m2);
                if(ans == 2) hi = lo;
                else if(ans == 1) lo = hi;
                else assert(1 == 0);
            }else{
                m = (hi - lo + 1)/3;
                m1 = lo + m;
                m2 = lo + 2*m;
                int ans = query(m1, m2);
                if(ans == 2) hi = m1;
                else if(ans == 1) lo = m1 + 1, hi = m2;
                else lo = m2+1;
            }
        }
        cout << "! " << lo << "\n";
    }
}
