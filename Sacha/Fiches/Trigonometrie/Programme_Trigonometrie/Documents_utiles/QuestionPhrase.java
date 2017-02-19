class QuestionPhrase extends Question{

  private String reponse;

  public QuestionPhrase(String enonce, String reponse, double score){
    super(enonce, score);
    this.reponse = reponse;
  }

  public String getReponse(){
    return this.reponse;
  }

  public String getReponseToString(){
    return this.getReponse();
  }

  public void setReponse(String rep){
    this.reponse = rep;
  }

  boolean estCorrect(String answer){
    if(this.reponse.equals(answer))
      return true;
    return false;
  }

  }
