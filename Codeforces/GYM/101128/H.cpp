#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

void solve(ull a, set<ull> &s){
    if(a == -1) return;
    ull  in = 0, potj =0, poti = 1;
    for(int i=1;i<=63;i++){
        if(i == 1) {poti = 2; in = 1;}
        else{
            in = 2*in + 1;
            poti <<= 1;
        }
        for(int j=1;j<=62;j++){
            if(j == 1) potj = 2;
            else potj <<= 1;
            ull cur;
            for(int k=1;k<=63;k++){
                if(i == 63 && k > 1) break;
                if(k == 1) {cur = in;}
                else if(k % 2){
                    double d = cur * poti + in;
                    d = a/d;
                    if(d+EPS < 1) break;
                    cur = cur * poti + in;
                } 
                else {
                    double d = cur * potj;
                    d = ((double)a)/d;
                    if(d +EPS < 1) break;
                    cur = cur * potj;
                }
                if(cur <= a) s.insert(cur);
                else break;
            }
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ull x, y;
    cin >> x >> y;
    set<ull> s1, s2;
    solve(x-1, s2);
    solve(y, s1);
    cout << s1.size() - s2.size();
}
