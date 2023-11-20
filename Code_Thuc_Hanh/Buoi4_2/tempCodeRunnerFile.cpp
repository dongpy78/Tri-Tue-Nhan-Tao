else {
        //     int mang_tam[MAX];
        //     int dem_tam = 0;
        //     for (int i = 0; i < sodinh; i++) {
        //         if (mtk[n][i] == 1 && CLOSE[i] != -1 && OPENED[i] != -1) {
        //             mang_tam[dem_tam++] = i;
        //             OPENED[i] = -1;
        //             PARENT[i] = n;
        //         }
        //     }
        //     for (int i = 0; i < dem_tam - 1; i++)
        //         for (int j = i + 1; j < dem_tam; j++)
        //             if (h[mang_tam[i]] < h[mang_tam[j]]) {
        //                 swap(&mang_tam[i], &mang_tam[j]);
        //             }
        //     for (int i = 0; i < dem_tam; i++) {
        //         OPEN[dem++] = mang_tam[i];
        //     }
        //     // printf("\nOPEN[]: ");
        //     // inmang(OPEN, dem);
        // }