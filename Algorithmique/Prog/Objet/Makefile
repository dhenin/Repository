all : attente expression inf2pre inf2post  entier 
	    
attente :  Liste.o Liste.h File.tda attente.c
	    cc -g -o attente attente.c Liste.o

expression : Liste.o Liste.h Pile.tda expression.c
	    cc -g -o expression expression.c Liste.o

inf2pre : Liste.o Liste.h Pile.tda inf2pre.c
	    cc -g -o inf2pre inf2pre.c Liste.o

inf2post : Liste.o Liste.h File.tda inf2post.c
	    cc -g -o inf2post inf2post.c Liste.o

usager : Liste.o Liste.h Liste.tda usager.c
	    cc -g -o usager usager.c Liste.o

entier : Liste.o Liste.h Liste.tda entier.c
	    cc -g -o entier entier.c Liste.o

Liste.o : Liste.h Liste.c
	    cc -g -c Liste.c

clean : 
	    rm -f a.out Liste Liste.o entier inf2post
