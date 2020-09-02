
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define par pair< pair<int, int>, int>
#define st first
#define nd second

using namespace std;

int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
int n,b,ant=0,newint,cont=0,cur;
cin >> n >> b;
for(int i=0;i<n;i++){
    cin >> newint;
    newint <=ant ? cur = (ant-newint)/b+1 : cur =0;
    cont+=cur;
    newint+=cur*b;
    ant=newint;
}
cout << cont;
}
