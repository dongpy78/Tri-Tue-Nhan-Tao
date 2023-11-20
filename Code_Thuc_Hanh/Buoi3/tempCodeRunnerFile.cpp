n = pos;
    path[++dem] = n;
    CLOSE[n] = -1;
    cout << "Dinh ke tiep: " << n << endl;
    cout << "CLOSE[]" << "  ";
    inmang(CLOSE, sodinh);