#include <bits/stdc++.h>
typedef long long int ll;
const ll MAX_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int MAX_INT = 0x3f3f3f3f;
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin);  test input
    int n, k;
    vector<int> v;
    cin >> n >> k;
    string s(n+1, ' ');
    s[0] = 'L';
    for(int i=0;i<k;i++){
        int aux;
        cin >> aux;
        v.push_back(aux);
    }
    sort(v.begin(), v.end());
    for(int i=1;i <= n;i++){
        s[i] = 'L';
        for(int j=0; j< v.size(); j++){
            if(v[j] <= i){
                if(s[i - v[j]] == 'L') s[i] = 'W';
            }else break;
        }
    }
    cout << s.substr(1,n);

}
 