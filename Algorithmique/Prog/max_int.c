#include <stdio.h>
#include <machine/limits.h>
#include <float.h>

main()
{
    printf ("Max int : %12d\n",
                       INT_MAX) ;
    printf ("Min float : %g\n",
                       FLT_MIN) ;
    exit (0) ;
}
