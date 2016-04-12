#include "Pile.tda"

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

pile (lettre) ;    /* utilise les  definitions ci-dessus */

void main ()
{
    lettrepile p ; int i ; lettre x ;

    p = lettrepile_creer(lettre_copier, lettre_detruire, lettre_editer) ;

    for (i = 65 ; i < 70 ; i++)
    {
    x = lettre_copier   ((lettre) &i) ;
        lettrepile_empiler  (p, x)        ;
        lettrepile_afficher (p)           ;   
    }

    for (i = 0 ; i < 5 ; i++)
    {
        lettrepile_desempiler (p) ;
        lettrepile_afficher   (p) ;   
    }
}
