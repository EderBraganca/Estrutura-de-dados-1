# ifndef presente_h
    # define presente_h

typedef struct{
    double i, h, w, l, v; 
} Gift;

typedef struct{
    int k, n;
} Kn;

Gift* readGifts(int n);
void print(Gift* gift, int n, int k);
void quickSort(Gift* gift, int n, int r);
int partition(Gift* gift, int n, int r);
void quickSort2(Gift* gift, int n, int r);
int partition2(Gift* gift, int n, int r);
int switx(Gift *gift, int n, int r);
# endif