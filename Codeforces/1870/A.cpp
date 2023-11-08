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
        int n, k, x;
        cin >> n >> k >> x;
        if(n >= k && x>=(k-1)){
            int sum = 0;
            for(int i=0;i<k;i++) sum += i;
            if(x != k) for(int i=0;i<n-k;i++) sum += x;
            else for(int i=0;i<n-k;i++) sum += (x-1);
            cout << sum << "\n";
        }else cout << "-1\n";
    }
}       
