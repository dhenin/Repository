#include "File.tda"

typedef char * lettre ;


void lettre_editer (lettre i) 
{
    printf ("%c", *i) ;
}

lettre lettre_copier (lettre i)
{
    lettre j ;
    j = (lettre) malloc (sizeof (*i)) ;
    *j = *i ;
    return j ; 
}

void lettre_detruire (lettre i)
{
    free (i) ; 
}

file (lettre) ;    /* utilise les  definitions ci-dessus */

void main ()
{
    lettrefile p ; int i ; lettre x ;

    p = lettrefile_creer(lettre_copier, lettre_detruire, lettre_editer) ;

    for (i = 65 ; i < 70 ; i++)
    {
        x = lettre_copier   ((lettre) &i) ;
        lettrefile_enfiler  (p, x)        ;
        lettrefile_afficher (p)           ;   
    }

    for (i = 0 ; i < 5 ; i++)
    {
        lettrefile_desenfiler (p) ;
        lettrefile_afficher   (p) ;   
    }
}
