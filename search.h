/*Project created by Piotr Lewandowski
im using md5.h and md5.cc files with was
shared on http://www.zedwood.com/article/cpp-md5-function

thepiotr022@gmail.com
*/

#include <iostream>
#include <fstream>

#include <cstring>

#include "md5.h"

using namespace std;

class Hash_de
{
	public:
	Hash_de(string); // inicjacja hasha md5 // Hash_de obj1("md5hashasdnandja");
	char* dyn_MD5_c(string);
	char* decode(char* ="dict.txt");// obj1.decode("location_of_dictionary")
	char* decode_silent(char* ="dict.txt");
	int calc_lines(char* ="dict.txt");
	
	private:
	string hash;
	char* hash_c_main;
	ifstream dict;
	int lines_num;

};


class Brute_gen
{
	public:
	Brute_gen(char*,int,int);
	void file_dump();
	void raw_dump();
	
	private:
	const char* filename;
	char inputFN;
	fstream output;
	int first, last;
};


class Num_brute
{
	public:
	Num_brute(string);
	char* str_to_c(string);
	char* do_brute(int);
	string int_to_str(int);
	
	private:
	int last;
	string hash;
	char* hash_c_main;
};
