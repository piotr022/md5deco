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
cout << "--------------------------------------------- "<< endl;
cout << "Welcome :D in md5deco program\nwith this program you can decode md5 hashes\n";
cout << "using dictionary scanning mode, or numerical bruteforce\n";
cout << "full brute force with characters will be added soon :D\n";
cout << "Verbose mode is more more slower than normal\n";
cout << "thepiotr022@gmail.com \n";
cout << "---------------[good luck]!------------------\n";
if(argc==1)
{
	cout << "\nusage:\n";
	cout << "\thelp:\n";
	cout << "./md5deco\n";
	cout << "\tcrack hash by default 'dict.txt':\n";
	cout << "./md5deco 'md5hash_sum_to_crack'\n";
	cout << "\tgenerating digts dictionary: \n./md5deco 'output.txt' 'first_array' 'last_array'\n";
	cout << "\tcrack md5 using custom name dictionary:\n";
	cout << "./md5deco 'hash_to_crack' 'name_of_your_dict'\n";
	cout << "\tbrute force only numerical md5 hashes\n";
	cout << "./md5deco bruteforce 'md5hash_sum_to_crack' 'number_of_digts'\n";
	cout << "\texamples:\n./md5deco 098f6bcd4621d373cade4e832627b4f6 darc0de.lst\n";
	cout << "./md5deco bruteforce 202cb962ac59075b964b07152d234b70 3\n\n";
	return 0;
}

bool file=false;
char* file_n;
//if(argc==1){
//	cout << "hash to crack: ";
//	cin >> input;
//}
if(argc == 4)
{
	if (string(argv[1]) == "bruteforce")
	{
		string mdh = string(argv[2]);
		Num_brute numforce1(mdh);
		int digts = atoi(argv[3]);
		cout << digts << " digts brute force mode!\n\n";
		char* eq = numforce1.do_brute(digts);
		cout << eq << "\t" << md5(string(eq));
		cout << endl << endl;
		return 0;
	}
	else{
	Brute_gen brute1(argv[1],atoi(argv[2]),atoi(argv[3]));
	cout << "GENERATING number dictionary to '"<<argv[1]<<"' from ";
	cout << atoi(argv[2]) << " to " << atoi(argv[3])<< endl;
	brute1.file_dump();
	return 0;}
}
else if(argc == 2)
{
	input = string(argv[1]);
	cout << "decoding " + string(argv[1]) << " md5 hash\n";
}
if(argc==3)
{
	file=true;
	input = string(argv[1]);
	file_n = argv[2];
}

/////
Hash_de crack1(input);
/////
cout << endl;
cout << "0 - Verbose | 1 - normal | choose 0 or 1: "; cin >> silent;
string cont;
cout << "file cointains "<<crack1.calc_lines(file_n)<<" words. continue? [yes/no] : ";
cin>>cont;
if (cont == "yes"){
cout << "hash decoding started :D ... : ";


if(silent == false){
	if(file==false)
		cout<<"+" << crack1.decode() << endl << endl;
	else cout << crack1.decode(argv[2]) << endl << endl;
}
else{
	if(file==false)
		cout << "  +  " << crack1.decode_silent() << endl << endl;
	else cout << "     " << crack1.decode_silent(argv[2]) << endl << endl;
}
}
else cout << "goodbay\n";
}
