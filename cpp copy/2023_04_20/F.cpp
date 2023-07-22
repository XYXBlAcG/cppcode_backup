#include <cstdio>
const int N = 1e3 + 5;
int n;
char list[N];
int cnt;
int mod = 1e9 + 7;
typedef long long ll;
int read() {
  int x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {  // ch ��������ʱ
    if (ch == '-') w = -1;        // �ж��Ƿ�Ϊ��
    ch = getchar();               // ��������
  }
  while (ch >= '0' && ch <= '9') {  // ch ������ʱ
    x = x * 10 + (ch - '0');  // ���¶�������֡��ӡ��� x �ĺ���
    // x �� int ���ͣ�char ���͵� ch �� '0' �ᱻ�Զ�תΪ���Ӧ��
    // ASCII �룬�൱�ڽ� ch ת��Ϊ��Ӧ����
    // �˴�Ҳ����ʹ�� (x<<3)+(x<<1) ��д�������� x*10
    ch = getchar();  // ��������
  }
  return x * w;  // ���� * ������ = ʵ����ֵ
}
int main(){
	for (char c = getchar(); c > 32; c = getchar()){
		list[++cnt] = c;
	}
	ll ans = 0;
	for (int i = 1; i <= cnt; i++){
		for (int j = 1; j <= i; j++){
			int flag = 0, l = j; int kk = 0;
			for (int k = cnt; k >= i && l <= i; k--){
				kk = k;
				if(list[l] == list[k]) {
					flag = 1; l++;
//					printf("j:%d k:%d ans:%d\n", l - 1, k, ans);
				}else{
					flag = 0; 
				}
			}
			if(flag) {
				ans++;
			}
		}
		ans %= mod;
	}
	printf("%d ", ans);
	return 0;
}

//int flag1 = 0;
//		for (int j = 1, o = i; j <= o; j++, o--){
//			if(j == o) break;
//			if(list[j] == list[o]){
//				flag1 = 1;
//			}else{
//				flag1 = 0;
//			}
//			printf("j: %d o: %d flag: %d\n", j, o, flag1);
//		}ans += flag1;
//		
//		int flag2 = 0;
//		for (int j = i + 1, o = cnt; j <= o; j++, o--){
//			if(j == o) break;
//			if(list[j] == list[o]){
//				flag2 = 1;
//			}else{
//				flag2 = 0;
//			}
//			printf("j: %d o: %d flag: %d\n", j, o, flag2);
//		}ans += flag2;
//		
//		ans %= mod;
