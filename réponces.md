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