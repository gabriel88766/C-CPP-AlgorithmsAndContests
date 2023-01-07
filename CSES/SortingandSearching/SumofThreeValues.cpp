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
    int n, x;
    cin >> n >> x;
    map<int, int> mp;
    pair<pair<int,int>, int> ans = {{-1,-1}, -1}; //index,index, num
    vector<int> v;
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        v.push_back(aux);
        mp[aux]++;
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int cursum = v[i] + v[j];
            int rem = x - cursum;
            if(mp.count(rem) != 0){
                int cnt = mp[rem];
                if(rem == v[i]) cnt--;
                if(rem == v[j]) cnt--;
                if(cnt != 0){ // hit
                    ans = {{i, j}, rem};
                    goto outloop;
                }
            }
        }
    }
outloop:

    if(ans == make_pair(make_pair(-1, -1), -1)) cout << "IMPOSSIBLE";
    else{
        for(int i=0;i<n;i++){
            if(v[i] == ans.second && i != ans.first.first && i != ans.first.second){
                ans.second = i;
                break;
            }
        }
        cout << ans.first.first+1 << " " << ans.first.second+1 << " " << ans.second+1;
    }
}
