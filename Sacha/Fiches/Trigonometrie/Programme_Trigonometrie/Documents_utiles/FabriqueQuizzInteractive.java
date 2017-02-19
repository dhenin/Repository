import java.util.Scanner;
import  java.util.ArrayList;

class FabriqueQuizzInteractive{
  // Ces macros permettent d'être plus clair dnas le switch qui suivra...
  private final int AJOUTER_QUESTION = 1;
  private final int SUPPRIMER_QUESTION = 2;
  private final int RECHERCHER_QUESTION = 3;
  private final int DEPLACER_QUESTION = 4;
  private final int AFFICHER = 5;
  private final int QUITTER = 6;

  private ArrayList<Question> bdd = new ArrayList<Question>();

  public FabriqueQuizzInteractive(){
    System.out.print("\033[2J"); // efface le terminal
    Scanner sc = new Scanner(System.in);
    int reponse = 0;
    while(reponse != QUITTER){
      System.out.print("\033[2J"); // efface le terminal
      System.out.println(menuGeneral()); // On affiche le menu général
      reponse = sc.nextInt();
      while(!(1 <= reponse && reponse <= QUITTER)){
        // Si la réponse n'est pas dans l'intervalle
        System.out.println("Ceci n'est pas une réponse correcte !");
        System.out.println("Veuillez choisir une réponse correcte...");
        reponse = sc.nextInt();
      }
      switch(reponse){
        case AJOUTER_QUESTION:
          ajouterQuestion();
        break;

        case SUPPRIMER_QUESTION:
          supprimerQuestion();
        break;

        case RECHERCHER_QUESTION:
          rechercherQuestion();
        break;

        case DEPLACER_QUESTION:
          deplacerQuestion();
        break;

        case AFFICHER:
        // affiche la base de données (grâce au toString())
          System.out.print("\033[2J"); // efface le terminal
          System.out.println(this);
        break;
        case QUITTER:
        break;
      }
      continuer(); // Cette fonction permet simplement de valider l'opération qui a été faite
      // Elle est utile pour que le menu n'efface pas tout de suite le travail en cours au moment du réaffichage
    }
  }

  public void ajouterQuestion(){
    Question q = nouvelleQuestion();
    this.bdd.add(q); // On utilise les fonctions de la class ArrayList
  }

  public void supprimerQuestion(){
    System.out.print("\033[2J"); // efface le terminal
    Scanner sc = new Scanner(System.in);
    System.out.println("Veuillez entrer le numéro de la question que vous voulez supprimer...");
    int index = sc.nextInt();
    this.bdd.remove(index-1);
  }

  public void rechercherQuestion(){
    System.out.print("\033[2J"); // efface le terminal
    Scanner sc = new Scanner(System.in);
    System.out.println("Vous allez rechercher une question grâce à un mot ou \n"
    + "une chaîne de caractères présent(e) dans l'énoncé");
    System.out.println("Veuillez entrer cette chaîne de caractères...\n"
    +"(attention aux majuscules, signes de ponctuation...)");
    String recherche = sc.next();
    System.out.print("\033[2J"); // efface le terminal
    ArrayList<Question> trouvees = new ArrayList<Question>();
    // On cherche tous les énoncés qui contiennent la chaine de caractères "recherche"
    // Et s'ils la contient, on les met dans un tableau
    for(int i = 0; i<this.bdd.size();i++){
      if(this.bdd.get(i).getEnonceComplet().contains(recherche))
        trouvees.add(this.bdd.get(i));
    }
    // Si le tableau est vide, on a rien trouvé
    if(trouvees.size()==0){
      System.out.println("Aucune question ne correspond à votre recherche");
    }
    // Sinon, on affiche « proprement » questions et réponses.
    for(int i = 0; i<trouvees.size(); i++){
      System.out.println("Question trouvée " + (i+1) + " sur " + trouvees.get(i).getScore() + (trouvees.get(i).getScore()<=1?"point":" points."));
      System.out.println(trouvees.get(i).getEnonceComplet());
      System.out.println("Réponse : " + trouvees.get(i).getReponseToString());
      System.out.println();
    }
  }

  // On switch deux questions dont on connaît les indices.
  public void deplacerQuestion(){
    System.out.print("\033[2J"); // efface le terminal
    Scanner sc = new Scanner(System.in);
    System.out.println("Veuillez entrer le numéro de la question que vous voulez déplacer...");
    int index = sc.nextInt();
    System.out.println("Veuillez entrer le nouveau numéro de cette question...");
    int newIndex = sc.nextInt();
    Question old = this.bdd.get(index - 1);
    Question nouv = this.bdd.get(newIndex - 1);
    this.bdd.set(newIndex - 1, old);
    this.bdd.set(index - 1, nouv);
  }

  // Permet de simule une « pause » de durée variable.
  public void continuer(){
    Scanner sc = new Scanner(System.in);
    System.out.println("Appuyez sur la touchée 'entrée' pour terminer l'opération");
    String temporaire = sc.nextLine();
  }

  // Utilisée pour afficher l'ensemble de la BDD
  @Override
  public String toString(){
    String retour = "";
    for(int i = 0; i<this.bdd.size(); i++){
      Question tmp = this.bdd.get(i);
      retour += "Question " + (i+1) + ", sur " + this.bdd.get(i).getScore() + (this.bdd.get(i).getScore()<=1?"point":" points." + "\n");
      retour += tmp.getEnonceComplet() + "\n";
      retour += "Réponse : " + tmp.getReponseToString() + "\n \n";
    }
    return retour;
  }

