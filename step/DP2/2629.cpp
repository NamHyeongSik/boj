#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

//함수에 벡터의 참조자를 넘기는 것  자체부터 시간초과!
int N,M;
vector<int> chu, bid;
long long cache[30][45001];

long long solve(int n, int sum){
   if(n==N) return sum==0 ? 1 : 0; // 양쪽 무게가 같을 경우 1

   long long& ret=cache[n][sum+15000]; // 음수 방지
   if(ret!=-1) return ret;

   ret=0;
   ret+=solve(n+1,sum); // 추를 사용하지 않음
   ret+=solve(n+1,sum+chu[n]); // 추를 구슬이 있는 저울에
   ret+=solve(n+1,sum-chu[n]); // 추를 구슬이 없는 저울에

   return ret;
}

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);

   cin>>N;
   chu.resize(N);
   for(int& i:chu) cin>>i;

   cin>>M;
   bid.resize(M);
   for(int& i:bid) cin>>i;

   for(int i:bid){
      if(i>15000){ // 무게가 15000 초과일 시 무조건 불가능
         cout<<"N ";
         continue;
      }
      memset(cache,-1,sizeof(cache));
      cout<<(solve(0,i)>0LL?"Y ":"N "); // 1번이라도 같아지면 YES
   }

   return 0;
}