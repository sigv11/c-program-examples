/*
 * fact.c - find factorial of a number
 */
 #include <stdio.h>
 #include <assert.h>

 long long fact(int num)
 {
   long long fact = 1;

   if(num == 0) {
     return fact;
   }

   do {
     fact = fact * num;
   } while(--num);

   return fact;
 }

 int main()
 {
   int num;

   printf("Enter a positive number: ");
   scanf("%d", &num);

   assert(num >= 0);

   printf("Factorial of %d is %lld\n", num, fact(num));

   return 0;
 }
