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
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int qt1 = 0;
        int best;
        for(int i=0;i<n;i++) if(s[i] == '1') qt1++;
        best = qt1;
        for(int i=0;i<k;i++){
            vector<int> ps;
            int cur = 0;
            for(int j=i; j<n;j += k){
                if(s[j] == '1') cur++;
                else cur--;
                ps.emplace_back(cur);
            }
            int curmin = 0, bs = 0;
            for(int j=0;j<ps.size();j++){
                if(ps[j] < curmin) curmin = ps[j];
                bs = max(bs, ps[j] - curmin);
            }
            best = min(best, qt1-bs);
        }
        cout << best << "\n";
    }
}
