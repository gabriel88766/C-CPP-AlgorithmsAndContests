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
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        int b = 0;
        while(b < (n-1)){
            int c = 0, minv = INF_INT;
            for(int i=b;i<n;i++){
                if(v[i] < minv){
                    minv = v[i];
                    c = i;
                }
            }
            if(c == b){
                b++;
                continue;
            }
            for(int i=c;i>=b+1;i--){
                swap(v[i], v[i-1]);
            }
            b = c;
        }
        for(int i=0;i<n;i++) cout << v[i] << " ";
        cout << "\n";
    }
}
