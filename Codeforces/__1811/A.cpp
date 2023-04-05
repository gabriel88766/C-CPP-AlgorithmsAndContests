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
        string d;
        cin >> n >> d;
        string s;
        cin >> s;
        int pos = -1;
        for(int i=0;i<n;i++){
            if(s[i] < d[0]){
                pos = i;
                break;
            }
        }
        string ans;
        if(pos == -1) ans = s+d;
        else{
            for(int i=0;i<pos;i++) ans += s[i];
            ans += d;
            for(int i=pos;i<n;i++) ans += s[i];
        }
        cout << ans << "\n";
    }
}   
