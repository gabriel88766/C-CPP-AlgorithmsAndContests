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
    //freopen("in", "r", stdin); test input
    int n, q;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin >> nums[i];
    cin >> q;
    for(int i=0;i<q;i++){
        int a,b;
        cin >> a >> b;
        int sum = 0;
        for(int i=0;i<n;i++){
            if(a == (i+1)) sum += b;
            else sum += nums[i];
        }
        cout << sum << "\n";
    }
}
