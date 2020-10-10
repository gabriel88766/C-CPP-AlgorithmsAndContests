#include<bits/stdc++.h>

#define INF 0x3f3f3f3f
#define par pair< pair<int, int>, int>
#define st first
#define nd second
#define mp(x,y) make_pair(x,y)
#define sti pair<string,int>
//matrix vector<vector<int>> matrix(row,vector<int>(col))

using namespace std;

int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
int n,aux,Sum=0,mini,maxi,lm=0,gm=0;
vector<int> v;
cin >> n;
for(int i=0;i<n;i++){
    cin >> aux;
    Sum+=aux;
    v.push_back(aux);
}
mini = Sum/n;
maxi = mini;
if(Sum%n) maxi++;
sort(v.begin(),v.end());
for(int i=0;i<n;i++){
    if(v[i]<mini) lm +=(mini-v[i]);
    if(v[i]>maxi) gm +=(v[i]-maxi);
}
cout << max(lm,gm);

}


