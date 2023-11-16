// #include<bits/stdc++.h>
// using namespace std;
// long long n,z;
// long long x[200005];
// bool check(int u){
// 	for(int i=1;i<=u;i++){
// 		if(x[n-u+i]-x[i]<z) return false;
// 	}
// 	return true;
// }
// int main(){
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	cout.tie(0);
// 	cin>>n>>z;
// 	for(int i=1;i<=n;i++){
// 		cin>>x[i];
// 	}
// 	sort(x+1,x+1+n);//排序 
// 	int l=0,r=n/2;//二分 
// 	while(l<=r){
// 		int mid=(l+r)>>1;
// 		if(check(mid)) l=mid+1;
// 		else r=mid-1;
// 	}
// 	cout<<r;
// 	return 0;
// } 