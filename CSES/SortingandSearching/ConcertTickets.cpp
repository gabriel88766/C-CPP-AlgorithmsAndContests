#include <bits/stdc++.h>
typedef long long int ll;
const ll MAX_LL = 0x3f3f3f3f3f3f3f3f;
const int MAX_INT = 0x3f3f3f3f;
using namespace std;

map<int,int> mp;
set<int> ss;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, m, aux;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> aux;
        mp[aux]++;
        ss.insert(aux);
    }
    for(int i=0;i<m;i++){
        cin >> aux;
        auto it = ss.lower_bound(aux);
        if(aux == *it){
            cout << *it << endl;
            mp[*it]--;
            if(!mp[*it])ss.erase(*it);
        }else if(it != ss.begin()){
            it--;
            cout << *it << endl;
            mp[*it]--;
            if(!mp[*it])ss.erase(*it);
        }else{
            cout << -1 << endl;
        }
    }
}
