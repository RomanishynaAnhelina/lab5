#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

class Conditioner
{
public:
  Conditioner(const char* set_Model)
  {
    Model = new char[strlen(set_Model) + 1];
    strcpy(Model, set_Model);
    Name = 0;
  }
  virtual ~Conditioner()
  {
    if (Name != 0)
    {
      delete[] Name;
    }
    if (Model != 0)
    {
      delete[] Model;
    }
  }
  virtual char* Mode() = 0;
  virtual void setMode(bool k) = 0;
  virtual bool Status()
  {
    return IsWork;
  }
protected:
  char* Name;
  char* Model;
  bool IsWork = 0;
};

class ClimateControl : public Conditioner
{
public:
  ClimateControl(const char* set_Model, const char* set_Name) : Conditioner(set_Model)
  {
    IsWork = 0;
    Name = new char[strlen(set_Name) + 1];
    strcpy(Name, set_Name);
  }
  virtual ~ClimateControl()
  {

  }
  virtual void Set_Temperature(int Temperature)
  {
    this->Temperature = Temperature;
  }
  virtual char* Mode()
  {
    char* curMode = new char[10];
    if (mode == 0)
    {
      strcpy(curMode, "Colling");
    }
    else
    {
      strcpy(curMode, "Heating");
    }
    return curMode;
  }
  virtual void setMode(bool k)
  {
    mode = k;
  }
  virtual int Get_Temperature()
  {
    return Temperature;
  }
private:
  int Temperature = 0;
  bool mode = 0;
};



int main()
{

    setlocale(LC_ALL, "Russian");
    ClimateControl Control("Samsung", "Control1");
    Control.Set_Temperature(25);
    Control.setMode(1);

  cout << "Поточна температура: " << Control.Get_Temperature() << endl;
  cout << "Поточний режим: " << Control.Mode() << endl;
  system("pause");
  return 0;
}

