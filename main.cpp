#include <iostream>
using namespace std;

class SmartArray
{
  int* elem;
  int size = 0;
  public:
 SmartArray(int s = 0)
 {
  if(s < 0)
  {
    throw "Размер не может быть меньше 0, значение установлено на 0.";
    s = 0;
  }
  elem = new int[s];
  for(int i = 0; i < s; i++)elem[i] = 0;
  size = s;
 }
 int& operator[](int i){return elem[i];};
 void push(int b)
 {
  if(size >= 0)
  {
    int* tempelem;
    tempelem = new int[size + 1];
    for(int i = 0; i < size; i++)tempelem[i] = elem[i];
    tempelem[size] = b;
    size++;
    delete[] elem;
    elem = tempelem;
  }
 }
 int getsize(){return size;}
 void pop()
 {
   int* tempelem;
    tempelem = new int[size -1];
    for(int i = 0; i < size-1; i++)tempelem[i] = elem[i];
    size--;
    delete[] elem;
    elem = tempelem;
 }
  SmartArray& operator=(SmartArray& arr)
  {
    if (elem) delete[] elem;
    size = arr.getsize();
    elem = new int[size];
    for (int i = 0; i < size; i++) elem[i] = arr.elem[i];
    return *this;
  }
 SmartArray& operator+(SmartArray& arr)
  { 
    int sizen = arr.getsize() + size;
    int* tmpelem = new int[sizen];
    for(int i = 0; i < size; i++)tmpelem[i] = elem[i];
    for(int i = 0; i < arr.getsize(); i++)tmpelem[i + size] = arr[i];
    delete[] elem;
    size = sizen;
    elem = tmpelem;
    return *this;
  }
 friend ostream& operator<<(ostream& os, SmartArray& arr)
 {
    os << '[' << arr[0];
    for(int i = 1; i < arr.getsize(); i++)
    {
      os << ", " << arr[i];
    }
    os << ']' << std::endl;
    return os;
 }
 SmartArray(SmartArray& source)
 {
   size = source.getsize();
   elem = new int[size];
   for (int i = 0; i < size; i++)elem[i] = source.elem[i];
 }
  ~SmartArray()
  {
    if(elem)delete[] elem;
  }
};


int main()
{
  try
  {
  SmartArray sa1(5);
  sa1[2] = 500;
  sa1.push(4);
  std::cout << "sa1[2] = " << sa1[2] << std::endl;
  std::cout << "sa1 = " << sa1;
  sa1.pop();
  std::cout << "sa1 = " << sa1;
  SmartArray sa2(sa1);
  sa2[1] = 2;
  std::cout << "sa1 = " << sa1;
  std::cout << "sa2 = " << sa2;
  SmartArray sa3;
  sa3.push(2);
  std::cout << "sa3 = " << sa3;
  SmartArray sa4(10);
  sa4 = sa1;
  std::cout << "sa4 = " << sa4;
  SmartArray sa5;
  SmartArray sa6;
  SmartArray sa7;
  sa5.push(1);
  sa6.push(2);
  std::cout << "sa5 = " << sa5;
  sa7 = sa5 + sa6;
  std::cout << "sa6 = " << sa6;
  std::cout << "sa7 = " << sa7;
  }
  catch(const char *ex)
  {
    std::cout << ex << endl;
  }
}
