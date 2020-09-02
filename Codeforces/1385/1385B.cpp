#include <bits/stdc++.h>

using namespace std;

int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
int n,k,temp;
cin >> n;
vector <int> v;
v.reserve(100);
for(int i=0;i<n;i++){
    cin >> k;
    v.clear();
    vector<char> is(51,false);
    for(int j=0; j < 2*k; j++){
        cin >> temp;
        if(!is[temp]){
            is[temp]=true;
            cout << temp << " ";
        }
    }
    cout << endl;
}

}
