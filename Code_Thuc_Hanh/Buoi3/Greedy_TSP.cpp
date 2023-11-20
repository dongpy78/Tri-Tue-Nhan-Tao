// #include <stdio.h>
// #define INPUT "input.txt"
// #define MAX 100

// // bien toan cuc 
// FILE *fp;
// int sodinh;
// int chiphi[MAX][MAX];

// void inmt(int mt[][MAX], int size) {
//   for(int i = 0; i < size; i++) {
//     printf("\n");
//     for(int j = 0; j < size; j++) 
//       printf("%5d", mt[i][j]);    
//   } 
// }

// void readfile() {
//   fp = fopen(INPUT, "r");
//   if (fp == NULL) {
//     printf("File not found");
//     return; 
//   } else {
//     fscanf(fp, "%d", &sodinh);
//     for(int i = 0; i < sodinh; i++)
//       for(int j = 0; j < sodinh; j++) 
//         fscanf(fp, "%d", &chiphi[i][j]);      
//     fclose(fp);
//   }
//  // in ra cac gia tri 
//  printf("\nSo dinh cua do thi : %d", sodinh);
//  printf("\nChi phi di lai giua cac thanh pho: \n");
//  inmt(chiphi, sodinh);
// }

// void Greedy_TSP(int start) {
//   int n = start;
//   int dem = 0;
//   while (dem < sodinh ) {
//     for(int i = 0; i < sodinh; i++) {
//       // Tim MIN cua cac dinh ke voi n

//     }

//     dem++;
//   }  
// }

// int main() {
//   readfile();
//   return 0;
// }


#include <iostream>
#include <fstream>
#define INPUT "input1.txt"
#define MAX 100
#include <limits.h>

using namespace std;

// Global variables
ifstream fp;
int sodinh;
int chiphi[MAX][MAX];

void inmt(int mt[][MAX], int size) {
  for(int i = 0; i < size; i++) {
    cout << endl;
    for(int j = 0; j < size; j++) 
      cout << mt[i][j] << " ";    
  } 
}

void readfile() {
  fp.open(INPUT);
  if (!fp) {
    cout << "File not found";
    return; 
  } else {
    fp >> sodinh;
    for(int i = 0; i < sodinh; i++)
      for(int j = 0; j < sodinh; j++) 
        fp >> chiphi[i][j];      
    fp.close();
  }
  
  // Print values
  cout << "So dinh cua do thi: " << sodinh << endl;
  cout << "Chi phi di lai giua cac thanh pho: " << endl;
  inmt(chiphi, sodinh);
}

void inmang(int m[], int size) {
  for(int i = 0; i < size; i++) cout << m[i] << " ";
}

void Greedy_TSP(int start) {
  int CLOSE[MAX];
  int n = start;
  int dem = 0; 
  int path[MAX];

  cout << endl;
  cout << "Dinh xuat phat: " << n << endl;
  
  for(int i = 0; i < sodinh; i++) CLOSE[i] = i;

  CLOSE[n] = -1;
  
  cout << "CLOSE[]" << "  ";
  inmang(CLOSE, sodinh);

  // luu lai thu tu dinh da duyet
  path[dem] = n;

  while (dem < sodinh - 1) {
    int MIN = INT_MAX;
    int pos; // luu giu chi phi la min
    // cout << "MIN = " << MIN << endl;
    for(int i = 0; i < sodinh; i++) {
      // Tim MIN cua cac dinh ke voi n
      if(i != n && MIN > chiphi[n][i] && CLOSE[i] != -1) {
        MIN = chiphi[n][i];
        pos = i;
      }
    }
    // gan dinh ke tiep la dinh co pos = min
    n = pos;
    path[++dem] = n;
    CLOSE[n] = -1;
    cout << "Dinh ke tiep: " << n << endl;
    cout << "CLOSE[]" << "  ";
    inmang(CLOSE, sodinh);
  }  
  cout << endl;
  cout << "\nDuong di: "; inmang(path, sodinh);  
}

int main() {
  readfile();
  Greedy_TSP(0);
  return 0;
}



