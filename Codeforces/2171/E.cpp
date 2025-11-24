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
    vector<int> seq0 = {2, 1, 4, 6, 5, 3};
    vector<int> seq1 = {3, 1, 6, 2, 5, 4};
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=0;;i++){
            int x = 6*i;
            if(x > n) break;
            if(i % 2){
                for(auto y : seq1){
                    if(x + y <= n) cout << x + y << " ";
                }
            }else{
                for(auto y : seq0){
                    if(x + y <= n) cout << x + y << " ";
                }
            }
        }
        cout << "\n";
    }
}
