
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
    int array1[] = {1, 3, 6, 10, 15, 21, 28, 36};
    int array2[] = {2, 3, 4, 5, 6, 7, 8, 9};
    while(t--){
        int n, k;
        cin >> k >> n;
        int maxc = 1;
        int diff = n-k;
        for(int i=0;i<8;i++){
            if(diff >= array1[i]) maxc++;
            else break;
        }
        vector<int> ans;
        int cur = 2;
        ans.push_back(1);
        ans.push_back(2);
        int cnt = 2;
        while(cnt < k && cnt <= maxc){
            cur += array2[cnt-2];
            cnt++;
            ans.push_back(cur);
        }
        while(cnt < k){
            cur += 1;
            cnt++;
            ans.push_back(cur);
        }
        for(auto v : ans) cout << v << " ";
        cout << "\n";
    }
}
