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
        sort(v.begin(), v.end());
        vector<int> ans;
        ans.push_back(v[(n-1)/2]);
        int p1 = (n-1)/2, p2 = (n-1)/2;
        for(int i=n-1;i>=1;i--){
            if(i%2){
                p2++;
                ans.push_back(__gcd(ans.back(), v[p2]));
            }else{
                p1--;
                ans.push_back(__gcd(ans.back(), v[p1]));
            }
        }
        reverse(ans.begin(), ans.end());
        for(auto x : ans) cout << x << " ";
        cout << "\n";
    }
}
