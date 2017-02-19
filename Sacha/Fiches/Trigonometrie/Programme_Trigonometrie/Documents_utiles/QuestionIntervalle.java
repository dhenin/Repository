  public class QuestionIntervalle extends Question{

    private Intervalle reponse; // C'est dans cette class que l'on définie la tolérance, sous forme d'un intervalle

    public QuestionIntervalle(String enonce, Intervalle reponse, double score){
      super(enonce, score);
      this.reponse = reponse;
    }

    public Intervalle getReponse(){
      return new Intervalle(this.reponse.getInf(), this.reponse.getSup());
    }

    // On différencie dans cette fonction de cas, si l'intervalle est la forme [35,35], alors on retournera 35
    // car l'intervalle est juste un réel.
    public String getReponseToString(){
      if(this.getReponse().getInf()==this.getReponse().getSup()){
        return "" + this.getReponse().getInf();
      }
      else{
        return this.getReponse().toString();
      }
    }

    public void setReponse(Intervalle rep){
      this.reponse = rep;
    }

    boolean estCorrect(String answer){
      double rep = Double.parseDouble(answer);
      if(this.reponse.getInf() <= rep && rep <= this.reponse.getSup()) // Il faut que la réponse soit dans l'intervalle
        return true;
      return false;
    }
  }
