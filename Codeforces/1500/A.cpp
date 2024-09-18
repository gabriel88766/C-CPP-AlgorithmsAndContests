#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5e6+3;
pair<int,int> s[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int sum = v[i] + v[j];
            if(s[sum] != make_pair(0, 0) && s[sum].first != i && s[sum].first != j && s[sum].second != i && s[sum].second != j){
                cout << "YES\n";
                cout << i << " " << j << " " << s[sum].first << " " << s[sum].second << "\n";
                return 0;
            }else s[sum] = {i, j};
        }
    }
    cout << "NO\n";

}
