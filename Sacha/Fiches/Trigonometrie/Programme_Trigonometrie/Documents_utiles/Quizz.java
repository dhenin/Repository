import java.util.Scanner;
import java.io.*;
import java.util.*;

public class Quizz{

  public BanqueAleatoire questions;
  public static int niveau; // Permet de définir si on est en mode facile ou difficile
  // Si mode facile, on garde le score de la question
  // Si mode difficile, alors les points de la question sont multipliés par deux

  public Quizz(ArrayList<Question> q){
    this.questions = new BanqueAleatoire(q);
  }

  public Quizz(){
    this.questions = new BanqueAleatoire();
  }


  public static void main(String[] args) throws IOException{
    Scanner sc = new Scanner(System.in);
    niveau = 1; // On définit ici le niveau facile / difficile
    System.out.print("\033[2J"); // efface le terminal
    Quizz y = FabriqueQuizz.creeQuizz("BDD.txt");
    y.questions.poser();
  }
}
