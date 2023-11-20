

// void BestFirshSearch(int start, int goal) {
//   int n;
//   int OPEN[MAX];
//   int CLOSE[MAX];
//   int OPENED[MAX];
//   int Tn[MAX]; 

//   for(int i = 0; i < sodinh; i++) {
//     CLOSE[i] = i;
//     OPENED[i] = i;
//     Tn[i] = -1; 
//   }

//   int dem = 0; 
//   OPEN[dem++] = start;
  
//   while (dem > 0) {
//     n = OPEN[--dem];
//     CLOSE[n] = -1;
//     OPENED[n] = -1;    

//     if(n == goal) {
//       printf("\nTim thay duong di tu %d den %d: ", start, goal);
//       // In ra đường đi từ start đến goal
//       int path[MAX];
//       int count = 0;
//       int current = goal;
//       while (current != start) {
//         path[count++] = current;
//         current = Tn[current];
//       }
//       path[count++] = start;
//       for (int i = count - 1; i >= 0; i--) {
//         printf("%d", path[i]);
//         if (i > 0) {
//           printf(" -> ");
//         }
//       }
//       break;
//     }
//     else {
//       for(int i = 0; i < sodinh; i++) {
//         if(mtk[n][i] == 1 && OPENED[i] != -1 && CLOSE[i] != -1) {
//           OPEN[dem++] = i;
//           OPENED[i] = -1;
//           Tn[i] = n; 
//         }
//       }               
//     }
//   }  
// printf("Khong tim thay duong di");
// }