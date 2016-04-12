#include <stdio.h>
#include "Liste.h"

/* #define TRACE  */

static char * nom_module = "Liste generique" ;

/* Error */

static void ERR_vide(char *mess)
{
    printf ("\n Erreur dans la fonction %s in %s\n", mess, nom_module) ;

    exit (1) ;
}

/* Creation d'une cellule tete de liste */

static liste creer ()
{
    liste p ;

    p = (liste) malloc (sizeof (struct tete)) ;

    p->prem = p->vue = p->der = p->s = NULL ;

    return p ;
}

/* Destruction d'une liste */

static void detruire (liste l, void (*det_obj) (void *))
{
    l->vue = l->prem ;
    while (l->vue)
    {
    (*det_obj) (l->vue->objet) ;
    l->prem = l->vue ;
    l->vue = l->vue->suiv ;
    free (l->prem) ;
    }
    l->prem = l->der = l->s = NULL ;
}

/* Test d'une liste vide */

static int nulle (liste l)
{
    return (NULL == l->prem) ;
}

/* Test de fin de liste */

static int fin (liste l) 
{
    return (NULL == l->vue) ;
}

/* Positionne la vue en premiere position */

static void premier (liste l)
{
    l->vue = l->prem ;
}

/* Positionne la vue en derniere position */

static void dernier (liste l) 
{
    l->vue = l->der ;
}

/* Positionne la vue sur l'element suivant */

static void suivant (liste l)
{
    if (l->vue)
    l->vue = l->vue->suiv ;
    else ERR_vide("suivant") ;
}

static cellule precedent (liste p)
{
    cellule q ;

    q = p->prem ;

#ifdef TRACE
printf ("prem : %x vue : %x\n", p->prem, p->vue ) ;
#endif
    if (q == p->vue) 
    return (NULL) ;
    else
    while (q->suiv != p->vue)
    {
#ifdef TRACE
printf ("Recherche = prem : %x vue : %x\n", p->prem, p->vue ) ;
#endif
        q = q->suiv ;
    }
   return q ;
}


/* Ajout d'un objet avant la vue */

static void insereravant (liste l, void * obj)
{
    cellule p, s ;

    p = (cellule) malloc (sizeof (struct cell)) ;
    p->objet = obj ; p->suiv = NULL ;

    if (!l->prem)
    l->prem = l->der = p ;
    else
    if (!l->vue)             /* insertion en derniere pos */
        l->der = l->der->suiv = p ;
    else 
    {
        s = precedent (l) ;
        if (s)
        s->suiv = p ;
        else 
        l->prem = p ;
        p->suiv = l->vue ;
    }
    l->vue = p ;
}


static void insererapres (liste l, void * obj)
{
    cellule p, s ;

#ifdef TRACE
printf ("Je vais insererapres\n") ;
#endif
    p = (cellule) malloc (sizeof (struct cell)) ;
    p->objet = obj ; p->suiv = NULL ;

    if (!l->prem)               /* liste vide */
    {
#ifdef TRACE
printf ("Premier = obj : %x prem : %x\n", obj, l->prem) ;
#endif
    l->prem = l->der = p ;
    }
    else
    {
    s = l->vue->suiv ;
#ifdef TRACE
printf ("vue : %x, s : %x \n", l->vue, s) ;
#endif
    if (!s)                   /* placer a la fin */
    {
        l->der = p ;
    }
    else
    {
        p->suiv = l->vue->suiv ;
    }
    l->vue->suiv = p ;   
    }
    l->vue = p ;
#ifdef TRACE
printf ("apres ins = prem : %x vue : %x der : %x\n", l->prem, l->vue, l->der ) ;
#endif
}

/* Remplacement d'un objet */

static void remplacer (liste l, void *obj, void (*det_obj) (void *))
{
    if (!l->vue)
    ERR_vide("remplacer") ;
    (*det_obj) (l->vue->objet) ;
    l->vue->objet = obj ;
}

/* Suppression d'une cellule */

static void oter (liste l, void (*det_obj) ())
{
    cellule s, q ;

    if (l->vue)
    {
    q = l->vue ;
    if (l->vue == l->prem)
    {
        l->vue = l->prem = (l->vue)->suiv ;    /* !!! */
        if (!l->vue) l->der = NULL ;
    }
    else
    {
        s = precedent (l) ;
        s->suiv = (l->vue)->suiv  ;          /* !!! */
        if (l->vue == l->der)
        l->der = l->vue = s ;
        else
        l->vue = l->vue->suiv ;
    }

    (*det_obj) (q->objet) ; free (q) ;
    }
    else ERR_vide ("oter") ;
}

/* Lecture d'un objet */

static void * lire (liste l)
{
    if (l->vue)
    return l->vue->objet ;
    else
    ERR_vide ("lire") ;
}

/* Sauvegarde de la position de la vue */

static void fixer (liste l)
{
    cellule n ;

    n = (cellule) malloc (sizeof (struct cell)) ;
    n->objet = l->vue ; n->suiv = l->s ; l->s = n ;
}

/* Retablissement de la vue sur la derniere sauvegarde */

static int retablir (liste l) 
{
    cellule q ;

    if (l->s)
    {
    q = l->s ;
    l->s = l->s->suiv ;
    l->vue = q->objet ; free (q) ;
    return 1 ;
    }
    return 0 ;
}

/* Affichage d'une liste  */

static void afficher (liste l, void (*afic) (void *))
{
    cellule p = l->prem ;

    printf ("(") ;

    while (p) 
    {
    (*afic) (p->objet) ;
    if (p->suiv) printf (", ") ;
    p = p->suiv ;
    }
    
    printf (")\n") ;
}

void * lier_liste () 
{
    Liste.creer        = &creer        ;
    Liste.copier       = 0             ;
    Liste.detruire     = &detruire     ;
    Liste.nulle        = &nulle        ;
    Liste.premier      = &premier      ;
    Liste.dernier      = &dernier      ;
    Liste.suivant      = &suivant      ;
    Liste.fin          = &fin          ;
    Liste.lire         = &lire         ;
    Liste.insereravant = &insereravant ;
    Liste.insererapres = &insererapres ;
    Liste.remplacer    = &remplacer    ;
    Liste.oter         = &oter         ;
    Liste.fixer        = &fixer        ;
    Liste.retablir     = &retablir     ;
    Liste.afficher     = &afficher     ; 
}
