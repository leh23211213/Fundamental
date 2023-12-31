#include <cmath>
#include <iostream>
#include <time.h>

using namespace std;
#define size 50

void inputArray(int Array[], int amoutOfArray);
void outputArray(int Array[], int amoutOfArray);
void sortAcsendingArray(int Array[], int amoutOfArray);
void insertElementIntoArray(int Array[], int &amoutOfArray, int insertValue,
                           int insertPosition);
void deleteElementFromArray(int Array[], int &amoutOfArray, int deletePosition);
int main() {
  system("cls");
  int amoutOfArray, Array[size];
  int option;
  int deletePosition, value, insertPosition;
rebackMenu:
  int times = 0;
  cout << " ___________________MENU ___________________" << endl;
  cout << " 1. Input and output array  " << endl;
  cout << " 2. Sort array acsending    " << endl;
  cout << " 3. Select and remove value from array    " << endl;
  cout << " 4. Insert value into array   " << endl;
  cout << " Enter '1-4' to continue with menu or press '-1' for out program .  "
          " . "
       << endl;
  do {
    cin >> option;
    if (option == -1)
      break;
    switch (option) {
    case 1:
      while (times != 5) {
        cout << " Enter amout of array  :  ";
        cin >> amoutOfArray;
        if (amoutOfArray > 0 && amoutOfArray <= size) {
          cout << " Enter array " << endl;
          inputArray(Array, amoutOfArray);
          cout << " \n here is array : " << endl;
          outputArray(Array, amoutOfArray);
          break;
        } else {
          times++;
          cout << " Invalid array length. \n ";
          cout
              << " Pleas enter amout of array a random number from 1 to 50. \n";
        }
        if (times == 3) {
          goto rebackMenu;
        }
      }
      times = 0;
      break;
    case 2:
      cout << " Array after sort acsending  : \n";
      sortAcsendingArray(Array, amoutOfArray);
      outputArray(Array, amoutOfArray);
      break;
    case 3:
      cout << " here is array : " << endl;
      outputArray(Array, amoutOfArray);
      while (times != 6) {
        cout << " Input delete position  : ";
        cin >> deletePosition;
        if (deletePosition <= 0 || deletePosition > amoutOfArray) {
          cout << " Delete position not exist , pleas try again. \n";
          times++;
        } else {
          deleteElementFromArray(Array, amoutOfArray, deletePosition);
          cout << " Array after delete value  : \n";
          outputArray(Array, amoutOfArray);
        }
        if (times == 3) {
          cout << " you entered it wrong too much times. \n";
          break;
        }
      }
      times = 0;
      break;
    case 4:
      cout << " here is array : " << endl;
      outputArray(Array, amoutOfArray);
      while (times != 6) {
        cout << " Input insert position and value  : ";
        cin >> insertPosition >> value;
        if (insertPosition < 0 || insertPosition > amoutOfArray) {
          cout << " Invalid length, pleas try again. \n";
          times++;
        } else {
          insertElementIntoArray(Array, amoutOfArray, value, insertPosition);
          cout << " Array after insert value  : \n";
          outputArray(Array, amoutOfArray);
          break;
        }
        if (times == 3) {
          cout << " You already intered too much times. \n";
          cout << " Reback to visit the menu if you want continue with this "
                  "program. \n";
          break;
        }
      }
      break;
    default:
      cout << " No have this option in menu  pleas try again . \n";
      break;
    }
  } while (option);
}
void inputArray(int Array[], int amoutOfArray) {
  srand(time(NULL));
  for (int i = 0; i < amoutOfArray; i++) {
    cout << " A[" << i << "]= ";
    Array[i] = rand() % 5 + 1;
    cout << Array[i] << " \t ";
  }
}
void outputArray(int Array[], int amoutOfArray) {
  for (int i = 0; i < amoutOfArray; i++)
    cout << Array[i] << " \t ";
  cout << endl;
}

void sortAcsendingArray(int Array[], int amoutOfArray) {
  for (int i = 0; i < amoutOfArray; i++)
    for (int j = i + 1; j <= amoutOfArray; j++) {
      if (Array[i] > Array[j])
        swap(Array[i], Array[j]);
    }
}
void insertElementIntoArray(int Array[], int &amoutOfArray, int insertValue,
                           int insertPosition) {
  amoutOfArray++;
  for (int j = amoutOfArray; j >= insertPosition; j--)
    swap(Array[j + 1], Array[j]);
  Array[insertPosition] = insertValue;
}
void deleteElementFromArray(int Array[], int &amoutOfArray, int deletePosition) {
  for (int j = deletePosition - 1; j <= amoutOfArray; j++)
    swap(Array[j], Array[j + 1]);
  amoutOfArray--;
}
