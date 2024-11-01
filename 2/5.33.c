# include <stdio.h>  
# include <string.h>  
int minimum(int l, int *p1)  
{  
    int min0 = *p1;  
    p1 = p1 + 1;  
    for (int i = 1; i < l; ++i)  
    {  
        if (*p1 < min0) min0 = *p1;  
        p1 = p1 + 1;  
    }  
    return min0;  
}  
int f(char *p)  
{  
    char c[100];  
    c[0] = '\0';  
    int count[100];  
    count[0] = 0;  
    int m;  
    int l;  
    for (int i = 0; *p != '\0'; ++i)  
    {  
        m = 0;  
        for (int j = 0; c[j] != '\0'; ++j)  
        {  
            if (c[j] == *p)   
            {  
                ++count[j];  
                ++m;  
            }  
        }  
        l = strlen(c);  
        if (m == 0)  
        {  
            count[l] = 1;  
            c[l] = *p;  
            c[l + 1] = '\0';  
        }  
        p = p + 1;      
    }  
    l = strlen(c); 
    int min = minimum(l, count);  
    char ch = c[0];  
    for (int k = 1; c[k] != '\0'; ++k)  
    {  
        if ((count[k] == min) && (ch > c[k])) ch = c[k];  
    }  
    printf("%c\n", ch);  
    printf("%d", min); 
}  
int main()  
{  
    char s[100];  
    scanf("%s", s);  
    f(s);  
}
