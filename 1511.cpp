///max-difference=120
#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::string;
int n;
string s;

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		string a, b;
		cin >> a >> b;
		string t = s + a;
		if(t.length() < b.length())
			continue;
		if(t.substr(t.length() - b.length()) == b)
			s = t;
	}
	for(int i = 0; i <= (int)s.length()-1; i++)
        s[i] = toupper(s[i]);
		// if('a' <= s[i] && s[i] <= 'z')
		// 	s[i] = s[i] + 'A' - 'a';
    printf("%s\n", s.c_str());
	// cout << s << '\n';
	return 0;
}
//do not modify the following code
//ending-code

// #if (__GNUC__ > 4) || (__cplusplus > 199711L) || defined(__clang__)
// #error
// #endif
