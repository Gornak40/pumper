#!/usr/bin/python3
from rsa import decrypt
import pickle


with open('key', 'wb') as key_file, open('private', 'rb') as private_file, open('rsa_key', 'rb') as rsa_key_file:
	rsa_key = rsa_key_file.read()
	private = pickle.load(private_file)
	key = decrypt(rsa_key, private)
	key_file.write(key)