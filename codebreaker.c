#include <stdio.h>  //pour printf()
#include <time.h>   //pour time()
#include <stdlib.h> //pour srand()
 
#define SIZE        50
#define SIZE_CARPOS 64
 
typedef unsigned int uint;
 
int main(void)
{
 FILE* fichier = fopen("wword_list2.txt", "w+");
 fseek(fichier, 0, SEEK_END);
  for (int i = 0; i < 1073741824; i++)
 {
    int     i = 0;
    char    mdp[8],      //l'allocation dynamique serait plus propre, mais tu ne l'as pas encore vue
            testMDP[8],  //chaîne qui servira à essayer les différents mots de passe
            carPossibles[10] = "1234567890";
 
    //génération aléatoire du mot de passe
    srand((uint)time(NULL));    //pour générer les nombres aléatoires
 
    for(i = 0; i < 8 - 1; ++i)   //pour chaque case du tableau :
    {
        int tmp = rand() % (11 - 1);    //générer un nombre aléatoire
        mdp[i] = carPossibles[tmp]; //assigner à la case du mdp le caractère aléatoire
    }
    mdp[8 - 1] = '\0';   //pour terminer la chaîne du mdp
 
    //découverte du mot de passe
    for(i = 8 - 1; i >= 0; --i)   //on explore testMDP de sa dernière case jusqu'à la première
    {
        int tmp = 0;
        while(mdp[i] != testMDP[i]) //tant que la case 'i' de la chaîne n'est pas la bonne
        {
            testMDP[i] = carPossibles[tmp]; //on change sa valeur par la suivante de carPossibles
            ++tmp;
            fprintf(fichier, "%s\n", testMDP); 
        }
    }
       //affichage du mot de passe trouvé
   }
    return EXIT_SUCCESS;
}