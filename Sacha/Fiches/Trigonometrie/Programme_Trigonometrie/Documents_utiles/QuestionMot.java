class QuestionMot extends QuestionPhrase{

  QuestionMot(String enonce, String reponse, double score){
    super(enonce, reponse, score);
  }

  boolean estCorrect(String answer){
    for(int i = 0; i<answer.length(); i++){
      if(answer.charAt(i)==' '){ // Si la String contient un espace, ce n'est pas un mot, donc on retourne un faux (erreur)
        return false;
      }
    }
    if(this.getReponse().equals(answer))
      return true;
    return false;
  }


}
