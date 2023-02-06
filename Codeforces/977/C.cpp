#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, k;
    cin >> n >> k;
    set<int> nums;
    map<int,int> qt;
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        nums.insert(aux);
        qt[aux]++;
    }
    if(k == 0){
        if(nums.count(1)){
            cout << "-1\n";
        }else{
            cout << "1\n";
        }
    }else{
        int curqt = 0;
        for(auto it = nums.begin(); it != nums.end(); it++){
            curqt += qt[*it];
            if(curqt == k){
                cout << *it << "\n";
                break;
            }else if(curqt > k){
                cout << "-1\n";
                break;
            }
        }
    }
}
