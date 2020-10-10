#include<bits/stdc++.h>

#define INF 0x3f3f3f3f
#define par pair< pair<int, int>, int>
#define st first
#define nd second
#define mp(x,y) make_pair(x,y)
#define sti pair<string,int>
//matrix vector<vector<int>> matrix(row,vector<int>(col))

using namespace std;

int gcd(int a,int b){
    if((a&&b)){
        return gcd(b,a-b*(a/b));
    }else if(a){
        return a;
    }else{
        return b;
    }
}


int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
int n,entry,curmax,cont;
cin >> n;
multiset<int> m;
vector<int> values;
for(int i=0;i<n*n;i++){
    cin >> entry;
    m.insert(entry);

}
while(n){
    curmax = *(--m.end());
    values.push_back(curmax);
    m.erase(--m.end()); // how to remove greatest value in a multiset.
    for(int i=0;i<values.size()-1;i++){
        m.erase(m.find(gcd(values[i],curmax)));
        m.erase(m.find(gcd(values[i],curmax)));
    }
    n--;
}
for(int i=0;i<values.size();i++){
    cout << values[i] << " ";
}
}


