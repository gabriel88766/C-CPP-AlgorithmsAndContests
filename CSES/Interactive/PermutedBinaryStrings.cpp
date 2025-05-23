#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1005;
int ans[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=0;i<10;i++){
        cout << "? ";
        for(int j=1;j<=n;j++){
            if(j & (1 << i)) cout << "1";
            else cout << "0";
        }
        cout << "\n";
        cout.flush();
        string s;
        cin >> s;
        for(int j=0;j<n;j++){
            ans[j+1] += (s[j] == '1' ? 1 << i : 0);
        }
    }
    cout << "! ";
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
    cout << "\n";
    cout.flush();
}
