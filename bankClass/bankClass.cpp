#include <iostream>
#include "bankAccount.h"

using namespace std;

void aralik()
{
    cout << "##############################" << endl;
}


int main()
{
    bankAccount acc1("savas", "eratesli",56299,"05346196233");

    cout << "Ad: " << acc1.getPersonName() << endl;
    cout << "SoyAd: " << acc1.getPersonSurname() << endl;
    cout << "Tel: " << acc1.getPersonPhone() << endl;
    cout << "Hesap: " << acc1.getPersonBalance() << endl;

    aralik();

    bankAccount acc2(acc1);
    cout << "Ad: " << acc2.getPersonName() << endl;
    cout << "SoyAd: " << acc2.getPersonSurname() << endl;
    cout << "Tel: " << acc2.getPersonPhone() << endl;
    cout << "Hesap: " << acc2.getPersonBalance() << endl;

    acc1.credit(150);
    acc1.displayProfil();
    acc1.withDraw(300);
    acc1.displayProfil();

    bankAccount acc3("nazlican","jenner",0,"12345678910");

    acc1.displayProfil();
    acc3.displayProfil();

    acc1.sendMoney(acc3,1500);

    acc1.displayProfil();
    acc3.displayProfil();




    return 0;
}
