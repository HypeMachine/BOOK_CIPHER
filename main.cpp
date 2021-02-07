#include "Book_cipher.h"

int main()
{
	setlocale (LC_ALL, "Russian");

	string nameOpenFile = "OpenTXT.txt";
	string nameKeyFile = "KeyTXT.txt";

	string opentxt = readTxt(nameOpenFile);
	string keytxt = readTxt(nameKeyFile);

	cout << "Текст который будем шифровать: \n" << opentxt << "\n";
	cout << "Текст-ключ для расшифровки: \n" << keytxt << "\n";

	vector<int> res = crypt(opentxt, keytxt);

	cout << "Зашифрованный текст: \n";

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << "\n";
	}

	string decrypttxt = decrypt(res, keytxt);

	cout<< "Расшифровка: \n" << decrypttxt << "\n";

	return 0;
}