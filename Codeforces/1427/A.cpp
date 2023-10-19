#include <bits/stdc++.h>
 
using namespace std;
 
const long long int INF = 0x3f3f3f3f3f3f3f3f;
 
typedef long long int ll;
typedef vector<long long int> vl;
typedef vector<vector<long long int>> vvl;
 
int main(){
//ios_base::sync_with_stdio(0),cin.tie(0);
int t,n,S,index;
cin >> t;
while(t--){
    cin >> n;
    vector<int> elements(n,0);
    for(int i=0;i<n;i++){
        cin >> elements[i];
    }
    S=0;
    for(int i=0;i<n;i++){
        S+=elements[i];
    }
 
    if(S==0){
        cout << "NO" << endl;
    }else{
        if(S<0){
            sort(elements.begin(),elements.end());
        }else{
            sort(elements.begin(),elements.end(),greater<int>());
        }
        cout << "YES" << endl;
        for(int i=0;i<n;i++){
            cout << elements[i] << " ";
        }
        cout << endl;
    }
}
 
}