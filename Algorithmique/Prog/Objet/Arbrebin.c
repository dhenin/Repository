static char * nom_module = "arbre binaire" ;

typedef struct noeud 
{
    void         * objet                   ;
    struct noeud * gauche, * droit, * pere ;
} * noeud ;

struct csvg 
{
    noeud         svue  ;
    struct csvg * sprec ;
} ;

typedef struct tete
{
    noeud         racine, vue ;
    struct csvg * svg         ;
} * arbrebin ;

typedef enum {racine, pere, gauche, droite} direction ;

struct 
{
    arbrebin (*creer)     ()                                    ;
    void     (*detruire)  (arbrebin, void (*) (void *))         ;
    int      (*existe)    (arbrebin, direction)                 ;
    void *   (*lire)      (arbrebin)                            ;
    int      (*aller)     (arbrebin, direction)                 ;
    void     (*ajouter)   (arbrebin, direction, void *)         ;
    int      (*oter)      (arbrebin)                            ;
    void     (*remplacer) (arbrebin, void *, void (*) (void *)) ;
    void     (*fixer)     (arbrebin)                            ;
    int      (*retablir)  (arbrebin)                            ;
    void     (*afficher)  (arbrebin, void (*) (void *))         ;
    void     (*deplacer)  (arbrebin, direction)                 ;
    void     (*greffer)   (arbrebin, arbrebin, direction)       ;
    arbrebin (*tailler)   (arbrebin, direction)                 ;
} Arbrebin ;

static arbrebin creer ()
{
    arbrebin r ;

    r = (arbrebin) malloc (sizeof (struct tete)) ;
    r->racine = r->vue : r->svg = NULL           ;

    return r ;
}

static void detruire (arbrebin r, void (*det_obj) (void *))
{
    noeud x ;
    r->vue = r->racine ;

    while (r->vue)
    {
        while (r->vue->gauche)
            r->vue = r->vue->gauche ;
        while (!r->vue->droite)
        {
            x = r->vue ;
            if (r->pere)
            r->vue = r->pere ;
            else
            {
                (*det_obj) (x->objet)     ;
                free (x)                  ;
                r->vue = r->racine = NULL ;
                return                    ;
            }
            (*det_obj) x->objet) ;
            free (x)             ;
        }
        x = r->vue->droite    ;
        r->vue->droite = NULL ;
        r->vue = x            ;
    }
}

static int existe (arbrebin r, direction d)
{
    switch (d)
    {
    case racine : return (r->racine ? 1           : 0) ;
    case gauche : return (r->vue ? r->vue->gauche : 0) ;
    case droite : return (r->vue ? r->vue->droite : 0) ;
    case pere   : return (r->vue ? r->vue->pere   : 0) ;
    }
}

static void * lire (arbrebin r)
{
    if (!r->vue) { ERR_objet ("lire") ; return NULL ; }
    return r->vue->objet ;
}

