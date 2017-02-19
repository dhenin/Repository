import java.util.Scanner;

class EntreeSortie{

  private Question entree;

  public EntreeSortie(Question entree){
    this.entree = entree;
  }

  public boolean discussion(){
    System.out.println(entree); // On affiche l'énoncé
    Scanner sc = new Scanner(System.in);
    System.out.print("Réponse : ");
    String reponse = sc.nextLine(); // On lit la réponse de l'utilisateur
    System.out.println(entree.estCorrect(reponse)?"Oui !\n":"Non...\nLa bonne réponse était " + entree.getReponseToString() + "\n"); // On la compare
    return this.entree.estCorrect(reponse); // Et on retourne le résultat
  }



}
