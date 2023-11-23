#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

void doop(vector<int> &v, int ind){
    int x = v[ind];
    v[ind] = v[ind+2];
    v[ind+2] = v[ind+1];
    v[ind+1] = x;
}

int n;

void sortp(vector<int> &ans, vector<int> &v){
    for(int i=0;i<n-2;i++){
        //cerr << i << " ";
        auto it = min_element(v.begin() + i, v.end());
        while(it != v.begin() + i){
            int ind = it - v.begin();
            if(ind == i + 1){
                ans.push_back(ind);
                ans.push_back(ind);
                doop(v, ind-1);
                doop(v, ind-1);
            }else{
                ans.push_back(ind-1);
                doop(v, ind-2);
            }
            it = min_element(v.begin() + i, v.end());
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> v(n), ans;
        for(int i=0;i<n;i++) cin >> v[i];
        sortp(ans, v);
        if(v[n-2] > v[n-1] && v[n-1] == v[n-3]){
            ans.push_back(n-2);
            doop(v, n-3);
        }
        auto x = v;
        sort(x.begin(), x.end());
        if(x == v){
            cout << ans.size() << "\n";
            for(auto x : ans) cout << x << " ";
            cout << "\n";
        }else{
            int ind = -1;
            for(int i=0;i<n;i++){
                if(v[i] == v[i+1]) ind = i;
            }
            if(ind == -1) cout << "-1\n";
            else{
                ans.push_back(ind+1);
                ans.push_back(ind+1);
                doop(v, ind);
                doop(v, ind);
                sortp(ans, v);
                cout << ans.size() << "\n";
                for(auto x : ans) cout << x << " ";
                cout << "\n";
            }
        }

    }
}
