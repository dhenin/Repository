class QCM extends QuestionCaractere{

  private String[] propositions;

  QCM(String enonce, String[] propositions, char reponse, double score){
    super(enonce, reponse, score);
    this.propositions = propositions;
  }

  @Override
  public String getEnonce(){
    return "" + this.enonce;
  }

  // Cette fonction permet de créer une string sur laquelle on concatène
  // l'énoncé et le tableau des propositions
  @Override
  public String getEnonceComplet(){
    String retour = "" + this.enonce + "\n";
    for(int i = 0; i<propositions.length; i++){
      retour += "(" + (char)('a' + i) + ") " + propositions[i];
      if(i!=this.propositions.length-1)
        retour += "\n";
    }
    return retour;
  }

  // Renvoie le caractère sous forme d'un string
  public String getReponseToString(){
    return "" + this.getReponse();
  }

  @Override
  public boolean estCorrect(String answer){
      if(answer.length()==1 && (this.getReponse()==answer.charAt(0)))
        return true;
      this.setScore(- 1); // On met le score de la question à -1, pour faire une pénalité de 1 point négatif si la réponse est fausse
      return false;
  }
}
