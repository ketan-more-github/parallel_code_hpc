#include<stdio.h>


int main()
{
    int a[3][3];
    int b[3][3];
    int result[3][3]; 
    int sum = 0;
      printf("Enter the  1st 2x2 matrix element\n");
      for(int i =1;i<=2;i++)
        {

          for(int j =1;j<=2;j++)
            {
              scanf("%d" , &a[i][j]);
            }
        }
        
        printf("Enter the  2st 2x2 matrix element\n");
      for(int i =1;i<=2;i++)
        {

          for(int j =1;j<=2;j++)
            {
              scanf("%d" , &b[i][j]);
            }
        }
        
        //perform mult
        
        
         for(int i =1;i<=2;i++)
        {

          for(int j =1;j<=2;j++)
            {
              for(int k =1;k<=2;k++){
                  sum += a[i][k] * b[k][j];       
            
               }
               result[i][j] = sum;
               sum = 0;
            }
        }
        
        //printing
        
        for(int i =1;i<=2;i++)
        {

          for(int j =1;j<=2;j++)
            {
              printf("%d" , result[i][j]);
            }
        }

 
return 0;

}
