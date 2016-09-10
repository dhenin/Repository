PDF = Ackerman.pdf 
OBJ =  Ackerman.tex

Install_variations:
	mkdir -p $HOME/Library/texmf/tex/generic/variations
	cd $HOME/Library/texmf/tex/generic/variations
	curl -O http://mirror.switch.ch/ftp/mirror/tex/macros/generic/variations/variations.sty
	curl -O http://mirror.switch.ch/ftp/mirror/tex/macros/generic/variations/variations.tex
	texhash

Ackerman: Ackerman.c
	cc -o Ackerman Ackerman.c

pdf :  $(PDF)

clean  : 
	rm -f *log *aux *synctex.gz *toc *mp *bak *cxx *idx *gnuplot *table *cfg  *maf *mtc *mtc0  *giac *.600pk *.660pk *.tfm
	touch french.cfg

clean_all: clean 
	rm -f *pdf  french.cfg Ackerman
