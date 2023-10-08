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
        vector<ll> cnt(n+1, 0);
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            cnt[x]++;
        }
        int cntl = 0;
        bool flag = false;
        set<pair<int,int>> sp;
        ll sum = 0;
        for(int i=0;i<=n;i++){
            if(flag){
                cout << "-1 ";
                continue;
            }
            if(cntl >= i){
                //my login goes here
                cout << cnt[i] + sum << " ";
                if(cnt[i]){
                    if(cnt[i] > 1){
                        sp.insert({i, cnt[i]-1});
                    }
                }else{
                    if(sp.size() == 0){
                        continue;
                    }
                    auto x = *prev(sp.end());
                    sp.erase(x);
                    x.second--;
                    sum += i - x.first;
                    if(x.second) sp.insert(x);
                }

            }else{
                flag = true;
                cout << "-1 ";
            }
            cntl += cnt[i];
        }
        cout << "\n";
    }
}   
