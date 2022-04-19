#include <iostream>
#include<string.h>

using namespace std;

class bankAccount
{
public:
	bankAccount(string name, string surname, float balance = 0, string phoneNumber = "");
	bankAccount(const bankAccount& othAccount);
	~bankAccount();

	bool controlNameSurname(string nameOrSurname);
	bool controlPhoneNumber(string phoneNumber);
	void displayProfil();
	void credit(float);//Para yat�rma
	void withDraw(float);//Para �ekme
	void sendMoney(bankAccount& othAccount, float amount);//Havale
	void setPersonName(string name);
	void setPersonSurname(string surname);
	void setPersonPhone(string phone);
	void setPersonBalance(float balance = 0);
	int getPersonBalance() const
	{
		return accountBalance;
	}
	string getPersonName() const
	{
		return personName;
	}
	string getPersonSurname() const
	{
		return personSurname;
	}
	string getPersonPhone() const
	{
		return personPhone;
	}

private:
	float accountBalance;
	string personName, personSurname, personPhone;
	
};

void bankAccount::setPersonName(string name)
{
	//Kullan�c� do�ru girene kadar ismi al
	while (!controlNameSurname(name))
	{
		cout << "Gecersiz Isim!!" << endl;
		cin >> name;
	}
	personName = name;
}

void bankAccount::setPersonSurname(string surname)
{
	//Kullan�c� do�ru girene kadar ismi al
	while (!controlNameSurname(surname))
	{
		cout << "Gecersiz Soyisim!!" << endl;
		cin >> surname;
	}
	personSurname = surname;
}

void bankAccount::setPersonPhone(string phone)
{
	//Kullan�c� do�ru girene kadar ismi al
	while (!controlPhoneNumber(phone))
	{
		cout << "Gecersiz Telefon Numarasi!!" << endl;
		cin >> phone;
	}
	personPhone = phone;
}

void bankAccount::setPersonBalance(float balance)
{
	if (balance < 0)
	{
		accountBalance = 0;
		cout << "Hatali Bakiye!!" << endl;
	}
	else
	{
		accountBalance = balance;
	}
}

bankAccount::bankAccount(string name, string surname, float balance, string phoneNumber)
{
	setPersonName(name);
	setPersonSurname(surname);
	setPersonPhone(phoneNumber);
	setPersonBalance(balance);

	cout << "Hesap Olusturuldu." << endl;
}

bankAccount::~bankAccount()
{
	cout << "Hesap Kapatildi." << endl;
}

bankAccount::bankAccount(const bankAccount& othAccount)
{
	personName = othAccount.personName;
	personSurname = othAccount.personSurname;
	personPhone = othAccount.personPhone;
	accountBalance = othAccount.accountBalance;

	cout << "Hesap Kopyalandi." << endl;

}

bool bankAccount::controlNameSurname(string nameOrSurname)
{
	for (unsigned i = 0; i < nameOrSurname.length(); i++)
	{
		//at-> indexteki karaktere eri�mek i�in
		if (!((nameOrSurname.at(i) >= 'A' && nameOrSurname.at(i) <= 'Z')|| (nameOrSurname.at(i) >= 'a' && nameOrSurname.at(i) <= 'z')))
		{
			return false;//a-z aras�nda de�ilse false
		}

	}
	return true;
}

bool bankAccount::controlPhoneNumber(string phoneNumber)
{
	if (phoneNumber.empty())
	{
		return true;
	}

	if (phoneNumber.length() != 11)
	{
		return false;
	}

	for (unsigned i = 0; i < phoneNumber.length(); i++)
	{
		if (!(phoneNumber.at(i) >= '0' && phoneNumber.at(i) <= '9'))
		{
			return false;
		}
	}
	return true;
}

void bankAccount::credit(float amount)
{
	while (amount <= 0)
	{
		cout << "Gecersiz Miktar!!" << endl;
		cin >> amount;
	}
	accountBalance += amount;
}

void bankAccount::withDraw(float amount)
{
	while (amount <= 0||amount>accountBalance)
	{
		cout << "Gecersiz Miktar!!" << endl;
		cin >> amount;
	}
	accountBalance -= amount;
}

void bankAccount::displayProfil()
{
	cout << "--------------------------" << endl;
	cout << "Isim: " << personName << endl;
	cout << "SoyIsim: " << personSurname << endl;

	if (!personPhone.empty())
	{
		cout << "Tel: " << personPhone << endl;
	}
	else
	{
		cout << "Tel: #" << personPhone << endl;
	}

	cout << "Hesap: " << accountBalance << " Dollar" << endl;
}

void bankAccount::sendMoney(bankAccount& othAccount, float amount)
{
	while (amount <= 0 || amount > accountBalance)
	{
		cout << "Gecersiz Miktar!!" << endl;
		cin >> amount;
	}

	accountBalance -= amount;//G�nderen
	othAccount.accountBalance += amount;//Al�c�


}









