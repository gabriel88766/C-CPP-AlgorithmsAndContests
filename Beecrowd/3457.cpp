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
    int n;
    cin >> n;
    vector<int> v(n), d(n);
    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=0;i<n;i++) cin >> d[i];
    sort(v.begin(), v.end());
    sort(d.begin(), d.end(), greater<int>());
    bool ok1 = true, ok2 = true;
    int pos1 = v[0] + d[0];
    int pos2 = v[v.size()-1] - d[0];
    multiset<int> s1 = multiset(d.begin(), d.end());
    multiset<int> s2 = multiset(d.begin(), d.end());
    if(pos1 <= 1000000000){
        for(int i=0;i<n;i++){
            auto it = s1.lower_bound(abs(pos1-v[i]));
            if(it != s1.end() && *it == abs(pos1-v[i])){
                s1.erase(it);
            }else{
                ok1 = false;
                break;
            }
        }
    }else ok1 = false;
    if(pos2 < 1) ok2 = false;
    else{
        for(int i=0;i<n;i++){
            auto it = s2.lower_bound(abs(pos2-v[i]));
            if(it != s2.end() && *it == abs(pos2-v[i])){
                s2.erase(it);
            }else{
                ok2 = false;
                break;
            }
        }
    }
    if(ok1 && !ok2) cout << pos1 << "\n";
    else if(!ok1 && ok2) cout << pos2 << "\n";
    else{
        if(pos1 < pos2) cout << pos1 << "\n" << pos2 << "\n";
        else if(pos1 > pos2) cout << pos2 << "\n" << pos1 << "\n";
        else cout << pos1 << "\n";
    }

}
