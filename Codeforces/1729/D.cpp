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
        vector<int> v1(n), v2(n), diff(n);
        for(int i=0;i<n;i++) cin >> v1[i];
        for(int i=0;i<n;i++) cin >> v2[i];
        for(int i=0;i<n;i++) diff[i] = v2[i]-v1[i];
        sort(diff.begin(), diff.end());
        int p1 = 0, p2 = n-1;
        int ans = 0;
        while(diff[p1] < 0 && p1 < n){
            if(diff[p2] < abs(diff[p1])) p1++;
            else{ p1++; p2--; ans++;}
        }
        cout << ans + (p2-p1+1)/2 << "\n";
    }
}