  public Question nouvelleQuestion(){
    Scanner sc = new Scanner(System.in);
    System.out.print("\033[2J"); // efface le terminal
    System.out.println("Combien de points vaut votre question ?");
    double points = sc.nextDouble();
    System.out.print("\033[2J"); // efface le terminal
    System.out.println("Quel est l'énoncé de votre question ?");
    // On vide la ligne de caractère...
    sc.nextLine();
    // Avant de lire la suivante, sinon beug
    String enonce = sc.nextLine();
    System.out.print("\033[2J"); // efface le terminal
    System.out.println(menuQuestion());
    int rep = sc.nextInt();
    while(!(1 <= rep && rep <= 7)){
      // Si la réponse n'est pas compris dans les possibilités
      System.out.println("Ceci n'est pas une réponse valide !");
      System.out.println("Veuillez entrer une réponse valide.");
      rep = sc.nextInt();
    }
    String reponse = "";
    System.out.print("\033[2J"); // efface le terminal
    switch(rep){
      case 1: // Si c'est une question dont la réponse est une phrase
        System.out.println("Quelle est la réponse à la question ?");
        System.out.println("(Entrez la phrase ci-dessous)");
        reponse = sc.next();
        return new QuestionPhrase(enonce, reponse, points);
      case 2: // Si c'est une question dont la réponse est un mot
        System.out.println("Quelle est la réponse à la question ?");
        System.out.println("(Entrez le mot ci-dessous)");
        reponse = sc.next();
        return new QuestionMot(enonce, reponse, points);
      case 3: // Si c'est une question dont la réponse est un nombre décimal
        System.out.println("Quelle est la réponse à la question ?");
        System.out.println("(Entrer le nombre ci-dessous)");
        reponse = sc.next();
        return new QuestionReel(enonce, Double.parseDouble(reponse), points);
      case 4: // Si c'est une question dont la réponse est un intervalle
        System.out.println("Quelle est la réponse à la question ?");
        System.out.println("(Entrez votre intervalle-réponse sous la \n"
        + "forme BORNE_INFERIEURE/BORNE_SUPERIEURE)");
        reponse = sc.next();
        String[] tmp = reponse.split("/"); // On coupe en deux String la partie avant et celle après le slash
        // Puis on crée un intervalle en ayant parsé les deux Strings (qui correspondent à des double)
        Intervalle answer = new Intervalle(Double.parseDouble(tmp[0]), Double.parseDouble(tmp[1]));
        return new QuestionIntervalle(enonce, answer, points);
      case 5: // Si c'est une question dont la réponse est un entier
        System.out.println("Quelle est la réponse à la question ?");
        System.out.println("(Entrer l'entier réponse ci-dessous)");
        reponse = sc.next();
        return new QuestionEntier(enonce, Integer.parseInt(reponse), points);
      case 6: // Si c'est une question dont la réponse est un racaractère
        System.out.println("Quelle est la réponse à la question ?");
        System.out.println("(Entrez le caractère réponse ci-dessous)");
        reponse = sc.next();
        while(reponse.length()!=1){ // Si la chaîne de caractère entrée n'est pas de taille 1, ce n'est pas un caractère
          System.out.println("Ceci n'est pas une réponse valide !");
          System.out.println("Veuillez entrer une réponse valide.");
          reponse = sc.nextLine();
        }
        return new QuestionCaractere(enonce, reponse.charAt(0), points);
      case 7: // Si c'est une question de type QCM
        System.out.println("Combien y a-t-il de propositions de réponses ?");
        int taille = sc.nextInt();
        String[] propositionsDeReponses = new String[taille];
        for(int k = 0; k<taille; k++){
          System.out.println("Veuillez entrer la proposition " + "(" + (char)('a' + k) + ")");
          String tmpp = sc.next();
          propositionsDeReponses[k] = tmpp;
        }
        System.out.println("Quelle est la réponse à la question ?");
        reponse = sc.next();
        return new QCM(enonce, propositionsDeReponses, reponse.charAt(0), points);
      default:
        System.out.print("\033[2J"); // efface le terminal
    }
    // Pour le bon fonctionnement du programme, l'interpréteur JAVA a besoin de la question suivante pour compiler...
    return new QuestionPhrase("Ceci est une question qui n'a pas lieu d'être, sa réponse est \"oui\"...", "oui", 0);
  }

  // Premier menu
  public static String menuGeneral(){
    return ("Que voulez-vous faire ?\n"
    + "(1) Ajouter une question\n"
    + "(2) Supprimer une question\n"
    + "(3) Rechercher une question particulière en connaissant un mot\n"
    + "(4) Déplacer une question\n"
    + "(5) Afficher toute la base de données de questions\n"
    + "(6) Quitter.")
    ;
  }

  // Second menu
  public static String menuQuestion(){
    return "Quel est le type de la question ?\n"
    + "(1) Réponse sous forme d'une phrase ;\n"
    + "(2) Réponse sous forme d'un mot ;\n"
    + "(3) Réponse sous forme d'un nombre décimal ;\n"
    + "(4) Réponse sous forme d'un nombre décimal avec une tolérance ;\n"
    + "(5) Réponse sous forme d'un entier ;\n"
    + "(6) Réponse sous forme d'un caractère ;\n"
    + "(7) QCM ;";
  }

  // Permet de récupérer la BDD de questions créée, notamment dans Quizz, pour après la mélanger, et poser des questions
  public ArrayList<Question> getBdd(){
    return this.bdd;
  }
}
