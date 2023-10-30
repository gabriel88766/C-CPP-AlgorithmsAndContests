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
        int n, c0, c1, h;
        string s;
        cin >> n >> c0 >> c1 >> h >> s;
        int cnt0 = 0, cnt1 = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '0') cnt0++;
            else cnt1++;
        }
        int f = 0;
        if(h < max(c0,c1)-min(c0,c1)){
            if(c0 > c1){
                cnt1 += cnt0;
                f += h*cnt0;
                cnt0 = 0;
            }else{
                cnt0 += cnt1;
                f += h*cnt1;
                cnt1 = 0;
            }
        }
        cout << c0*cnt0+c1*cnt1+f << "\n";
        
    }
}
