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
        string s;
        cin >> n >> k >> s;
        s = " " + s;
        vector<int> su(n+2, 0);
        vector<int> v;
        for(int i=n;i>=2;i--){
            su[i] = su[i+1] + (s[i] == '1' ? 1 : -1);
            v.push_back(su[i]);
        }
        sort(v.begin(), v.end(), greater<int>());
        ll sum = 0;
        int ans = -1, cur = 0;
        for(auto x : v){
            sum += x;
            cur++;
            if(sum >= k){
                ans = cur+1;
                break;
            }
        }
        cout << ans << "\n";
    }
}
