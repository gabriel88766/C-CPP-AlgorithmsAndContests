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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        auto allv = v;
        allv.push_back(0); //no penalty at all
        sort(allv.begin(), allv.end());
        allv.resize(unique(allv.begin(), allv.end()) - allv.begin());
        int lo = 0, hi = allv.size() - 1;
        while(lo != hi){
            int mid = lo + (hi - lo)/2;
            int rv = allv[mid]; //?
            bool lb = false;
            int cs = 0;
            for(int i=0;i<n;i++){
                if(v[i] > rv){
                    //must be the right color.
                    if(s[i] == 'R') lb = false;
                    else{
                        if(lb == false){
                            lb = true;
                            cs++;
                        }
                    }
                }
            }
            if(cs <= k) hi = mid;
            else lo = mid + 1;
        }
        cout << allv[lo] << "\n";
    } 
}
