#include <stdio.h> 
int Pmax = 500;
int P[] = {100, 350, 250, 120, 200, 50, 80, 135, 320}; // trong luong cua vat
int w[] = {50, 70, 160, 200, 140, 100, 25, 120, 400}; // gia tri  cua do vat
int n = sizeof(w) / sizeof(w[0]); // lay so luong cua tung gia tri 

int cs[100];
int flag[100];

void sap_xep() {
  for(int i = 0; i < n; i++) cs[i] = i; // chi so vat
  // sap xep
  for(int i = 0; i < n-1; i++)
    for(int j = i + 1; j < n; j++)
      if((float)(w[cs[j]]/P[cs[j]]) > (float)(w[cs[i]]/P[cs[i]])) {
        int tam = cs[i]; cs[i] = cs[j]; cs[j] = tam;
      }
}

void lay_vat() {
  int S = 0;
  for(int i = 0; i < n; i++) {
    if(S+P[cs[i]] <= Pmax) {
      S = S+P[cs[i]];
      flag[cs[i]] = 1;
    }
  }
}

void In_kq() {
  int gt = 0; int tt = 0;
  printf("\nKet qua chon cac vat sau: \n");
  for(int i = 0; i < n; i++)
    if(flag[cs[i]] == 1) {
      printf("\n vat thu = %2d, the tich = %4d, gia tri = %4d", cs[i], P[cs[i]], w[cs[i]]);
      gt = gt+w[cs[i]];
      tt = tt + P[cs[i]];      
    }
    printf("\nTong the tich cac vat = %d, tong gia tri = %d", tt, gt);
}


int main() { 
  sap_xep();
  lay_vat();
  In_kq();
  return 0;
}