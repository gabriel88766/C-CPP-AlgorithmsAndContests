#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N =2e5+3;
map<int,int> mp;
int cnt[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, cn=0;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        if(!mp[aux]){
            mp[aux] = ++cn;
            v.push_back(aux);
        }
        cnt[mp[aux]]++;
    }
    vector<int> vs;
    for(int i=1;i<=cn;i++) vs.push_back(cnt[i]);
    sort(vs.begin(),vs.end());
    int ans = 0;
    for(int i=0;i<vs.size();i++){
        int cur = 0;
        if(i != (vs.size()-1)){
            for(int j=1;j<=vs[i];j++){ //O(N)
                int curv = j;
                cur = curv;
                int last=-1;
                map<int,int> used;
                while(true){
                    curv *= 2;
                    if(curv > vs[vs.size()-1]){
                        break;
                    }
                    if((last+1) == vs.size()) break;
                    auto it = lower_bound(vs.begin()+last+1, vs.end(), curv);
                    if((it - vs.begin()) == i) ++it;
                    last = it-vs.begin();
                    cur += curv;
                }
                ans = max(cur, ans);
            }
        }else ans = max(ans, vs[i]);
    }
    cout << ans;

}
