import java.util.Scanner;
import java.util.ArrayList;
import java.util.*;

public class BanqueAleatoire{

  ArrayList<Question> questions;
  int nbPoints;

  // Constructeur pour une banque aléatoire sur une liste de questions donnée
  public BanqueAleatoire(ArrayList<Question> q){
    this.nbPoints = 20;
    System.out.print("\033[2J"); // efface le terminal
    this.questions = new ArrayList<Question>();
    this.questions.addAll(q);
  }

  public BanqueAleatoire(){
    nbPoints = 0;
    this.questions = new ArrayList<Question>();
  }

  public Question get(int i){
    return this.questions.get(i);
  }

  // Poser une question de la banque de questions, en évitant qu'elle soit posée 2 fois
  public void poser(){
    int compteurDePoints = 0;
    int index = 0;
    while(compteurDePoints < nbPoints && this.questions.size()!=0){
      index = (int) (Math.random()*this.questions.size()); // permet de choisir un int entre 0 et la taille du tableau - 1
      System.out.println("Question " + "sur " + this.questions.get(index).getScore()*(Quizz.niveau) + (this.questions.get(index).getScore()*(Quizz.niveau)==1?" point":" points"));
      if(index >= this.questions.size()) // Parfois, il peut y avoir des coquilles lors de la réduction du tableau, d'où cette condition préalable...
        index = this.questions.size()-1;
      EntreeSortie q = new EntreeSortie(this.questions.get(index));
      if(q.discussion() || this.questions.get(index).getScore() < 0) // la partie EntreeSortie est externalisée.
      // Si le score de la question est inférieur à 0, alors c'est que la question est de type QCM, et il faut ajouter ces points négatifs
      // L'autre condtion est dans le cas d'une bonne réponse
        compteurDePoints += this.questions.get(index).getScore()*(Quizz.niveau);
      // On fait maintenant en sorte que la question ne soit pas posée une deuxième fois,
      // on la retire donc du tableau de questions
      if(this.questions.size()-1 == index) // Cette condition sert à ce qu'il n'y ait pas de conflit si la question est au dernier indice
        this.questions.remove(index);
      else // On remplace la question par la dernière question du tableau
        this.questions.set(index, this.questions.remove(this.questions.size()-1));
    }
    // On traite ci-dessous l'affichage des cas terminaux
    if(this.questions.size()==0){
      if(compteurDePoints == nbPoints)
        System.out.println("Vous avez gagné !");
      else
        System.out.println("Vous avez perdu...");
      System.out.println("Votre score est de : " + compteurDePoints);
    }
    else{
      System.out.println("Vous avez gagné !\nVotre score est de " + compteurDePoints);
    }
  }
}
