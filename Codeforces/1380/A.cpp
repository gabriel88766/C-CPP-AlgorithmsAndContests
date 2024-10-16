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
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        int il = -1, ir = -1, ij = -1;
       
        for(int j=2;j<n;j++){
            il = -1, ir = -1;
            for(int i=1;i<j;i++){
                if(v[i] < v[j]) il = i;
            }
            for(int i=j+1;i<=n;i++){
                if(v[j] > v[i]) ir = i;
            }
            if(il != -1 && ir != -1){
                ij = j;
                break;
            }
        }
        if(ij != -1){
            cout << "YES\n" << il << " " << ij << " " << ir << "\n";
        }else{
            cout << "NO\n";
        }
    }
}
