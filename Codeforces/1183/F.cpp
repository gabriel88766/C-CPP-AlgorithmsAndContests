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
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        sort(v.begin(), v.end(), greater<int>());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        n = v.size();
        int ans = v[0];

        //why it works?
        //if v[1] and v[2] are greater than v[0]/2, then it will be basically O(1)

        //if v[1] is greater than v[0]/2, then either v[0] or v[1] or both will be definitely chose
        //3 cases, if both, then O(n), if v[0] or v[1], then it will be the complexity of subproblem: chose 2
        //this subproblem worst case compl. should be O( (n/2)^2) which is TLE
        //however

        //last case, v[1] is lower or equal v[0]/2.
        //3 divisors sum up to 31/30 * v[0], only 1 possibility
        //if there are numbers which are not divisor of v[0] chose, then these numbers
        //are better with v[0]
        //this case is definitely fast

        for(int i=0;i<n;i++){ //n^3 ?? guess not
            if(3*v[i] <= ans) break;
            for(int j=i+1;j<n;j++){
                if(v[i] + 2*v[j] <= ans) break;
                if(!(v[i] % v[j])) continue;
                if(v[i] % v[j] && v[i] + v[j] > ans){
                    ans = v[i] + v[j];
                }
                for(int k=j+1;k<n;k++){
                    if(v[i] + v[j] + v[k] <= ans) break;
                    if(v[i] % v[j] && v[i] % v[k] && v[j] % v[k]){
                        ans = v[i] + v[j] + v[k];
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}
 