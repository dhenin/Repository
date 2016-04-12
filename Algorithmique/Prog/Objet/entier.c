#include "Liste.tda"

typedef int * entier ;


void entier_editer (entier i) 
{
    printf ("%d", *i) ;
}

void entier_detruire (entier i)
{
    free (i) ; 
}

entier entier_copier (entier i)
{
    entier j ;

    j = (entier) malloc (sizeof (*i)) ;
    *j = *i  ;

    return j ;
}

liste(entier) ;

void main ()
{
    entierliste l ; int i ; entier x ;

    l = entierliste_creer (entier_copier,
                           entier_detruire,
                           entier_editer) ;

    for (i = 10 ; i < 15 ; i++)
    {
        x = entier_copier   (&i)   ;
        entierliste_insereravant (l, x) ;
        entierliste_afficher     (l)    ;   
    }

    for (i = 0 ; i < 5 ; i++)
    {
        x = entier_copier   (&i)   ;
        entierliste_insererapres (l, x) ;
        entierliste_afficher     (l)    ;   
    }

    printf ("\nl = ") ;
    entierliste_afficher (l) ;

    printf ("Element courant : ") ;
    entier_editer (entierliste_lire(l)) ; printf ("\n") ;
    entierliste_suivant(l) ;
    printf ("Element suivant : ") ;
    entier_editer (entierliste_lire(l)) ; printf ("\n") ;
    entierliste_premier(l) ;
    printf ("Element premier : ") ;
    entier_editer (entierliste_lire(l)) ; printf ("\n") ;
    entierliste_suivant(l) ;
    printf ("Element deuxieme : ") ;
    entier_editer (entierliste_lire(l)) ; printf ("\n") ;
    entierliste_dernier(l) ;
    printf ("Element dernier : ") ;
    entier_editer (entierliste_lire(l)) ; printf ("\n") ;
}
