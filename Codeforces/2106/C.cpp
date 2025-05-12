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
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i];
        int sum = -1;
        bool ok = true;
        for(int i=0;i<n;i++){
            if(b[i] != -1){
                if(sum == -1) sum = a[i] + b[i];
                else if(sum != (a[i] + b[i])){
                    ok = false;
                    break;
                }
            }
        }
        if(!ok) cout << "0\n";
        else if(sum != -1){
            if(sum < *max_element(a.begin(), a.end()) || sum > *min_element(a.begin(), a.end()) + k) cout << "0\n";
            else cout << "1\n";
        } 
        else{
            int mx = *max_element(a.begin(), a.end());
            int mn = *min_element(a.begin(), a.end());
            cout << k + 1 + mn - mx << "\n";
        }
    }
}
