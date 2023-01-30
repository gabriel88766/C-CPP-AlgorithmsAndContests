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
    int t;
    cin >> t;
    while(t--){
        int n, s, r;
        cin >> n >> s >> r;
        int last = s-r;
        vector<int> ans(n-1, 1);
        ans.push_back(last);
        int sum = n-1 + last;
        while(sum < s){
            int i = n-2;
            while(sum < s && i >= 0){
                ans[i--]++;
                sum++;
            }
        }
        for(int i=0;i<ans.size();i++) cout << ans[i] << " ";
        cout << "\n";   
    }
}
