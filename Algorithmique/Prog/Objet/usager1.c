/* Ecp -- 1ere Annee -- 
 * jjd                        Liste1.c
 */
#include "Liste.tda"
typedef int  *entier ;     /* Creation du nouveau type pointeur sur int */
liste(entier) ;

/* fonctions particulieres au nouveau type */

void entier_editer(entier i)
{ printf("%d", *i) ; }

entier entier_copier(entier i)
{
    entier      j ;
    j = (entier) malloc(sizeof(*i)) ;
    *j = *i ;
    return j ;
}

void main()
{
    entierliste   l ;
    entier        x ;
    int           i ;

/* Instanciation */
    l = entierliste_creer(entier_copier, 0, entier_editer) ;

    for (i = 0 ; i < 5 ; i++)
    {
        x = entier_copier((entier) & i)         ;
        entierliste_insererapres(l, (entier) x) ;
    }
    entierliste_afficher(l) ;
}
