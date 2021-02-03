#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

typedef string str;

const int LAST8 = (1ll << 8ll) - 1ll;
const int K = 7;

unsigned char get_last(uint64_t &key) {
	unsigned char x = key & LAST8;
	key >>= 8ll;
	return x;
}

void swapper(int n, str &s) {
	for (int i = 1; i < n; i += 2)
		swap(s[i - 1], s[i]);
}

void encode(int n, str &s, uint64_t key) {
	unsigned char h = get_last(key);
	bool start = h & 1;
	h >>= 1;
	for (int j = 0; j < K; ++j) {
		unsigned char x = get_last(key);
		if (h & 1) reverse(s.begin(), s.end());
		else swapper(n, s);
		h >>= 1;
		if ((j & 1) ^ start) {
			for (int i = 0; i < n; ++i)
				s[i] ^= x;
		}
		else {
			for (int i = 0; i < n; ++i)
				s[i] += x;
		}
	}
}

void decode(int n, str &s, uint64_t key) {
	unsigned char h = get_last(key);
	bool start = h & 1;
	h >>= 1;
	unsigned char arr[K];
	for (int i = 0; i < K; ++i)
		arr[i] = get_last(key);
	for (int j = K - 1; j >= 0; --j) {
		unsigned char x = arr[j];
		if ((j & 1) ^ start) {
			for (int i = 0; i < n; ++i)
				s[i] ^= x;
		}
		else {
			for (int i = 0; i < n; ++i)
				s[i] -= x;
		}
		if ((h >> j) & 1) reverse(s.begin(), s.end());
		else swapper(n, s);
	}
}