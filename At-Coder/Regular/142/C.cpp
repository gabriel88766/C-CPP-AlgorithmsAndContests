#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int ask(int a, int b){
    cout << "? " << a << " " << b << "\n";
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}

void ans(int x){
    cout << "! " << x << "\n";
    cout.flush();
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> v1, v2;
    for(int i=3;i<=n;i++){
        int x = ask(1, i);
        if(x == 1) v1.push_back(i);
        if(x == 2) v2.push_back(i);
    }
    if(v1.size() == 0) ans(1);
    else{
        int mn = INF_INT, mx = 0;
        for(auto x : v1){
            int a = ask(x, 2);
            mx = max(mx, a);
            mn = min(mn, a);
        }
        if(mx == mn && mn == 2){
            if(v1.size() > 1) ans(1);
            else{
                //maybe ans = 1 or maybe ans = 3
                if(v2.size() == 0) ans(1);
                else{
                    int x1 = ask(v1[0], v2[0]);
                    int x2 = ask(2, v2[0]);
                    if(x1 == x2) ans(3);
                    else ans(1);
                }
            }
        }else ans(mn + 1);
    }
}
