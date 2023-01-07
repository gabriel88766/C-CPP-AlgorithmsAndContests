#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> //required
//#include <ext/pb_ds/tree_policy.hpp> //required

typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

//using namespace __gnu_pbds; //required 
//template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ll h1, h2, Sumh1 = 0, Sumh2 = 0;
    //ordered_set<pair<int,int>> sp;

    int n, k;
    cin >> n >> k;
    h1 = k/2; //if odd, median is lesser of seth2, else, is lesser h2 + greater h1
    h2 = k - h1;
    set<pair<int,int>> setH1, setH2;


    vector<int> v(n);
    vector<ll> ans;
    for(int i=0;i<n;i++) cin >> v[i];

    if(k == 1){ //corner case
        for(int i=0;i<n;i++) cout << "0 ";
        return 0;
    } 
    //forming first groups
    set<pair<int,int>> aux;
    for(int i=0;i<k;i++) aux.insert({v[i], i});
    auto auxIT = aux.begin();
    for(int i=0;i<k;i++){
        if(i < h1) {
            setH1.insert(*auxIT);
            Sumh1 += auxIT->first;
        }else{
            setH2.insert(*auxIT);
            Sumh2 += auxIT->first;
        } 
        auxIT++;
    }
    
    if(k % 2){
        ans.push_back(Sumh2 - Sumh1 - setH2.begin()->first);
    }else{
        ans.push_back(Sumh2 - Sumh1);
    }

    for(int i=k;i<n;i++){
        pair<int, int> p = {v[i-k], i-k};
        if(setH1.count(p)){
            Sumh1 -= v[i-k];
            setH1.erase(p);
            if(v[i] <= setH2.begin()->first){
                Sumh1 += v[i];
                setH1.insert({v[i], i});
            }else{
                auto FirstH2 = *setH2.begin();
                Sumh2 -= FirstH2.first;
                setH2.erase(FirstH2);
                setH1.insert(FirstH2);
                Sumh1 += FirstH2.first;
                Sumh2 += v[i];
                setH2.insert({v[i], i});
            }
        }else{
            Sumh2 -= v[i-k];
            setH2.erase(p);
            auto auxIT2 = setH1.end();
            auxIT2--;
            if(v[i] >= auxIT2->first){
                Sumh2 += v[i];
                setH2.insert({v[i], i});
            }else{
                auto LastH1 = *auxIT2;
                Sumh1 -= LastH1.first;
                setH1.erase(LastH1);
                setH2.insert(LastH1);
                Sumh2 += LastH1.first;
                Sumh1 += v[i];
                setH1.insert({v[i], i});
            }

        }

        if(k % 2){
            ans.push_back(Sumh2 - Sumh1 - setH2.begin()->first);
        }else{
            ans.push_back(Sumh2 - Sumh1); 
        }
    }


    // i have medians!
    for(int i=0; i<ans.size();i++) cout << ans[i] << " ";
}
