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
    // vector<int> v;
    // for(int i=1;i<=30000;i++){
    //     if(i % 2 == 0 || i % 3 == 0) v.push_back(i);
    // }
    // int sum = 0;
    // for(auto x : v) sum += x;
    int n;
    cin >> n;
    if(n == 3){
        cout << "2 5 63\n";
    }else{
        //remove many, except 2, 4;
        vector<int> ans = {2, 4, 3, 9};
        int xx = 15;
        while(ans.size() + 2 <= n && xx <= 30000){
            ans.push_back(xx);
            ans.push_back(xx + 6);
            assert(xx  + 6 <= 30000);
            xx += 12;
        }
        xx = 8;
        while(ans.size() + 2 <= n && xx <= 30000){
            ans.push_back(xx);
            ans.push_back(xx + 2);
            xx += 6;
        }
        xx = 6;
        while(ans.size() + 1 <= n && xx <= 30000){
            ans.push_back(xx);
            xx += 6;
        }
        for(auto x : ans) cout << x << " ";
        cout << "\n";
    }
}
