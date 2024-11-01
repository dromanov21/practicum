# include <stdio.h>  
int G(int n, int m, int *p)  
{  
    int elemi; 
    int elem0; 
    for (int j = 0; j < n; ++j) 
    { 
        elem0 = *p; 
        for (int i = 1; i < m; ++i)  
        {  
            p = p + 1; 
            elemi = *p; 
            p = p - 1; 
            *p = elemi; 
            p = p + 1;  
        } 
        *p = elem0; 
        p = p - m + 1; 
    } 
     
    return 0;  
}  
int main()  
{  
    int m;  
    printf("%s", "Введите длину массива: ");  
    scanf("%d", &m);  
    int n; 
    printf("%s", "Введите количество сдвигов: ");  
    scanf("%d", &n);  
    int s[m];  
    printf("%s", "Введите элементы массива: ");  
    for (int i = 0; i < m; ++i)  
        scanf("%d", &s[i]);  
    G(n, m, s);  
    for (int k = 0; k < m; ++k) 
    { 
        printf("%d ", s[k]); 
    } 
}
