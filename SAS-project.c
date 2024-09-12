#include <stdio.h>
#include <string.h>


int choix=0;
int count=0;
int max_etudiant = 300;
int max_departement = 20;


typedef struct{
    int jour;
    int mois;
    int annee;
} Datenaissance;

typedef struct{

    int num_etudiant;
    char nom[50];
    char prenom[50];
    Datenaissance birthdate;
    char departemenet[50];
    float note;

} Etudiant;

void ajouter(Etudiant student[])
{
    //student[max_etudiant].num_etudiant = unique;

    printf("Entrer les infos d'etudiant %d: \n",count + 1 );

    printf("----ENTRER LE NUMERO UNIQUE D'ETUDIANT : \n");
    scanf("%d", &student[count].num_etudiant);

    printf("----ENTRER LE NOM D'ETUDIANT : \n");
    scanf("%s", &student[count].nom);

    printf("----ENTRER LE PRENOM D'ETUDIANT : \n");
    scanf("%s", &student[count].prenom);

    printf("----ENTRER LE JOUR DE NAISSANCE : \n");
    scanf("%d", &student[count].birthdate.jour);

    printf("----ENTRER LE MOIS DE NAISSANCE : \n");
    scanf("%d", &student[count].birthdate.mois);

    printf("----ENTRER L'ANNEE DE NAISSANCE : \n");
    scanf("%d", &student[count].birthdate.annee);

    printf("----ENTRER LA DEPARTEMENT D'ETUDIANT : \n");
    scanf("%s", &student[count].departemenet);

    printf("----ENTRER LA NOTE GENERALE D'ETUDIANT : \n");
    scanf("%f", &student[count].note);

    printf("--------------------------------------\n");

}

void modifier(Etudiant student[])
{

    int num_recherch;
    int nouveau_numero;
    int nouveau_jour;
    int nouveau_mois;
    int nouveau_annee;
    char nouvelle_departemenet[50];
    float nouvelle_note;

    // new variables that will take the new entered informations.

    printf("Entrer le numero unique d'etudiant : ");
    scanf("%d", &num_recherch);

    for (int i=0; i < count; i++)
    {
            //search loop for the unique number of the student we are looking for.

        if (num_recherch == student[i].num_etudiant)
        {
            // giving the old values new ones
            printf("Entrer le nouveau numero unique : \n");
            scanf("%d", &nouveau_numero);
            student[i].num_etudiant = nouveau_numero;

            printf("Entrer le nouveau jour de naissance : \n");
            scanf("%d", &nouveau_jour);
            student[i].birthdate.jour = nouveau_jour;

            printf("Entrer le nouveau mois de naissance : \n");
            scanf("%d", &nouveau_mois);
            student[i].birthdate.mois = nouveau_mois;

            printf("Entrer la nouvelle annee de naissance : \n");
            scanf("%d", &nouveau_annee);
            student[i].birthdate.annee = nouveau_annee;

            printf("Entrer la nouvelle departement : \n");
            scanf("%s", nouvelle_departemenet);
            strcpy(student[i].departemenet, nouvelle_departemenet);

            printf("Entrer la nouvelle note generale du : \n");
            scanf("%f", &nouvelle_note);
            student[i].note = nouvelle_note;

        }

    }

}

void supprimer(Etudiant student[])
{

    int num_recherch;


    printf("Entrer le Numero unique d'etudiant ce que vous voulez supprimer: ");
    scanf("%d", &num_recherch);
    for (int i=0; i < count; i++) // a loop that search for the unique number entered
    {
        if (num_recherch == student[i].num_etudiant)
        {
            printf("L'etudiant: %s %s", student[i].prenom, student[i].nom);
            for(int j=i; j < count-1; j++)
            {
                // a nested loop that replaces the element we want to delete with the element in the index after it.

                strcpy(student[j].nom, student[j+1].nom);
                strcpy(student[j].prenom, student[j+1].prenom);
                strcpy(student[j].departemenet, student[j+1].departemenet);
                student[j].num_etudiant = student[j+1].num_etudiant;
                student[j].birthdate.jour = student[j+ 1].birthdate.jour;
                student[j].birthdate.mois = student[j+ 1].birthdate.mois;
                student[j].birthdate.annee = student[j+ 1].birthdate.annee;
                student[j].note = student[j+1].note;

            }
                count--;
        }
    }
}

void afficher(Etudiant student[])
{

     for(int i = 0; i < count; i++){

        printf(" --- LES INFOS D'ETUDIANT : ----------------- %d\n",i + 1 );
        printf(" --- LE NOM D'ETUDIANT:  -------------------- %s\n", student[i].nom);
        printf(" --- LE PRENOM D'ETUDIANT: ------------------ %s\n", student[i].prenom);
        printf(" --- LE NUMERO UNIQUE D'ETUDIANT:  ---------- %d\n", student[i].num_etudiant);
        printf(" --- LE DATE DE NAISSANCE D'ETUDIANT:  ------ %d/%d/%d\n", student[i].birthdate.jour, student[i].birthdate.mois, student[i].birthdate.annee);
        printf(" --- LA DEPARTEMENT D'ETUDIANT:  ------------ %s\n", student[i].departemenet);
        printf(" --- LA NOTE GENERALE D'ETUDIANT:  ---------- %.2f\n", student[i].note);
        printf("-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/--\n");

     }
}

