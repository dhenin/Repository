PDF =  Essais.pdf
OBJ =  Essais.tex


Essais.pdf :
	/Library/TeX/texbin/pdflatex -synctex=1 -interaction=nonstopmode --shell-escape Essais.tex

pdf :  $(PDF)

clean  : 
	rm -f *log *aux *synctex.gz *toc *mp *bak *cxx *idx *gnuplot *table *cfg  *maf *mtc *mtc0  *giac *.600pk *.660pk *.tfm *out
	touch french.cfg

clean_all: clean 
	rm -f *pdf 
