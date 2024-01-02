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
        int c0 = 0, c1 = 0, c2 = 0;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            if(x % 3 == 0) c0++;
            else if(x % 3 == 1) c1++;
            else c2++;
        }
        int d3 = n/3;
        if(c0 == d3 && c1 == d3 && c2 == d3) cout << "0\n";
        else{
            int cnt = 0;
            if(c0 >= d3) cnt++;
            if(c1 >= d3) cnt++;
            if(c2 >= d3) cnt++;
            if(cnt == 2){
                if(c0 < d3){
                    cout << c2-d3 + 2*(c1-d3) << "\n";
                }else if(c1 < d3){
                    cout << c0-d3 + 2*(c2-d3) << "\n";
                }else{
                    cout << c1-d3 + 2*(c0-d3) << "\n";
                }
            }else{
                if(c0 > d3){
                    cout << d3-c1 + 2*(d3-c2) << "\n";
                }else if(c1 > d3){
                    cout << d3-c2 + 2*(d3 - c0) << "\n";
                }else{
                    cout << d3-c0 + 2*(d3 - c1) << "\n";
                }
            }
        }
    }
}
