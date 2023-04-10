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
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        sort(v.begin(), v.end());
        int maxmex = 0, cnt = 0;
        for(int i=0;i<n;i++){
            bool brk = false;
            if(v[i] == maxmex){
                maxmex++;
            }else{
                if(v[i] > maxmex){
                    while(v[i] > maxmex){
                        if(cnt < k){
                            cnt++;
                            maxmex++;
                        }else{
                            brk = true;
                            break;
                        }
                    }
                    if(brk) break;
                    else i--;
                }
            }
        }
        multiset<int> ms;
        int lst = 0;
        cnt = 0;
        for(auto it = lower_bound(v.begin(), v.end(), maxmex); it!= v.end(); ++it){
            if(*it == lst) cnt++;
            else{
                if(cnt > 0) ms.insert(cnt);
                lst = *it;
                cnt = 1;
            }
        }
        ms.insert(cnt);
        cnt = 0;
        while(!ms.empty() && cnt + *ms.begin() <= k){
            cnt += *ms.begin();
            ms.erase(ms.begin());
        }
        
        cout << ms.size() << "\n";

        
    }
}
