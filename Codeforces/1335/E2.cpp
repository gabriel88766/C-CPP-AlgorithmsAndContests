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
        vector<int> num(n+1);
        vector<vector<int>> v(201);
        vector<int> cnt(201);
        for(int i=1;i<=n;i++){
            cin >> num[i];
            v[num[i]].push_back(i);
            cnt[num[i]]++;
        }
        int ans = 1;
        for(int i=1;i<=200;i++){
            if(v[i].size() >= 2){
                auto cnt2 = cnt;
                int p1 = 0;
                int p2 = v[i].size() - 1;
                for(int j=1;j<=v[i][p1];j++) cnt2[num[j]]--;
                for(int j=v[i][p2];j<=n;j++) cnt2[num[j]]--;
                while(p2 > p1){
                    int qt = 2*(p1+1);
                    for(int j=1;j<=200;j++){
                        ans = max(ans, qt + cnt2[j]);   
                    }
                    for(int j=v[i][p1]+1;j<=v[i][p1+1];j++) cnt2[num[j]]--;                    
                    for(int j=v[i][p2-1];j<v[i][p2];j++) cnt2[num[j]]--;
                    p2--;
                    p1++;
                    
                }
            }
        }
        cout << ans << "\n";
    }
}
