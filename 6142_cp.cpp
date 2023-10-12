// #include <cstring>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// constexpr int N = 50010;
// struct node
// {
//     int op;
//     int x, y, z;
//     int sign, id;
//     int part;
// } q[8 * N];
// int n, nn, cnt;
// int b[2 * N], c[N];
// int ans[N];
// int fw[2 * N];
// int lowbit(int x) { return x & -x; }
// void update(int k, int x)
// {
//     for (; k <= nn; k += lowbit(k))
//         fw[k] += x;
// }
// int query(int k)
// {
//     int res = 0;
//     for (; k; k -= lowbit(k))
//         res += fw[k];
//     return res;
// }

// void cdq(int l, int r)
// {
//     if (l >= r)
//         return;
//     int mid = l + r >> 1;
//     cdq(l, mid), cdq(mid + 1, r);
//     int i = l;
//     for (int j = mid + 1; j <= r; j++)
//     {
//         while (i <= mid && q[i].y <= q[j].y)
//         {
//             if (q[i].op == 0 && q[i].part == 0)
//                 update(q[i].z, 1);
//             i++;
//         }
//         if (q[j].op == 1 && q[j].part == 1)
//             ans[q[j].id] += q[j].sign * query(q[j].z);
//     }
//     while (i > l)
//     {
//         i--;
//         if (q[i].op == 0 && q[i].part == 0)
//             update(q[i].z, -1);
//     }
//     inplace_merge(q + l, q + mid + 1, q + r + 1, [](const node &a, const node &b)
//                   { return a.y < b.y; });
// }
// void solve(int l, int r)
// {
//     if (l >= r)
//         return;
//     int mid = l + r >> 1;
//     solve(l, mid), solve(mid + 1, r);

//     for (int i = l; i <= mid; i++)
//         q[i].part = 0;
//     for (int i = mid + 1; i <= r; i++)
//         q[i].part = 1;
//     stable_sort(q + l, q + r + 1, [](const node &a, const node &b)
//                 { return a.x < b.x; });
//     cdq(l, r);
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     int T;
//     cin >> T;
//     while (T--)
//     {
//         cin >> n;
//         cnt = nn = 0;
//         for (int i = 1; i <= n; i++)
//             ans[i] = 0, c[i] = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             int op;
//             cin >> op;
//             if (op == 1)
//             {
//                 int x, y, z;
//                 cin >> x >> y >> z;
//                 q[++cnt] = {0, x, y, z};
//                 b[++nn] = z;
//             }
//             else
//             {
//                 c[i] = 1;
//                 int x1, y1, z1, x2, y2, z2;
//                 cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
//                 q[++cnt] = {1, x2, y2, z2, 1, i};
//                 q[++cnt] = {1, x1 - 1, y2, z2, -1, i};
//                 q[++cnt] = {1, x2, y1 - 1, z2, -1, i};
//                 q[++cnt] = {1, x2, y2, z1 - 1, -1, i};
//                 q[++cnt] = {1, x1 - 1, y1 - 1, z2, 1, i};
//                 q[++cnt] = {1, x1 - 1, y2, z1 - 1, 1, i};
//                 q[++cnt] = {1, x2, y1 - 1, z1 - 1, 1, i};
//                 q[++cnt] = {1, x1 - 1, y1 - 1, z1 - 1, -1, i};
//                 b[++nn] = z1 - 1;
//                 b[++nn] = z2;
//             }
//         }
//         sort(b + 1, b + 1 + nn);
//         nn = unique(b + 1, b + 1 + nn) - b - 1;
//         for (int i = 1; i <= cnt; i++)
//             q[i].z = lower_bound(b + 1, b + 1 + nn, q[i].z) - b;
//         solve(1, cnt);
//         for (int i = 1; i <= n; i++)
//             if (c[i])
//                 cout << ans[i] << '\n';
//     }
//     return 0;
// }
















