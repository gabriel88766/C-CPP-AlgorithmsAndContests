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
    int n;
    set<int> s;
    cin >> n;
    for(int i=1;i<=n;i++){
        s.insert(i);
    }
    auto it = s.begin();
    for(int i=0;i<n;i++){
        if(++it == s.end()) it = s.begin();
        int value = *it;
        if(++it == s.end()) it = s.begin();
        cout << value << " ";
        s.erase(value);
    }
}
