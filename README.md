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
