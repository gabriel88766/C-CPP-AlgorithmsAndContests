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
        int n;
        cin >> n;
        vector<int> a1, a2;;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            if(x % 2) a1.push_back(x);
            else a2.push_back(x);
        }
        sort(a1.begin(), a1.end());
        sort(a2.begin(), a2.end());
        if(a1.size() == 0 || a2.size() == 0){
            cout << 0 << "\n";
            continue;
        }
        int c1 = 0, c2 = 0;
        for(auto &x : a1){
            if(x < a2[0] || x > a2.back()) c1++;
        }
        for(auto &x : a2){
            if(x < a1[0] || x > a1.back()) c2++;
        }
        cout << min(c1, c2) << "\n";

    }
}   
