#!/usr/bin/python3
from rsa import encrypt, decrypt, newkeys
import pickle


public, private = newkeys(1024)
with open('public', 'wb') as public_file, open('private', 'wb') as private_file:
	pickle.dump(public, public_file)
	pickle.dump(private, private_file)