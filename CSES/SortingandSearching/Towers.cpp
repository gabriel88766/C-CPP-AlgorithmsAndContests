#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin); 
    int n, ans = 0;
    set<int> tops;
    map<int,int> topsqnt;
    cin >> n;
    while(n--){
        int aux;
        cin >> aux;
        auto it = tops.upper_bound(aux);
        if(it == tops.end()){
            tops.insert(aux);
            ans++;
            topsqnt[aux]++;
        }else{
            topsqnt[*it]--;
            tops.insert(aux);
            topsqnt[aux]++;
            if(!topsqnt[*it]) tops.erase(*it);
        }
    }
    cout << ans;
}
