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
    int n, k;
    cin >> n >> k;
    set<int> nums;
    queue<int> q;
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        if(!nums.count(aux)){
            if(q.size() == k){
                 nums.erase(q.front()); 
                 q.pop();
            }
            q.push(aux);
            nums.insert(aux);
        }
    }
    vector<int> ans;
    while(!q.empty()) {ans.push_back(q.front()); q.pop();}
    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(auto x: ans) cout << x << " ";
}