#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#define mid ((l+r)>>1)
#define debug printf("%d %s\n",__LINE__,__FUNCTION__)
using namespace std;
const int N=50010;
struct Query {
	int type,x,y,z,id,v;
}a[N*8],b[N*8],temp[N*8];
int n,T,lsh[N*2],ans[N];
int num,nn,res,qnum,tot;
struct Binary_Indexed_Tree {//树状数组相关 
	int c[N*2];
	void Add(int x,int z) {for (;x<=2*n;x+=(x&-x)) c[x]+=z;}
	int Ask(int x) {for (res=0;x;x-=(x&-x)) res+=c[x];return res;}
	void Clear(int x) {if (!x) return;for (;x<=2*n;x+=(x&-x)) c[x]=0;}
}bit;
int Read() {
	char ch=getchar();
	int s=0,f=1;
	while (ch<'0'||ch>'9') f=(ch=='-'?-1:1),ch=getchar();
	while (ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*f;
}
void Put(int x) {
	if (x<0) {
		putchar('-');
		Put(-x);
		return;
	}
	if (x>9) Put(x/10);
	putchar(x%10+'0');
}
bool cmp1(Query a,Query b) {
	if (a.x!=b.x) return a.x<b.x;
	if (a.y!=b.y) return a.y<b.y;
	if (a.z!=b.z) return a.z<b.z;
	return a.type<b.type;
}
bool cmp2(Query a,Query b) {
	if (a.y!=b.y) return a.y<b.y;
	if (a.z!=b.z) return a.z<b.z;
	return a.type<b.type;
}
void CDQ2(int l,int r) {//第二个CDQ维护y有序
	if (l>=r) return;
	CDQ2(l,mid);
	CDQ2(mid+1,r);
	int p=l,q=mid+1,t=l;
	while (p<=mid&&q<=r) {
		if (cmp2(b[p],b[q])) {
			if (b[p].type==1) bit.Add(b[p].z,1);
			temp[t++]=b[p++];
		} else {
			if (b[q].type==2) ans[b[q].id]+=b[q].v*bit.Ask(b[q].z);
			temp[t++]=b[q++];
		}
	}
	while (q<=r) {
		if (b[q].type==2) ans[b[q].id]+=b[q].v*bit.Ask(b[q].z);
		temp[t++]=b[q++];
	}
	for (int i=l;i<p;i++)
		bit.Clear(b[i].z);
	while (p<=mid) temp[t++]=b[p++];
	for (int i=l;i<=r;i++) b[i]=temp[i];
}
void CDQ1(int l,int r) {//第一个CDQ维护x有序
	if (l>=r) return;
	CDQ1(l,mid);
	CDQ1(mid+1,r);
	int p=l,q=mid+1,t=l;
	int rp=0;
	while (p<=mid&&q<=r) {
		if (cmp1(a[p],a[q])) {
			if (a[p].type==1) b[++rp]=a[p];
			temp[t++]=a[p++];
		} else {
			if (a[q].type==2) b[++rp]=a[q];
			temp[t++]=a[q++];
		}
	}
	while (p<=mid) {
		if (a[p].type==1) b[++rp]=a[p];
		temp[t++]=a[p++];
	}
	while (q<=r) {
		if (a[q].type==2) b[++rp]=a[q];
		temp[t++]=a[q++];
	}
	for (int i=l;i<=r;i++) a[i]=temp[i];
	CDQ2(1,rp);
}
int main() {
	T=Read();
	while (T--) {
		qnum=tot=num=0;
		memset(ans,0,sizeof(ans));
		memset(bit.c,0,sizeof(bit.c));
		n=Read();
		for (int i=1;i<=n;i++) {
			int op,x1,y1,z1,x2,y2,z2;
			op=Read();
			x1=Read(),y1=Read(),z1=Read();
			if (op==1) {
				a[++qnum]=(Query){1,x1,y1,z1,i,1};
				lsh[++num]=z1;
			} else {
				x2=Read(),y2=Read(),z2=Read();
				++tot;
				x1--;y1--;z1--; 
				lsh[++num]=z1;//记录z值
				lsh[++num]=z2;
				a[++qnum]=(Query){2,x2,y2,z2,tot,1};//拆分询问
				a[++qnum]=(Query){2,x1,y2,z2,tot,-1};
				a[++qnum]=(Query){2,x2,y1,z2,tot,-1};
				a[++qnum]=(Query){2,x2,y2,z1,tot,-1};
				a[++qnum]=(Query){2,x1,y1,z2,tot,1};
				a[++qnum]=(Query){2,x1,y2,z1,tot,1};
				a[++qnum]=(Query){2,x2,y1,z1,tot,1};
				a[++qnum]=(Query){2,x1,y1,z1,tot,-1};
			}
		}
		sort(lsh+1,lsh+num+1);//以下四行离散化
		nn=unique(lsh+1,lsh+num+1)-lsh-1;
		for (int i=1;i<=qnum;i++)
			a[i].z=lower_bound(lsh+1,lsh+nn+1,a[i].z)-lsh;
		CDQ1(1,qnum);
		for (int i=1;i<=tot;i++) Put(ans[i]),putchar('\n');
	}
	return 0;
}
