#include <bits/stdc++.h>
using namespace std;

void build_table(vector <string> &table)
{
	for(int i = 0; i < 26; i++)
	{
		string s = "";
		for(int j = 0; j < 26; j++)
		{
			s += char((i + j) % 26 + 97);
		}
		table.push_back(s);
	}
}

int find_index(char s, char k, vector <string> &table)
{
	for(int i = 0; i < 26; i++)
	{
		for(int j = 0; j < 26; j++)
		{
			if(table[int(k) - 'a'][i] == s)
			{
				return i;
			}
		}
	}
	return -1;
}

void print_table(vector <string> &table)
{
	for(int i = 0; i < 26; i++)
	{
		string s = "";
		for(int j = 0; j < 26; j++)
		{
			cout << table[i][j] << " | ";
		}
		cout << endl;
	}
}

string encrypt(string text, string key, vector <string> &table)
{
	string encrypted_text = "";
	for(int i = 0; i < text.length(); i++)
	{
		encrypted_text += table[int(key[i % key.length()] - 'a')][int(text[i] - 'a')];
	}
	return encrypted_text;
}

string decrypt(string cipher, string key, vector <string> &table)
{
	string decrypted_text = "";
	for(int i = 0; i < cipher.length(); i++)
	{
		decrypted_text += char(find_index(cipher[i], key[(i % key.length())], table) + 97);
	}
	return decrypted_text;
}

int main()
{
	vector <string> table;
	build_table(table);
	//print_table(table);
	string text, key;
	cin >> text;
	cin >> key;
	string encrypted_text = encrypt(text, key, table);
	cout << "Cipher text: " << encrypted_text << endl;
	string decrypted_text = decrypt(encrypted_text, key, table);
	cout << "Decrypted text: " << decrypted_text << endl;
}



















/*
Encryption
The plaintext(P) and key(K) are added modulo 26.
Ei = (Pi + Ki) mod 26

Decryption
Di = (Ei - Ki + 26) mod 26
*/