#include <bits/stdc++.h>

using namespace std;

unsigned int matrix[100005][102];
const int MOD = 1e9+7;

int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
//freopen("test_input.txt", "r", stdin);
int n;
vector<int> v;
set<int> imnotadp,neitherI;
cin >> n;
v.resize(n);
for(int i=0;i<n;i++){
    cin >> v[i];
}
for(int i=0;i<n;i++){
    neitherI=imnotadp;
    neitherI.insert(v[i]);
    for(auto it = imnotadp.begin();it!=imnotadp.end();it++){
        neitherI.insert((*it)+v[i]);
    }
    imnotadp = neitherI;
}

cout << imnotadp.size() << endl;
for(auto it = imnotadp.begin();it!=imnotadp.end();it++){
        cout << *it << " ";
    }

}

