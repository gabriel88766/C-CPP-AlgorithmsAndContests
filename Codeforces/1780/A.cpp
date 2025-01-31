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
        //odd sum
        //3 odds or 1 odd and 2 even
        int n;
        cin >> n;
        vector<int> odd, even;
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            if(x % 2) odd.push_back(i);
            else even.push_back(i);
        }
        if(odd.size() >= 3){
            cout << "YES\n";
            cout << odd[0] << " " << odd[1] << " " << odd[2] << "\n";
        }else if(odd.size() >= 1 && even.size() >= 2){
            cout << "YES\n";
            cout << odd[0] << " " << even[0] << " " << even[1] << "\n";
        }else cout << "NO\n";
    }
}
