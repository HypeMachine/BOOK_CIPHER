#ifndef BOOK_CIPHER_H
#define BOOK_CIPHER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string readTxt(string nameOpenFile);
//string readKeyTXT(string nameKeyFile);
vector<int> crypt(string opentxt, string keytxt);
string decrypt(vector<int> res, string keytxt);

#endif