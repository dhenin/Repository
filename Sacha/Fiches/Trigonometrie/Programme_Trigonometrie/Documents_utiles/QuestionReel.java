  public class QuestionReel extends QuestionIntervalle{

    //c'est le cas où inf = suf dans l'intervalle

    public QuestionReel(String enonce, double reponse, double score){
      super(enonce, new Intervalle(reponse, reponse), score);
    }

    public void setReponse(double rep){
      // On met donc les deux bornes de l'intervalle au même réel, pour avoir un intervalle réduit à un réel
      this.getReponse().setInf(rep);
      this.getReponse().setSup(rep);
    }

    boolean estCorrect(String answer){
      double rep = Double.parseDouble(answer);
      if(rep == this.getReponse().getInf()) // équivalent à this.reponse.getSup()
        return true;
      return false;
    }
  }
