class Intervalle{

  private double inf;
  private double sup;

  // Constructeur pour un vrai intervallle
  Intervalle(double bas, double haut){
    this.inf = bas;
    this.sup = haut;
  }

  // Constructeur pour un intervalle = à un réel (type [42,42] = 42).
  //Utile pour l'héritage
  Intervalle(double valeur){
    this.inf = valeur;
    this.sup = valeur;
  }

  double getInf(){
    return this.inf;
  }

  double getSup(){
    return this.sup;
  }

  void setInf(double bas){
    this.inf = bas;
  }

  void setSup(double haut){
    this.sup = haut;
  }

  // Utile pour la lecture dans FabriqueQuizzInteractive
  @Override
  public String toString(){
    return ("[" + this.inf + " ; " + this.sup + "]");
  }
}
