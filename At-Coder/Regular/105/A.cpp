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
    int num[4], sum = 0;
    for(int i=0;i<4;i++) {
        cin >> num[i];
        sum += num[i];
    }
    if((sum%2)){
        cout << "No";
        return 0;
    }
    for(int i=1;i<16;i++){
        int cur = 0;
        for(int j=0;j<4;j++){
            if(i & (1 << j)) cur += num[j];
        }
        if(cur == sum/2){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}
