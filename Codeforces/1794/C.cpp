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
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        for(int i=0;i<n;i++){
            if(i == 0) cout << "1 ";
            else{
                int lo = 0, hi = i;
                while(lo != hi){
                    int mid = (lo+hi)/2;
                    int d = (i-mid+1);
                    if(v[mid] < d) lo = mid+1;
                    else hi = mid;
                }
                cout << i-lo+1 << " ";
            }
        }
        cout << "\n";
    }
}
