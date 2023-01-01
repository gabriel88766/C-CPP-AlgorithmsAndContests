#include <bits/stdc++.h>
#define ll long long int

using namespace std;
vector<pair<int,int>> v;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, y, a, b, cur_a;
    cin >> x >> y >> a >> b;
    while(b <= y){
        cur_a = max(b+1, a);
        while(cur_a <= x){
            v.push_back({cur_a, b});
            cur_a++;
        }
        b++;
    }





    sort(v.begin(), v.end());
    cout << v.size() << endl;
    for(auto it = v.begin(); it != v.end(); it++){

        cout << it->first << " " << it->second << "\n";
    }   
}
