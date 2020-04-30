#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <vector>
#include <string>


using namespace std;

class CFlat
{
private:
  vector <string> HumansName;
  int time,
    Square,
    electricity,
    water,
    gas;
public:
  CFlat(int set_time, int set_Square, int set_electricity, int set_water, int set_gas)
  {
    setState(set_time, set_Square, set_electricity, set_water, set_gas);
  }
  void addHuman()
  {
    cout << "Введіть ім'я" << endl;
    string name;
    cin >> name;
    HumansName.push_back(name);
  }
  void viewHuman()
  {
    for (unsigned int i = 0; i < HumansName.size(); i++)
    {
      cout << i << "\t" << HumansName[i] << endl;
    }
  }
  int getCountPeople()
  {
    return HumansName.size();
  }
  void delHuman()
  {
    viewHuman();
    cout << "Введіть номер" << endl;
    int k;
    cin >> k;
    HumansName.erase(HumansName.begin() + k);
  }
  void setState(int time, int Square, int electricity, int water, int gas)
  {
    this->time = time;
    this->Square = Square;
    this->electricity = electricity;
    this->water = water;
    this->gas = gas;
  }
  void currentstate()
  {
    cout << "Термін експлуатації квартири: " << time << " дн" << endl;
    cout << "Площа: " << Square << "м3" << endl;
    cout << "Кількість спожитої електроенергії: " << electricity << " Вт/г" << endl;
    cout << "Кількість спожитої води: " << water << " л" << endl;
    cout << "Кількість спожитого газу: " << gas << " кб" << endl;
    system("pause");
  }
  double price()
  {
    return electricity * 1.2 + water * 2.1 + gas * 1.5;
  }
  friend ostream& operator << (ostream& os, const CFlat& Flat) {
    os << "Термін експлуатації квартири: " << Flat.time << " дн" << endl;
    os << "Площа: " << Flat.Square << "м3" << endl;
    os << "Кількість спожитої електроенергії: " << Flat.electricity << " Вт/г" << endl;
    os << "Кількість спожитої води: " << Flat.water << " л" << endl;
    os << "Кількість спожитого газу: " << Flat.gas << " кб" << endl;
    os << endl;
    return os;
  }
  friend istream& operator >> (istream& is, CFlat& Flat) {
    cout << "Введіть термін експлуатації квартири: " << endl;
    is >> Flat.time;
    cout << "Введіть площу: " << endl;
    cin >> Flat.Square;
    cout << "Введіть кількість спожитої електроенергії: " << endl;
    is >> Flat.electricity;
    cout << "Введіть кількість спожитої води: " << endl;
    is >> Flat.water;
    cout << "Введіть кількість спожитого газу: " << endl;
    is >> Flat.gas;
    return is;
  }
  CFlat& operator = (const CFlat& Flat)
  {
    if (&Flat == this)
    {
      return *this;
    }
    else
    {
      setState(Flat.time, Flat.Square, Flat.electricity, Flat.water, Flat.gas);
      HumansName = Flat.HumansName;
      return *this;
    }
  }
  CFlat& operator += (const CFlat& Flat)
  {
    time += Flat.time;
    Square += Flat.Square;
    electricity += Flat.electricity;
    water += Flat.water;
    gas += Flat.gas;
    for (unsigned int i = 0; i < Flat.HumansName.size(); i++)
    {
      HumansName.push_back(Flat.HumansName[i]);
    }
    return *this;
  }
  CFlat operator -- (int)
  {
    electricity--;
    water--;
    gas--;
    return *this;
  }
  bool operator != (const CFlat& Flat)
  {
    if (time == Flat.time &&
      Square == Flat.Square &&
      electricity == Flat.electricity &&
      water == Flat.water &&
      gas == Flat.gas &&
      HumansName.size() == Flat.HumansName.size()
      )
    {
      return 0;
    }
    else
      return 1;
  }
};

extern void mainScreen(CFlat& Flat);

CFlat N1(50, 15, 7, 50, 80), N2(0, 0, 0, 0, 0);

void FlatSelector()
{
  system("cls");
  cout << "Виберіть дію" << endl;
  cout << "1. Перейти до керування першою квартирою" << endl;
  cout << "2. Перейти до керування другою квартирою" << endl;
  cout << "3. Скопіювати дані про першу квартиру в другу" << endl;
  cout << "4. Додати дані з першої квартири в другу" << endl;
  cout << "5. Зменшити параметри першої квартири на 1" << endl;
  cout << "6. Зменшити параметри другої квартири на 1" << endl;
  cout << "7. Перевірити чи квартири не однакові" << endl;
  cout << "8. Вихід" << endl;
  int ch;
  cin >> ch;
  switch (ch)
  {
  case 1:
    system("cls");
    mainScreen(N1);
  case 2:
    system("cls");
    mainScreen(N2);
  case 3:
    system("cls");
    N2 = N1;
    FlatSelector();
  case 4:
    system("cls");
    N2 += N1;
    FlatSelector();
  case 5:
    system("cls");
    N1--;
    FlatSelector();
  case 6:
    system("cls");
    N2--;
    FlatSelector();
  case 7:
    system("cls");
    if (N1 != N2)
    {
      cout << "Квартири не однакові" << endl;
    }
    else
    {
      cout << "Квартири однакові" << endl;
    }
    system("pause");
    FlatSelector();
  default:
    exit(0);
  }
}


extern void mainScreen(CFlat& Flat)
{
  system("cls");
  cout << "Виберіть дію" << endl;
  cout << "1. Заселити мешканця" << endl;
  cout << "2. Переглянути імена мешканців" << endl;
  cout << "3. Переглянути кількість мешканців" << endl;
  cout << "4. Виселити мешканця" << endl;
  cout << "5. Переглянути поточний стан" << endl;
  cout << "6. Змінити стан" << endl;
  cout << "7. Розрахувати вартість" << endl;
  cout << "8. Повернутись до попереднього меню" << endl;
  int ch;
  cin >> ch;
  switch (ch)
  {
  case 1:
    system("cls");
    Flat.addHuman();
    mainScreen(Flat);
  case 2:
    system("cls");
    Flat.viewHuman();
    system("pause");
    mainScreen(Flat);
  case 3:
    system("cls");
    cout << "Кількість мешканців: " << Flat.getCountPeople() << endl;
    system("pause");
    mainScreen(Flat);
  case 4:
    system("cls");
    Flat.delHuman();
    mainScreen(Flat);
  case 5:
    system("cls");
    Flat.currentstate();
    mainScreen(Flat);
  case 6:
    system("cls");
    cin >> Flat;
    mainScreen(Flat);
  case 7:
    system("cls");
    cout << "Вартість спожитих ресурсів: " << Flat.price() << "грн" << endl;
    system("pause");
    mainScreen(Flat);
  default:
    FlatSelector();
  }
}


int main()
{
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  FlatSelector();

  system("pause");
  return 0;
}
