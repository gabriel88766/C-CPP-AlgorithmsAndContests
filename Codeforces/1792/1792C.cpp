#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n, ans;
        cin >> n;
        ans = n/2;
        vector<int> ord(n+1);
        for(int i=0;i<n;i++){
            int aux;
            cin >> aux;
            ord[aux] = i;
        }
        if(n == 1){
            cout << "0\n";
            continue;
        }else if(n == 2){
            cout << (ord[2] > ord[1] ? 0 : 1) << "\n";
            continue;
        }
        int l, r;
        if(n % 2){
            l = n/2;
            r = l + 2;
            if(ord[l] < ord[l+1] && ord[l+1] < ord[r]){ans--;}//ok;
            else{
                cout << ans << "\n";
                continue;
            }
        }else{
            l = n/2;
            r = n/2 + 1;
            if(ord[l] < ord[r]){ans--;}
            else{
                cout << ans << "\n";
                continue;
            }
        }
        while(ans){
            if(ord[l-1] < ord[l] && ord[r] < ord[r+1]){
                l--, r++, ans--;
            }else{
                break;
            }
        }
        cout << ans << "\n";
    }
}
