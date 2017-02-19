// D'après le tableau des classes joint dans le dossier, cette classe est la sur-class
// de toutes les questions, et on la met abstract, car toutes les autres questions
// vont la redéfinir.

abstract class Question{

    public String enonce;
    private String reponse;
    private double score;

    public Question(String s, double score){
      this.enonce = s;
      this.score = score;
    }

    public String getEnonce(){
      return this.enonce;
    }

    abstract boolean estCorrect(String reponse);

    abstract String getReponseToString();

    public String getEnonceComplet(){
      return this.getEnonce();
    }

    public String toString(){
      return this.getEnonceComplet();
    }

    public double getScore(){
      return this.score;
    }

    public void setScore(int i){
      this.score = i;
    }

}
