# Pumper
Simple crypto algorithm which uses ascii.
### Build
* ```./build.sh``` on Linux or ```build.bat``` on Windows
* **Person A** should use ```make_key``` and ```to_rsa_key``` then send ```public``` and ```rsa_key``` to **Person B**
* **Person B** should use ```from_rsa_key``` after getting ```public``` and ```rsa_key``` files
### Usage
* ```./encoder``` put an ascii string
* ```./decoder``` put an array and press *Ctrl+D* on Linux or *Ctrl+Z* on Windows
### Idea
![key image](https://i.postimg.cc/9f0Rw0F5/key.png)
*Key structure*

* **paramets** are paramets
* **reverse and swapper** we need to reverse *(1)* or swap odds end evens *(0)* before each iteration
* **start flag** we need to start with xor *(1)* or sum *(0)*