#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n;
    cin >> n;
    int nums[] = {123456, 1234567};
    for(int i=0;i<= n/nums[0];i++){
        for(int j=0;j<= (n - nums[0]*i)/nums[1]; j++){
            int cur = n - i*nums[0] - j * nums[1];
            if(!(cur % 1234)){
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
}
