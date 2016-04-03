PDF = Cours_Hilaire_seconde.pdf Essais.pdf
OBJ =  Cours_Hilaire_seconde.tex Essais.tex

Install_variations:
	mkdir -p $HOME/Library/texmf/tex/generic/variations
	cd $HOME/Library/texmf/tex/generic/variations
	curl -O http://mirror.switch.ch/ftp/mirror/tex/macros/generic/variations/variations.sty
	curl -O http://mirror.switch.ch/ftp/mirror/tex/macros/generic/variations/variations.tex
	texhash

Cours_Hilaire_seconde.pdf:
	/Library/TeX/texbin/pdflatex -synctex=1 -interaction=nonstopmode --shell-escape Cours_Hilaire_seconde.tex
	
Essais.pdf :
	/Library/TeX/texbin/pdflatex -synctex=1 -interaction=nonstopmode --shell-escape Essais.tex

pdf :  $(PDF)

clean  : 
	rm -f *log *aux *synctex.gz *toc *mp *bak *cxx *idx *gnuplot *table *cfg  *maf *mtc *mtc0  *giac *.600pk *.660pk *.tfm *.-pg *teg *.-tk
clean_all: clean 
	rm -f *pdf 