static int aller (arbrebin r, direction d)
{
    switch (d)
    {
    case recine : r->vue     = r->racine ; return 1 ;
    case gauche : if (!r->vue) {ERR_vue ("aller") ; return 0 ;
              if (r->vue->gauche) 
              {   r->vue = r->vue->gauche ; return 1 }
              return 0 ;
    case droite : if (!r->vue) {ERR_vue ("aller") ; return 0 ;
              if (r->vue->droite) 
              {   r->vue = r->vue->droite ; return 1 }
              return 0 ;
    case pere   : if (!r->vue) {ERR_vue ("aller") ; return 0 ;
              if (r->vue->pere) 
              {   r->vue = r->vue->pere ; return 1 }
              return 0 ;
    }
}

static void ajouter (arbrebin r, direction d, void * obj)
{
    noeud n ;

    n = (noeud) malloc (sizeof (struct noeud)) ;
    n->gauche = n->droite = NULL ;
    n->objet  = obj ;

    switch (d)
    {
    case racine : r->vue    = n         ;
              n->gauche = r->racine ;
              if (r->racine) r->racine->pere = n ;
              r->racine = n ;
              break ;
    case gauche : n->gauche      = r->vue->gauche ;
              r->vue->gauche = n              ;
              n->pere        = r->vue         ;
              if (n->gauche) n->gauche->pere = n ;
              r->vue         = r->vue->gauche ;
              break ;
    case droite : n->droite      = r->vue->droite ;
              r->vue->droite = n              ;
              n->pere        = r->vue         ;
              if (n->droite) n->droite->pere = n ;
              r->vue         = r->vue->droite ;
              break ;
       case pere    : if (!r->vue->pere) r->racine = n ;
              n->pare        = r->vue->pere   ;
              r->vue->pere   = n              ;
              n->gauche      = r->vue         ;
              if (n->pere) 
              if (n->pere->gauche == r->vue)
                  n->pere->gauche = n ;
              else
                  n->pere->droite = n ;
              r->vue         = n              ;
    }
}

/* static int oter (arbrebin, void (*) (void *)) */
static int oter (arbrebin r) 
{
    noeud s, x ;

    if (!r->vue) { ERR_vue ("Oter") ; return 0 ; }

    if ((r->vue->gauche) && (r->vue->droite)) return 0 ;
    s = r->vue->pere ;
    if (s)
    if (s->gauche == r->vue)
        x = s->gauche = 
        ! r->vue->gauche ? r->vue->droite : r->vue->gauche ;
    else
        x = s->droite =
        ! r->vue->gauche ? r->vue->droite : r->vue->gauche ;
    else
    x = s->racine =
    ! r->vue->gauche ? r->vue->droite : r->vue->gauche ;

    if (x) x->pere = s ;
    oterfixer (r) ;
    free (r->vue) ;
    r->vue = x ? x : s ;
    return 1 ;
}

static void remplacer (arbrebin r, void *obj, void (*det_obj) (void *))
{
    if (!r->vue)
    { ERR_noeud ("Remplacer" ; return ; }
    (*det_obj) (r->vue->objet) ; 
    r->vue->objet = obj ;
}

static void fixer (arbrebin r)
{
    struct csvg * q ;
    q = (struct csvg *) malloc (sizeof (struct csvg)) ;
    q->svue = r->vue ; q->sprec = r->svg ; r->svg = q ;
}

static int retablir (arbrebin r)
{
    struct csvg * q ;
    if (r->svg) 
    {
        q = r->svg ; r->svg = r->svg->sprec ;
        free (q) ;
        return 1 ;
    }
    return 0 ;
}

static void afficher (arbrebin r, void (*affic) (void *))
{
    if (!r->racine)
        printf ("()") ;
    else _afficher (r->racine, affic) ;
}

static void _afficher (noeud n, void (*afficher) (void *))
{
    if (!(n->gauche) && !(n->droite))
    (*affic) (n->objet) ;
    else
    {
        printf ("(") ;
        (*affic) (n->n->objet) ;
    
        if (n->gauche) 
            _afficher (n->gauche, affic) ;
        else printf ("-") ;
    
        if (n->droite)
            _afficher (n->droite, affic) ;
    
        printf (")") ;
    }
}

static void deplacer (arbrebin r, direction d)
{
    noeud n ;

    if (!verifvue(r)) { ERR_vue() ; return ; }

    n = (noeud) malloc (sizeof (struct noeud) ; n->objet = NULL ;

    switch (d)
    {
    case racine : n->gauche = r->svg->svue ;
              n->droite = r->vue       ;
              n->pere   = NULL         ;
              r->racine = r->vue = n   ;
              break ;
    case pere   : n->gauche = r->svg->svue ;
              n->droite = r->vue       ;
              n->pere   = r->vue->pere ;
              r->vue->pere = n ; 
              r->vue       = n ;
              break ;
    case gauche : if (r->vue->gauche)
              {
              n->gauche = r->svg->svue   ;
              n->droite = r->vue->gauche ;
              n->pere   = r->vue         ;
              r->vue->gauche->pere = n   ;
              r->vue->gauche       = n   ;
              r->vue               = n   ;
              }
              else
              {
              n              = r->vue         ;
              r->vue->gauche = r->svg->vue    ;
              r->vue         = r->vue->gauche ;
              }
    case droite : if (r->vue->droite)
              {
              n->gauche = r->svg->svue   ;
              n->droite = r->vue->gauche ;
              n->pere   = r->vue         ;
              r->vue->droite->pere = n   ;
              r->vue->droite       = n   ;
              r->vue               = n   ;
              }
              else
              {
              n              = r->vue         ;
              r->vue->droite = r->svg->vue    ;
              r->vue         = r->vue->droite ;
              }
    }
    if (r->svg->svue->pere->gauche == r->svg->svue)
         r->svg->svue->pere->gauche = NULL ;
    else r->svg->svue->pere->droite = NULL ;
    
    r->svg->svue->pere = n ;
    r->svg = r->svg->sprec ;
}

static void greffer (arbrebin r, arbrebin s, direction d)
{
    noeud n ;
    n = (noeud) malloc (sizeof (struct noeud) ; n->objet = NULL ;

    switch (d)
    {
    case racine : n->gauche = r->racine ;
              n->droite = s->vue    ;
              n->pere   = NULL      ;
              n->gauche->pere = n->droite->pere = n ;
              r->vue = r->racine = n ; 
              break ;
    case pere   : if (r->vue->pere)
              {
              n->gauche       = r->vue              ;
              n->droite       = s->vue              ;
              n->pere         = r->vue->pere        ;
              n->gauche->pere = n->droite->pere = n ;
              r->vue          = n                   ;
              }
              else ERR_ajout ("greffer") ;
              break ;
    case gauche : if (r->vue->gauche)
              {
              n->gauche = r->vue->gauche ;
              n->droite = s->vue         ;
              n->pere   = r->vue         ;
              n->droite->pere = n->gauche->pere = n ;
              r->vue->gauche  = n ;
              r->vue          = n ;
              }
              else
              {
              r->vue->gauche = s->vue         ;
              s->vue->pere   = r->vue         ;
              r->vue         = r->vue->gauche ;
              }
              break ; 
    case droite : if (r->vue->droite)
              {
              n->gauche = r->vue->droite ;
              n->droite = s->vue         ;
              n->pere   = r->vue         ;
              n->droite->pere = n->gauche->pere = n ;
              r->vue->droite  = n ;
              r->vue          = n ;
              }
              else
              {
              r->vue->droite = s->vue         ;
              s->vue->pere   = r->vue         ;
              r->vue         = r->vue->droite ;
              }
    }
}

static arbrebin tailler (arbrebin r, direction d)
{
    arbrebin s ; noeud n ;
    s = creer () ;

    switch (d)
    {
    case racine : s->racine = s->vue = r->racine ;
              r->racine = r->vue = NULL      ;
              return s ;
    case droite : if (!r->vue) ERR_noeud ("tailler") ;
              if (r->vue->droite)
              {
              s->racine = s->vue   = r->vue->droite ;
              r->vue->droite->pere = NULL           ;
              r->vue->droite       = NULL           ; 
              }
              return s ;
    case gauche : if (!r->vue) ERR_noeud ("tailler") ;
              if (r->vue->gauche)
              {
              s->racine = s->vue   = r->vue->gauche ;
              r->vue->gauche->pere = NULL           ;
              r->vue->gauche       = NULL           ; 
              }
              return s ;
    case pere   : if (!r->vue) ERR_noeud ("tailler") ;
              if (r->vue->pere)
              {
                  s->racine = s->vue   = r->vue->pere ;
                      if (r->vue->pere == racine)
                      ERR_ajout ("tailler") ;
                  if (s->vue->pere->gauche == s->vue)
                      s->vue->pere->gauche = NULL ;
                  else
                      s->vue->pere->droite = NULL ;
                  r->vue = s->vue->pere ;
              }
              return s ;
    default : if (!r->vue) ERR_noeud ("tailler") ;
                  s->racine = s->vue   = r->vue ; 
              if (r->vue == racine) ERR_ajout ("tailler") ;
              if (r->vue->pere->gauche == r->vue)
                  r->vue->pere->gauche = NULL ;
              else
                  r->vue->pere->droite = NULL ;
              r->vue       = s->vue->pere ;
              s->vue->pere = NULL         ;
    }
}

static void ERR_vue ()
{
    printf ("ERREUR dans module %s : vue \n", nom_module) ;
}

static void ERR_noeud (char * mess)
{
    printf ("ERREUR dans module %s : fonction %s\n", nom_module, mess) ;
}

lier arbrebin ()
{
    arbrebin.creer     = &creer     ;
    arbrebin.detruire  = &detruire  ;
    arbrebin.existe    = &existe    ;
    arbrebin.aller     = &aller     ;
    arbrebin.lire      = &lire      ;
    arbrebin.ajouter   = &ajouter   ;
    arbrebin.oter      = &oter      ;
    arbrebin.remplacer = &remplacer ;
    arbrebin.fixer     = &fixer     ;
    arbrebin.retablir  = &retablir  ;
    arbrebin.deplacer  = &deplacer  ;
    arbrebin.greffer   = &greffer   ;
    arbrebin.tailler   = &tailler   ;
    arbrebin.afficher  = &afficher  ;
}


