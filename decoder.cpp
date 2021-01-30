#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include "pumper.hpp"

__attribute__((optimize("unroll-loops")))
int main() {
	ifstream in("key");
	uint64_t key; in >> key;
	str s;
	for (int val; cin >> val;)
		s.push_back(val);
	int n = (int)s.size();
	decode(n, s, key);
	cout << s << endl;
}