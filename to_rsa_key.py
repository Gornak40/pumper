#!/usr/bin/python3
from rsa import encrypt
import pickle


with open('key', 'rb') as key_file, open('public', 'rb') as public_file, open('rsa_key', 'wb') as rsa_key_file:
	key = key_file.read()
	public = pickle.load(public_file)
	rsa_key = encrypt(key, public)
	rsa_key_file.write(rsa_key)