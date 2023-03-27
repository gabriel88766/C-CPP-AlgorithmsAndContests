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
        ll n, k;
        cin >> n >> k;
        ll qt1 = k-3;
        n -= qt1;
        vector<int> ans;
        if(n % 2){
            ans.push_back(n/2);
            ans.push_back(n/2);
            ans.push_back(1);
        }else{
            if(n % 4 == 2){
                ans.push_back((n-2)/2);
                ans.push_back((n-2)/2);
                ans.push_back(2);
            }else{
                ans.push_back((n/4)*2);
                ans.push_back(n/4);
                ans.push_back(n/4);
            }
        }
        for(int i=0;i<qt1;i++) ans.push_back(1);
        for(auto x : ans) cout << x << " ";
        cout << "\n";
    }
}
