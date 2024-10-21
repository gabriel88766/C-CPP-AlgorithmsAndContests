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
    freopen("in.txt", "r", stdin); //test input
    freopen("out.txt", "w", stdout); //test input
    vector<ll> nums;
    for(int i=1;i<=9;i++){
        for(int j=i;j<=9;j++){
            string cur = "";
            for(int k=i;k<=j;k++) cur += (char)('0' + k);
            for(int k=j-1;k>=i;k--) cur += (char)('0' + k);
            nums.push_back(stol(cur));
        }
    }
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        ll A, B, M;
        cin >> A >> B >> M;
        int ans = 0;
        for(auto x : nums){
            if(x >= A && x <= B){
                if(!(x % M)) ans++;
            }
        }
        cout << "Case #" << i << ": " << ans << "\n";
    }
}
