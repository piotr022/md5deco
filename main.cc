#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "md5.h"
#include "search.h"

using namespace std;

int main(int argc, char * argv[])
{
string input;
bool silent=true;
system("clear");
cout << "---------------------------------------------\n";
cout << "you have to create 'dict.txt' file with cointains dictionary\n";
cout << "Verbose mode is more more slower than normal\n";
cout << "your 'dict.txt' should be big if you want to crack sth\n";
cout << "thepiotr022@gmail.com \n";
cout << "usage:\n";
cout << "./md5deco\n";
cout << "./md5deco md5hash_sum\n";
cout << "generating digts dictionary: ./md5deco output.txt first_array last_array\n";
cout << "---------------[good luck]!------------------\n";

if(argc==1){
	cout << "hash to crack: ";
	cin >> input;
}
else if(argc == 4)
{
	Brute_gen brute1(argv[1],atoi(argv[2]),atoi(argv[3]));
	cout << "GENERATING number dictionary to '"<<argv[1]<<"' from ";
	cout << atoi(argv[2]) << " to " << atoi(argv[3])<< endl;
	brute1.file_dump();
	return 0;
}
else
{
	input = string(argv[1]);
	cout << "decoding " + string(argv[1]) << " md5 hash\n";
}
/////
Hash_de crack1(input);
/////
cout << endl;
cout << "0 - Verbose | 1 - normal | choose 0 or 1: "; cin >> silent;
string cont;
cout << "file cointains "<<crack1.calc_lines()<<" words. continue? [yes/no] : ";
cin>>cont;
if (cont == "yes"){
cout << "hash decoding started :D ... : ";


if(silent == false)
	cout << crack1.decode() << endl << endl;
else
	cout << "     " << crack1.decode_silent() << endl << endl;
}
else cout << "goodbay\n";
}
