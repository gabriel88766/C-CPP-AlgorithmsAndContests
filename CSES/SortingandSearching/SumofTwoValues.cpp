#include <bits/stdc++.h>
typedef long long int ll;
const ll MAX_LL = 0x3f3f3f3f3f3f3f3f;
const int MAX_INT = 0x3f3f3f3f;
using namespace std;

vector<int> v(200005);
set<int> st;
map<int,int> mp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, ts, p1=0, p2;
    cin >> n >> ts;
    for(int i=1;i<=n;i++){
        cin >> v[i];
        mp[v[i]]++; 
        st.insert(v[i]);
    }
    for(int i=1;i<=n;i++){
        if(ts == (2*v[i])){
            if(mp[v[i]] > 1){
                p1 = i;
                break;
            }
        }else if(st.count(ts-v[i])){
            p1 = i;
            break;
        }
    }
    if(p1){
        for(int i=n;i>=1;i--){
            if(v[i] == (ts-v[p1])){
                p2 = i;
                break;
            }
        }
        cout << p1 << " " << p2;
    }else{
        cout << "IMPOSSIBLE";
    }
}
