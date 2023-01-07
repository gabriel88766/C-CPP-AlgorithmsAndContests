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
    int ans[4];
    set<pair<int, pair<int, int>>> st; //all sums of 2 nums
    int n, x;
    cin >> n >> x;
    vector<int> vnum;
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        vnum.push_back(aux);
    }
    for(int i=0;i<n;i++){
        for(int j=(i+1); j<n;j++){
            int sum = vnum[i] + vnum[j];
            int rem = x - sum;
            auto it = st.lower_bound({rem, {0, 0}});
            if(it != st.end() && it->first == rem && it->second.first != i){
                while(it != st.end() && (it->second.first == i || it->second.second == i || it->second.first == j || it->second.second == j)) it++;
                if(it != st.end() && it->first == rem){
                    ans[0] = it->second.first;
                    ans[1] = it->second.second;
                    ans[2]= i;
                    ans[3] = j;
                    cout << ans[0]+1 << " " << ans[1]+1 << " " << ans[2]+1 << " " << ans[3]+1;
                    return 0;
                }
            }
            st.insert({sum, {i, j}});
        }
    }
    cout << "IMPOSSIBLE";
}
