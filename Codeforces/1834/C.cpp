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
        string s,t;
        cin >> n >> s >> t;
        int A1 = 0, A2 = 0;
        for(int i=0;i<n;i++) if(s[i] != t[i]) A1++;
        reverse(s.begin(), s.end());
        for(int i=0;i<n;i++) if(s[i] != t[i]) A2++;
        reverse(s.begin(), s.end());
        int min1 = A1 % 2 ? 2*A1-1 : 2*A1;
        int min2 = A2 % 2 ? 2*A2 : 2*A2-1;
        if(!A2) min2 = 2;
        if(s != t) cout << min(min1,min2) << "\n";  
        else cout << "0\n";
    }
}
