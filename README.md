# md5deco
md5 dictionary / bruteforce hash decoding program program

compile:

g++ *.cc -o md5deco

help:
 
./md5deco

carck md5 using dictionary:

./md5deco 'hash_to_crack' 'name_of_your_dict_file'

crack md5 by numeral brute-force (max 9 digts):

./md5deco bruteforce 'md5hash_sum_to_crack' 'number_of_digts'

generating numbers dictionary:

./md5deco 'file_name_to_save]' 'startValue' 'stopValue'

examples:

./md5deco 098f6bcd4621d373cade4e832627b4f6 darc0de.lst

./md5deco bruteforce 202cb962ac59075b964b07152d234b70 3

 only for educational purposes
 
 TO DO:
 
 -everything :p


example output: 

./md5deco bruteforce 5059437b8a54d05c09884405ebaf7fb1 9

--------------------------------------------- 

Welcome :D in md5deco program

with this program you can decode md5 hashes

using dictionary scanning mode, or numerical bruteforce

full brute force with characters will be added soon :D

Verbose mode is more more slower than normal

thepiotr022@gmail.com 

---------------[good luck]!------------------

9 digts brute force mode!


 [1] digts numbers bruting :D

 [2] digts numbers bruting :D

 [3] digts numbers bruting :D

 [4] digts numbers bruting :D

 [5] digts numbers bruting :D

 [6] digts numbers bruting :D

 [7] digts numbers bruting :D
  [key found!!] -->  3234567	5059437b8a54d05c09884405ebaf7fb1
