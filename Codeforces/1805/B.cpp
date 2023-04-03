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
        string s;
        cin >> n >> s;
        char minc = 'z'+1;
        int ind;
        for(int i=n-1;i>=0;i--){
            if(s[i] < minc){
                minc = s[i];
                ind = i;
            }
        }
        string ans;
        ans += s[ind];
        for(int i=0;i<n;i++){
            if(i != ind) ans += s[i];
        }
        cout << ans << "\n";

    }
}
