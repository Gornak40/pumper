#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include "pumper.hpp"

__attribute__((optimize("unroll-loops")))
int main() {
	ifstream in("key");
	uint64_t key; in >> key;
	str s; getline(cin, s);
	int n = (int)s.size();
	encode(n, s, key);
	for (unsigned char c: s)
		cout << (int)c << ' ';
	cout << endl;
}