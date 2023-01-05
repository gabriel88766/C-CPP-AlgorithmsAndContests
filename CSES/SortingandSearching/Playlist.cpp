#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, count = 0, ans = 0, bp=0;
    cin >> n;
    vector<int> v(n);
    set<int> playlist;
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    for(int i=0;i<n;i++){
        if(playlist.count(v[i])){
            playlist.erase(v[bp++]);
            count--;
            i--;
        }else{
            playlist.insert(v[i]);
            count++;
            ans = max(ans, count);
        }
    }
    cout << ans;
}
