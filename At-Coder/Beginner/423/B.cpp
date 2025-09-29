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
    int n;
    cin >> n;
    vector<bool> lck(n+1);
    int cl = 0;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        lck[i] = x == 1;
        if(lck[i]) cl++;
    }
    if(cl <= 1) cout << "0\n";
    else{
        int mx = 0, mn = n;
        for(int i=1;i<=n;i++){
            if(lck[i]){
                mx = i-1;
                break;
            }
        }
        for(int i=n;i>=1;i--){
            if(lck[i]){
                mn = i;
                break;
            }
        }
        cout << mn - mx - 1 << "\n";
    }

}
