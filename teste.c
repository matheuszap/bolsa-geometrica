// #include <stdio.h>
// #include <stdlib.h>


// int main () {
//     char * fds1;
//     char * fds2;
//    FILE * fp;

//    fp = fopen ("teste.txt", "r");
   
//     if (!fscanf(fp, "%s", fds1)) {
// 						printf ("ERRO\n");
// 						return 1;
// 				}
// 	// Linha 2 do arquivo
// 	if (!fscanf(fp, "%s", fds2)) {
// 						printf ("ERRO\n");
// 						return 1;
// 				}

//    printf("teste%s",fds1);
//    printf("teste%s",fds2);

//    fclose(fp);
   
//    return(0);
// }



#include <stdio.h>
#include <stdlib.h>


int main () {
   char str1[256], str2[256];
   int year;
   FILE * fp;

   fp = fopen ("teste.txt", "r");
   
   rewind(fp);
   fscanf(fp, "%s", &str1);
   fscanf(fp, "%s", &str2);
   
   printf("Read String1 |%s|\n", str1 );
   printf("Read String2 |%s|\n", str2 );

   fclose(fp);
   
   return(0);
}