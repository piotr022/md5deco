#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <math.h>

#include "md5.h"
#include "search.h"

using namespace std;

Hash_de::Hash_de(string alpha)
{
	std::string str = alpha;
	char *cstr = new char[str.length() + 1];
	strcpy(cstr, str.c_str());
	delete [] cstr;
	const char * test= str.c_str();
	hash_c_main = strdup(test);
}


char* Hash_de::dyn_MD5_c(string md5_s)
{
	std::string str = md5_s;
	char *md5_cc = new char[str.length() + 1];
	strcpy(md5_cc, str.c_str());
	delete [] md5_cc;
	const char *md5_cccc=str.c_str();
	return strdup(md5_cccc);
}


char* Hash_de::decode(char* filena)
{
	const char* fn = filena;
	cout << hash_c_main << endl << endl;
	dict.open(fn); //otwieranie pliku
	string hash_s;
	char *hash_c_temp;
	int hash_lenght = 32;
	
	if (dict.is_open()){
		
	int counter;
	while(getline(dict,hash_s))
	{
		counter = 0;
		hash_c_temp = dyn_MD5_c(md5(hash_s));
		//testing
		cout << dyn_MD5_c (hash_s);
		cout << "   " << hash_c_temp;
		if (hash_c_temp[1]==hash_c_main[1]){
			for(int i = 0; i<=hash_lenght-1; i++){
				if(hash_c_temp[i]==hash_c_main[i])
					counter++;
			}
			if (counter==hash_lenght){
				cout << "  <--  [key found!!!]\n"; return dyn_MD5_c(hash_s);}
			else cout << endl;
		}
			else cout << endl;
		//

	}
	cout << endl << "key not found :(";
}
else return "file of dictionary not found"; 
}


char* Hash_de::decode_silent(char* filean)
{
	const char* fn = filean;
	cout << hash_c_main << endl << endl;
	dict.open(fn); //otwieranie pliku
	string hash_s;
	char *hash_c_temp;
	int hash_lenght = 32;
	
	if (dict.is_open()){
		
	int counter;
	int scaned_num;
	while(getline(dict,hash_s))
	{
		counter = 0;
		hash_c_temp = dyn_MD5_c(md5(hash_s));

		if (hash_c_temp[1]==hash_c_main[1]){
			for(int i = 0; i<=hash_lenght-1; i++){
				if(hash_c_temp[i]==hash_c_main[i])
					counter++;
			}
			if (counter==hash_lenght){
				cout << "[key found!!] " << hash_c_temp;
				return dyn_MD5_c(hash_s);
				}
		}
		
		if(scaned_num%100000==0){ //licznik
			system("clear");
			cout << "working... :)     ";
			cout << "["<<scaned_num<<"/"<<lines_num<<"]  "<< (scaned_num*100)/lines_num << "%\n";
		}
		scaned_num++;
		

	}
	dict.close();
	return "[key not found] :C";
}
else return "file of dictionary not found"; 
}


int Hash_de::calc_lines(char* filen)
{
	const char* fn = filen;
	lines_num=0;
	dict.open(fn);
	if(dict.is_open())
	{
		string useless;
		while(getline(dict,useless))
			lines_num++;
		dict.close();
		return lines_num;
	}
	else {cout << "\ncan't find file '" << filen<<"'\n make sure it exist in folder with from you running md5deco \n";
			return 0;}
}



Brute_gen::Brute_gen(char* FN,int f,int l)
{
	filename = FN;
	first=f; last=l;
}

void Brute_gen::file_dump()
{
	output.open(filename, fstream::out);
	if(output.is_open())
	{
		for(int i=first; i<=last; i++)
			output << i << endl;
		
		output.close();
	}
	
}



Num_brute::Num_brute(string h)
{
	hash_c_main = str_to_c(h);
}



char* Num_brute::str_to_c(string md5_s)
{
	string str = md5_s;
	char *md5_cc = new char[str.length() + 1];
	strcpy(md5_cc, str.c_str());
	delete [] md5_cc;
	const char *md5_cccc=str.c_str();
	return strdup(md5_cccc);
}



string Num_brute::int_to_str(int x)
{
     string tmp;
     
     if(x < 0)
     {
		tmp = "-";
		x = -x;
     }
     if(x > 9)
		tmp += int_to_str(x / 10);
     tmp += x % 10 + 48;
     return tmp;
}



char* Num_brute::do_brute(int digts)
{
	int counter;
	int hash_lenght = 32;
	last = pow(10, digts);//digts*10;
	char* hash_c_temp;
	
	for(int lap=0; lap <= last; lap++)
	{
		hash_c_temp = str_to_c(md5(int_to_str(lap)));
		
		if(hash_c_main[3] == hash_c_temp[3])
		{
			if(hash_c_main[11] == hash_c_temp[11])
			{
				counter = 0;
				
				for(int i=0; i <= hash_lenght-1; i++)
					if(hash_c_main[i] == hash_c_temp[i])
						counter++;
				if(counter == hash_lenght)
				{
					cout << "  [key found!!] -->  ";
					return str_to_c(int_to_str(lap));;
				}
			}
		}
	}
	return "[key not found] :C\n";
}