void calculermoyenne(Etudiant student[])
{

    char departement_rech[50];
    float somme_note = 0;
    float somme_universite = 0;
    int nombre_etudiants = 0;

    printf("Entrer la departement ce que vous voulez calculer: ");
    scanf("%s", &departement_rech);
    for (int i=0; i < count; i++)
    {
        somme_universite += somme_note;
        if (strcasecmp(departement_rech, student[i].departemenet)== 0)
        {

                 somme_note += student[i].note;
                 nombre_etudiants++;
        }
    }
            printf("La moyenne generale du departement %s : %.2f \n", departement_rech, somme_note / nombre_etudiants);
            printf("--------------------------------------------\n");
            printf("La moyenne generale d'universite : %.2f \n", somme_universite / nombre_etudiants);

}

void statistiques(Etudiant student[])
{
       int departs[max_departement];
       char departement_name[max_departement][20];
       int conteur_depart = 0;
       int option;
       float seuil;

       for (int i = 0; i < count; i++) {
            int trouver = 0; // variable pour stocker les departements trouver
          for (int j = 0; j < conteur_depart; j++) {
            if (strcasecmp(student[i].departemenet, departement_name[j]) == 0) {
                departs[j]++;
                trouver = 1;
                break;
            }
        }
           // we pass the values obtained to our main array in our structure
            if (!trouver) {
                  strcpy(departement_name[conteur_depart], student[i].departemenet);
                  departs[conteur_depart++] = 1;
        }
    }

      while(1)
      {

       printf("----- BIENVENUE SUR L'INTERFACE DU STATISTIQUES DU NOTRE UNIVERSITE -------\n");
       printf("1-- AFFICHER le nombre total d'etudiants inscrits: \n");
       printf("2-- AFFICHER le nombre d'etudiants dans chaque departement: \n");
       printf("3-- AFFICHER les etudiants ayant une moyenne generale superieure a un certain seuil: \n");
       printf("4-- AFFICHER les 3 etudiants ayant les meilleures notes: \n");
       printf("5-- AFFICHER le nombre d'etudiants ayant reussi dans chaque departement: \n");
       printf("6-- QUITTER\n");
       printf("---------------------------------------------------------------------------- \n");
       printf("Entrer l'option ce que vous voulez afficher: ");
       scanf("%d", &option);

            switch (option){

               case 1:

                   printf("le nombre total d'etudiants inscrits: %d ", count);
                   break;

               case 2:

                   for (int i = 0; i < conteur_depart; i++) {

                          printf("Departement %s: %d etudiants\n", departement_name[i], departs[i]);
                   }
                   break;

               case 3:

                          printf("Entrer la seuil : ");
                          scanf("%f", &seuil);
                          printf("Étudiants avec une moyenne generale superieure a %.2f:\n", seuil);
                             for (int i = 0; i < count; i++) {
                                 if (student[i].note > seuil) {
                                       printf("%s %s %.2f\n", student[i].nom, student[i].prenom, student[i].note);
                                 }
                             }
                   break;

               case 4:

                   printf("les 3 etudiants ayant les meilleures notes: ");
                   break;

               case 5:

                   printf("le nombre d'etudiants ayant reussi dans chaque departement: ");
                   break;

               case 6:

                   return;
                   break;

            }
      }
}

void Rechercher(Etudiant student[]){

    char Le_nom[50];

        printf("Entrer le nom d'etudiant: ");
        scanf("%s", &Le_nom);

    for(int i = 0; i < count; i++){

       if(strcasecmp(Le_nom, student[i].nom)== 0){
             printf(" --- LES INFOS D'ETUDIANT : ----------------- %d\n",i + 1 );
             printf(" --- LE NOM D'ETUDIANT:  -------------------- %s\n", student[i].nom);
             printf(" --- LE PRENOM D'ETUDIANT: ------------------ %s\n", student[i].prenom);
             printf(" --- LE NUMERO UNIQUE D'ETUDIANT:  ---------- %d\n", student[i].num_etudiant);
             printf(" --- LE DATE DE NAISSANCE D'ETUDIANT:  ------ %d/%d/%d\n", student[i].birthdate.jour, student[i].birthdate.mois, student[i].birthdate.annee);
             printf(" --- LA DEPARTEMENT D'ETUDIANT:  ------------ %s\n", student[i].departemenet);
             printf(" --- LA NOTE GENERALE D'ETUDIANT:  ---------- %.2f\n", student[i].note);
             printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
       }
     }
}
int main()
{

    Etudiant etudiant1[max_etudiant];

    while (1)
    {
        printf("-----------------------MENU----------------------\n");
        printf("1- Entrer 1 pour AJOUTER un Etudiant\n");
        printf("2- Entrer 2 pour MODIFIER les informations d'un Etudiant\n");
        printf("3- Entrer 3 pour AFFICHER les informations des Etudiant\n");
        printf("4- Entrer 4 pour SUPPRIMER les informations d'un Etudiant\n");
        printf("5- Entrer 5 pour CALCULER la moyenne generale d'une departement \n");
        printf("6- Entrer 6 pour STATISTIQUES \n");
        printf("7- Entrer 7 pour RECHERCHER les infos d'un Etudiant\n");
        printf("8- Entrer 8 pour TRIER les etudiants par ordre alphabetiques\n");
        printf(" -------------------------------------------------\n");
        printf("Entrer votre choix : ");
        scanf("%d", &choix );

        switch (choix)
        {

        case 1:

            ajouter(etudiant1);
            count++;
            break;

        case 2:

            modifier(etudiant1);
            break;

        case 3:

            afficher(etudiant1);
            break;

        case 4:

            supprimer(etudiant1);
                  break;

        case 5:

            calculermoyenne(etudiant1);
                  break;
        case 6:

            statistiques(etudiant1);
                  break;
        case 7:

            Rechercher(etudiant1);
                  break;

        /*case 8:

            modifier(etudiant1);
                  break;*/
        }

    }


    return 0;

}
