class QuestionCaractere extends Question{

  private char reponse; // Dans ce cas, la réponse est un caractère

  public QuestionCaractere(String enonce, char reponse, double score){
    super(enonce, score);
    this.reponse = reponse;
  }

  public char getReponse(){
    return this.reponse;
  }

  public String getReponseToString(){
    return "" + this.getReponse();
  }

  public void setReponse(char rep){
    this.reponse = rep;
  }

  boolean estCorrect(String answer){
    if(answer.length()==1 && (this.reponse==answer.charAt(0)))
      return true;
    return false;
  }
}
