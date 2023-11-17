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
        int a, b, c;
        cin >> a >> b >> c;
        int minv = INF_INT;
        tuple<int,int,int> ans;
        for(int i=1;i<=2*c;i++){
            int cla, mincla = INF_INT;
            for(int j=1;j*j<=i;j++){
                if(!(i % j)){
                    int cur = abs(a - j);
                    if(cur < mincla){
                        mincla = cur;
                        cla = j;
                    }
                    cur = abs(a - i/j);
                    if(cur < mincla){
                        mincla = cur;
                        cla = i/j;
                    }
                }
            }
            int clc1 = (c/i) * i;
            int clc2 = clc1 + i;
            int clc;
            if(abs(clc1 - c) < abs(clc2 - c)) clc = clc1;
            else clc = clc2;
            int tt = abs(clc - c) + abs(i - b) + abs(cla - a);
            if(tt < minv){
                minv = tt;
                ans = {cla, i, clc};
            } 
        }   
        auto [aa, ab, ac] = ans;
        cout << minv << "\n";
        cout << aa << " " << ab << " " << ac << "\n";
    }
}
