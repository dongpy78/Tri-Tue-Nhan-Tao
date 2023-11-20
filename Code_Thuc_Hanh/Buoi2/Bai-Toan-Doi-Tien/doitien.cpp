#include <iostream>
using namespace std;
int A = 390;
int n = 10;
int a[] = {200, 100, 100, 50, 50, 50, 50, 20, 20, 10};
int flag[20];
int P;

void doi_tien() {
  int i = 0;
  while ((P > 0) && (i < n)) {
    if(P >= a[i]) {
      flag[i] = 1;
      P = P - a[i];
    }
      i = i+1;
  }
}

int main() {
  system("cls");
  P = A;
  doi_tien();
  if(P != 0) cout << "Khong doi duoc tien! " << endl;
  else {
    cout << "Ket qua chuyen doi: " << endl;
    for(int j = 0; j < n; j++) 
      if(flag[j] == 1) cout << "  " << a[j];    
  }
  return 0;
}