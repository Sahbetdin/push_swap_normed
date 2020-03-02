#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// int main()
// {
//     char *cc;
//     char *str;

//     str = (char *)malloc(sizeof(char) * 2);
//     str[1]= '\0';

//     str[0] = 1 + '0';

//     cc = strcat("\"ARG=\"", str);
// return (0);
//     printf("%s\n", cc);
// //    system("ARG=\"1 2 4 3 5\"; ./push_swap $ARG | ./checker $ARG");
//     free(str);
//     // free(cc);
//     return (0);
// }




// int main()
// {
//    int i;
//    char buf[12];

//    for (i = 1; i < 4; i++) {
//       snprintf(buf, 12, "\"ARG=\" %d_suff", i); // puts string into buffer
//       printf("%s\n", buf); // outputs so you can see it
//    }
// }


void swap(char *x, char *y) 
{ 
    char temp; 
    temp = *x; 
    *x = *y; 
    *y = temp; 
} 
  
/* Function to print permutations of string 
   This function takes three parameters: 
   1. String 
   2. Starting index of the string 
   3. Ending index of the string. */
void permute(char *a, int l, int r) 
{ 
   int j; 
   int i;
   char buf[55];


   if (l == r)
   {
	   snprintf(buf, 55, "ARG=\"%c %c %c %c %c\"; ./push_swap $ARG | ./checker $ARG", a[0], a[1], a[2], a[3], a[4]); 
    //  printf("%c %c %c %c %c\n", a[0], a[1], a[2], a[3], a[4]);
	system(buf);
    //   printf("%s\n", buf); // outputs so you can see it

   }
   else
   { 
       for (j = l; j <= r; j++) 
       { 
          swap((a+l), (a+j)); 
          permute(a, l+1, r);
          swap((a+l), (a+j)); //backtrack 
       } 
   } 
} 
  
/* Driver program to test above functions */
int main() 
{ 
    char str[] = "12345"; 
    int n = strlen(str); 
    permute(str, 0, n-1); 
    return 0; 
} 
