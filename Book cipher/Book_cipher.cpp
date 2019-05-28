#include "Book_cipher.h"


string readTxt(string nameOpenFile)
{
	string rTXT;
	FILE* openFile;
	fopen_s(&openFile, nameOpenFile.c_str(), "r");
	while (!openFile)
	{
		cout << "Can't open file " << nameOpenFile << ". Please, enter another filename: ";
		cin >> nameOpenFile;
		fopen_s(&openFile, nameOpenFile.c_str(), "r");
	}
	char str[10];
	while (fgets(str, 10, openFile) != NULL)
		rTXT += str;
	fclose(openFile);
	return rTXT;
}


/*string readKeyTXT(string nameKeyFile)
{
	string keyTXT;
	FILE* keyFile;
	fopen_s(&keyFile, nameKeyFile.c_str(), "r");
	while (!keyFile)
	{
		cout << "Can't open file " << nameKeyFile << ". Please, enter another filename: ";
		cin >> nameKeyFile;
		fopen_s(&keyFile, nameKeyFile.c_str(), "r");
	}

	char str[10];
	while (fgets(str, 10, keyFile) != NULL)
		keyTXT += str;

	fclose(keyFile);
	return keyTXT;
}*/

vector<int> crypt(string opentxt, string keytxt)
{
	vector<int> result;
	vector<bool> used(keytxt.size());
	bool need_to_reload_used;

	for (int i = 0; i < opentxt.size(); i++)
	{
		if (!keytxt.find(opentxt[i])) // Если такого вообще нет в ключе
		{
			cout << "Bad key";
		}

		need_to_reload_used = true;
		for (int j = 0; j < keytxt.size(); j++)
		{
			if (keytxt[j] == opentxt[i] && !used[j])
			{
				result.push_back(j);
				used[j] = true;
				need_to_reload_used = false;
				break;
			}
		}
		if (need_to_reload_used)
		{
			for (int j = 0; j < keytxt.size(); j++)
			{
				if (keytxt[j] == opentxt[i])
				{
					used[j] = false;
				}
			}
			i--;
		}
	}

	FILE* file_res;
	fopen_s(&file_res, "CryptedTXT.txt", "w");

	for (int i = 0; i < result.size(); i++)
	{
		fprintf(file_res, "v(%d)", result[i]);
	}

	fclose(file_res);
	return result;
}

string decrypt(vector<int> res, string keytxt)
{
	string result; 
	for (int i = 0; i < res.size(); i++)
	{
		result.push_back(keytxt[res[i]]);
	}


	FILE* file_res;
	fopen_s(&file_res, "DecryptedTXT.txt", "w");

	for (int i = 0; i < result.size(); i++)
	{
		fputc(result[i], file_res);
	}

	fclose(file_res);
	return result;
}