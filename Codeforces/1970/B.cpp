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
    vector<pair<int,int>> vp;
    vector<int> ans(n+1);
    vector<pair<int,int>> po(n+1);
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        vp.push_back({x, i});
    }
    auto complete = [&](int beg){
        for(int i=beg;i<n;i++){
            if(vp[i].first == 0){
                po[vp[i].second] = {i+1, 1};
                ans[vp[i].second] = vp[i].second;
            }else if(vp[i].first <= i){
                po[vp[i].second] = {i+1, po[vp[i-vp[i].first].second].second};
                ans[vp[i].second] = vp[i - vp[i].first].second;
            }else{
                po[vp[i].second] = {i+1, vp[i].first - i + 1};
                ans[vp[i].second] = vp[0].second;
            }
        }
    };
    sort(vp.begin(), vp.end());
    if(vp[0].first == 0){
        //then 1 -> 1
        ans[vp[0].second] = vp[0].second;
        po[vp[0].second] = {1, 1};
        complete(1);
    }else{
        int ind = -1;
        for(int i=1;i<n;i++){
            if(vp[i].first == vp[i-1].first){
                ind = i-1;
                break;
            }
        }
        if(ind != -1){
            //then make ind - 1 and ind == 0, 1
            if(ind != 0){
                swap(vp[0], vp[ind]);
                swap(vp[1], vp[ind+1]);
            }
            ans[vp[0].second] = vp[1].second;
            ans[vp[1].second] = vp[0].second;
            po[vp[0].second] = {1, 1};
            po[vp[1].second] = {2, vp[0].first};
            complete(2);
        }else{
            if(n == 2){
                cout << "NO\n";
                return 0;
            }else{
                ans[vp[0].second] = vp[1].second;
                ans[vp[1].second] = vp[2].second;
                ans[vp[2].second] = vp[0].second;
                po[vp[0].second] = {1, 1};
                po[vp[1].second] = {2, 1};
                po[vp[2].second] = {3, 2};
                complete(3);
            }
        }
    }
    cout << "YES\n";
    for(int i=1;i<=n;i++){
        cout << po[i].first << " " << po[i].second << "\n";
    }
    for(int i=1;i<=n;i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
}
