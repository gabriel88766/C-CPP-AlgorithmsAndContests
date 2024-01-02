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
        vector<int> p(n+1);
        for(int i=1;i<=n;i++) cin >> p[i];
        set<int> s1, s2;
        for(int i=1;i<=n;i++) s1.insert(i), s2.insert(i);
        vector<int> ans1(n+1), ans2(n+1);
        for(int i=1;i<=n;i++){
            if(s1.count(p[i])){
                ans1[i] = ans2[i] = p[i];
                s1.erase(ans1[i]);
                s2.erase(ans2[i]);
            }else{
                ans1[i] = *s1.begin();
                ans2[i] = *prev(s2.lower_bound(p[i]));
                s1.erase(ans1[i]);
                s2.erase(ans2[i]);
            }
        }
        for(int i=1;i<=n;i++) cout << ans1[i] << " ";
        cout << "\n";
        for(int i=1;i<=n;i++) cout << ans2[i] << " ";
        cout << "\n";
    }
}
