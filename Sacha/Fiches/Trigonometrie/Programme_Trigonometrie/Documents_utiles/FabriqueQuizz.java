import java.io.*;
import java.util.*;

class FabriqueQuizz{

  public static Quizz creeQuizz(String filename) throws IOException{
    Scanner in = new Scanner(new File(filename));
    ArrayList<String> lu = new ArrayList<String>();
    ArrayList<Question> quizz = new ArrayList<Question>();
    // Tant qu'il y a encore des lignes, on les lit, et les ajoute à lu
    while(in.hasNextLine()){
      lu.add(in.nextLine());
    }
    // Si on a rien lu, on retourne un Quizz vide
    if(lu.size()==0)
      return new Quizz();
    for(int i = 0; i<lu.size(); i++){
      String[] question = lu.get(i).split("\\?");
      // question[0] représente l'énoncé de la question
      // question[1] contient le type de réponse, et la réponse
      if(question[1].charAt(0)==' '){ // Supprime l'espace introductif, s'il y en a un
        question[1] = question[1].replaceFirst(" ", "");
      }
      // On coupe la réponse en 3 parties (3 si tout va bien : type reponse points)
      String[] reponse = question[1].split(" ");
      int rep = 0; // permet de différencier les types de questions selon le premier mot après le ?
      if(reponse[0].equals("phrase")){
        rep = 1;
      }
      else if(reponse[0].equals("mot")){
        rep = 2;
      }
      else if(reponse[0].equals("double")){
        rep = 3;
      }
      else if(reponse[0].equals("intervalle")){
        rep = 4;
      }
      else if(reponse[0].equals("entier")){
        rep = 5;
      }
      else if(reponse[0].equals("char")){
        rep = 6;
      }
      else if(reponse[0].equals("qcm")){
        rep = 7;
      }
      switch(rep){
        case 1: // Si c'est une question dont la réponse est une phrase
          reponse[1] = reponse[1].replaceAll("_", " ");
          quizz.add(new QuestionPhrase(question[0], reponse[1], Double.parseDouble(reponse[2])));
          break;
        case 2: // Si c'est une question dont la réponse est un mot
          quizz.add(new QuestionMot(question[0], reponse[1], Double.parseDouble(reponse[2])));
          break;
        case 3: // Si c'est une question dont la réponse est un nombre décimal
          quizz.add(new QuestionReel(question[0], Double.parseDouble(reponse[1]), Double.parseDouble(reponse[2])));
          break;
        case 4: // Si c'est une question dont la réponse est un intervalle
          String[] tmp = reponse[1].split("/"); // On coupe en deux String la partie avant et celle après le slash
          // Puis on crée un intervalle en ayant parsé les deux Strings (qui correspondent à des double)
          Intervalle answer = new Intervalle(Double.parseDouble(tmp[0]), Double.parseDouble(tmp[1]));
          quizz.add(new QuestionIntervalle(question[0], answer, Double.parseDouble(reponse[2])));
          break;
        case 5: // Si c'est une question dont la réponse est un entier
          quizz.add(new QuestionEntier(question[0], Integer.parseInt(reponse[1]), Double.parseDouble(reponse[2])));
          break;
        case 6: // Si c'est une question dont la réponse est un racaractère
          quizz.add(new QuestionCaractere(question[0], reponse[1].charAt(0), Double.parseDouble(reponse[2])));
          break;
        case 7: // Si c'est une question de type QCM
          String[] propositionsDeReponses = reponse[1].split("-");
          quizz.add(new QCM(question[0], propositionsDeReponses, reponse[2].charAt(0), Double.parseDouble(reponse[3])));
          break;
        default:
      }
    }
    return new Quizz(quizz);
  }
}
