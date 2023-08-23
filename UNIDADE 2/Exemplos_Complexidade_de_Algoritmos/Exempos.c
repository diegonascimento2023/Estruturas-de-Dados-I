#include <stdio.h>
/*
int soma(int n){
    int i; // 1 vez: c1
    int soma = 5; // 1 vez: c2
    for ( i = 1; i <= n; i++) // n  vezes: n*c3
    {
        soma = soma + i; // n vezes: n*c4
    }

    return soma; // 1 vez: c5

}

//T(n) = c1 + c2 + n*c3 + n*c4 + c5 : Tempo de execução da função
//T(n) = n(c3 + c4) +  c1 + c2 + c5 : c3 + c4 = a / c1 + c2 + c5 = b
//T(n) = an + b
*/

/*int Max(int arr[], int n){
    int i; // 1 vez: c1
    int max = arr[0]; // 1 vez: c2
    for ( i = 1; i < n; i++) // n  vezes: (n - 1)*c3
    {
        if (arr[i] > max) // n  vezes: (n - 1)*c4
        {
            max = arr[i]; // n  vezes: (n - 1)*c5
        }

    }

    return max; // 1 vez: c6
}

  //T(n) = c1 + c2 + (n - 1)*c3 + (n - 1)*c4 +(n - 1)*c4 + n*c5 + c6 : Tempo de execução da função
  //T(n) = (n - 1)(c3 + c4 + c5) +  c1 + c2 + c6 : (c3 + c4 + c5 = a) / (c1 + c2 + c6 = b)
  //T(n) = a(n - 1) + b
  */

/*
 int multsuma(int n){
    int i, j; // 1 vez: c1
    int soma; // 1 vez: c2
    for ( i = 1; i <= n; i++) // n  vezes: n*c3
    {
        for ( j = 1; j <= n; j++){ // n*n ou n² vezes: n*n c4
        soma = soma + i*j; // n*n ou n² vezes: n*c5
        }
    }

    return soma; // 1 vez: c5

}

//T(n) = c1 + c2 + (n)*c3 + (n²)*c4 +(n²)*c5 + c6 : Tempo de execução da função
  //T(n) = (n²)( c4 + c5) + n(c3) c1 + c2 + c6 : ( c4 + c5 = a) / (c1 + c2 + c6 = c) / c3 = b
  //T(n) = an² + bn + c */

  /*void insertionsort(int arr[], int n){
    int i, key, j; // 1 vez: c1
    for ( i = 1; i < n; i++) // n -1   vezes:(n - 1)*c2
    {
        key = arr[i];  // n -1   vezes: (n - 1)*c3
        j = i - 1;  // n - 1   vezes:(n - 1)*c4
        while ( j >= 0 && arr[j] > key) // (n - 1)²   vezes: n²*c5
        {
            arr[j + 1] = arr[j]; // (n - 1)²   vezes: n²*c6
            j = j + 1; // (n - 1)²  vezes: n²*c7

        } 
        arr[ j + 1] = key; // n - 1   vezes: (n - 1)*c8
        
           
        } 
    }
*/

//T(n) = c1 + (n - 1)*c2 + (n - 1)*c3 + (n - 1)*c4  + (n²)*c5 + (n²)*c6 + (n²)*c7 + (n - 1)*c8: Tempo de execução da função
  //T(n) = ((n - 1²)( c5 + c6 + c7) + (n - 1)(c2 + c3 + c4 + c8) + c1  : ( c5 + c6 + c7 = a) / (c2 + c3 + c4 + c8 = c) / c1 = b
  //T(n) = a(n - 1)² + bn + c

/*int soma(int n){
    int i; // 1 vez: c1
    int soma = 0; // 1 vez: c2
    while ( i <= n) // n  vezes: n*c3
    {
        soma = soma + i; // n vezes: n*c4
        i++; // 1 vez: c5

    }

    return soma; // 1 vez: c6

}
*/
// T(n) = c1 + c2 + c3*n + c4*n + c5*n + c6
// T(n) = n(c3 + c4 + c5) + c1 + c2 + c6
// T(n) = n*a + b

// O(n)
/*
void boubblesort(int arr[], int n){
    int i, j; // 1 vez: c1
    for ( i = 0; i < n - 1; i++) // n - 1   vezes:(n - 1)*c2
    {
       for ( j = 0; j < n - i - 1; j++) // n - ( n- 1) - 1   vezes:(n²)*c2
    {
       if(arr[j] > arr[j + 1]){
        swap(&arr[j], &arr[j + 1]);
       }
           
        } 
           
        } 
    }*/

    //O(n²)