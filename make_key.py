#!/usr/bin/python3
from random import getrandbits


key = getrandbits(64)
with open('key', 'w') as key_file:
	print(key, file=key_file)