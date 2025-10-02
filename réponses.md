# TP Cryptanalyse
## Question 2
Nous avons écrit Question2.c qui une fois compilé permet de hasher une chaine de caractère et de print le hashé.

<img src="./Question2.png" alt="Question 2" width="600">

## Question 3
Nous avons écrit Question3.c qui permet de déchiffrer un mot de passe avec une lettre.

<img src="./Question3.png" alt="Question 3" width="300">

## Question 4
Pour traiter des mots de passe à plus d'une lettre, on à décider de créer une fonction qui permet d'incrémenter les lettres une par une. On l'appel dans une boucle wihle qui incrémente tant que le mot de passe n'est pas égale à zzz.

    void incrementerPswd()
    {
        for (int i = 0; i <= nbrCaratere; i++)
        {
            if (pswdTested[i] == 'z')
            {
                pswdTested[i] = 'a';
            }
            else
            {
                if (pswdTested[i] == '\0')
                {
                    return;
                }
                pswdTested[i]++;
                return;
            }
        }
}

<img src="./Question4.png" alt="Question 3" width="300">

## Question 5
Sur la base de la question 4 on a realiser une boucle for qui permet de chercher des mots de passe de plus en plus long. Pour cela on reitere la fonction *testPswd()* en augmentant la taille du mot de passe cherchee a travers *nbrCaratere*. A chaque iteration, on reinitialise le premier et le dernier mot de passe recherché.

    for (; nbrCaratere <= tailleMax; nbrCaratere++)
    {
        initialisation();
        if (testPswd() == 0)
        {
            return 0;
        }
        printf("on a teste tous les mots de passe de taille %d\n",nbrCaratere);
    }

## Mot de passe trouvés: 

    r
    hey
    sflkn
    bqjdg
    dghvgg
