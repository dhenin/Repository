FIGDIR = Figures

DESSINS = \
	$(FIGDIR)/recip1.tex \
	$(FIGDIR)/recip2.tex \
	$(FIGDIR)/recip3.tex \
	$(FIGDIR)/recip4.tex \
	$(FIGDIR)/recip5.tex \
	$(FIGDIR)/recip6.tex


support : ${DESSINS}
#	rm main.aux main.toc 
	latex main.tex ; # rm main.toc
	latex main.tex ; # rm main.toc 
	makeindex main
	sed -f filtre.toc.sed             main.toc > x.toc ; mv x.toc main.toc 
#	sed 's/figure}{\\numberline {[0-9\.]*/section/'  main.lof > x.lof ; mv x.lof main.lof 
	latex main.tex
	cp main.dvi main2.dvi 

ps : support
	dvips main.dvi -o main.ps

book : ps 
	psselect -e main.ps main.e.ps
	psselect -o -r  main.ps main.o.ps
	echo 'lp main.e.ps'

# re_vases.tex $(DESSINS)
#	latex re_vases.tex

#
# Les figures
#

recip1.tex:	$(FIGDIR)/recip1.fig
	fig2dev -L latex $(FIGDIR)/recip1.fig > $(FIGDIR)/recip1.tex

recip2.tex:	$(FIGDIR)/recip2.fig
	fig2dev -L latex $(FIGDIR)/recip2.fig > $(FIGDIR)/recip2.tex

recip3.tex:	$(FIGDIR)/recip3.fig
	fig2dev -L latex $(FIGDIR)/recip3.fig > $(FIGDIR)/recip3.tex

recip4.tex:	$(FIGDIR)/recip4.fig
	fig2dev -L latex $(FIGDIR)/recip4.fig > $(FIGDIR)/recip4.tex

recip5.tex:	$(FIGDIR)/recip5.fig
	fig2dev -L latex $(FIGDIR)/recip5.fig > $(FIGDIR)/recip5.tex

recip6.tex:	$(FIGDIR)/recip6.fig
	fig2dev -L latex $(FIGDIR)/recip6.fig > $(FIGDIR)/recip6.tex
clean  : 
	rm -f *log *aux *synctex.gz *toc *mp *bak *cxx *idx *gnuplot *table *cfg  *dvi
