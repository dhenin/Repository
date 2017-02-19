SOURCES  = $(wildcard ./*.tex)

OBJS= $(SOURCES:.tex=.pdf) 

PDFS=$(addprefix Fichiers_PDF/,$(OBJS))


LISTE :  $(SOURCES)
	echo  echo $(PDFS) 
	# echo $(SOURCES) ; echo "------------" ; echo $(PDFS) 

Fichiers_PDF/%.pdf : %.tex
	mkdir -p Fichiers_PDF ; pdflatex  -output-directory=Fichiers_PDF -aux-directory=Fichers_PDF $< 

all :  $(SOURCES) $(PDFS) 

clean  : 
	rm -f *log *aux *synctex.gz *toc *mp *bak *cxx *idx *gnuplot *table *cfg  *maf *mtc *mtc0  *giac ; 	(cd Fichiers_PDF ; rm -f *log *aux *synctex.gz *toc *mp *bak *cxx *idx *gnuplot *table *cfg  *maf *mtc *mtc0  *giac ) 

clean_all: clean 
	rm -f *pdf 
