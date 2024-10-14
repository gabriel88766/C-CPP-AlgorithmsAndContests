#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int query(int a, int b){
    cout << "? " << a << " " << b << "\n";
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}
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
        for(int i=1;i<=n;i+=2){
            int j = (i == n ? i-1 : i+1);
            int q1 = query(i, j);
            int q2 = query(j, i);
            if(q1 != q2){
                //impostor found
                int k = (i == 1 ? 3 : 1); //not impostor;
                int q3, q4;
                q3 = query(i, k);
                q4 = query(k, i);
                if(q3 == q4){
                    cout << "! " << j << "\n";
                    cout.flush();
                }else{
                    cout << "! " << i << "\n";
                    cout.flush();
                }
                break;
            }
        }
    }
}
