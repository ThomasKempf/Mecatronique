# TP Simulationdefeudeforêt
## Question 2
J'ai modifié les probabilités d'apparition, du coup les arbres apparaissent beaucoup moins vite

    #define TREE_PROB   0.006 -> #define TREE_PROB   0.001 
    #define BURN_PROB   0.00001 -> #define BURN_PROB   0.0001

## Question 3
La variable utiliser pour stocker l'état des cellules est **univ[y][x]**, on peut voir ci dessous la ligne qui permet d'actualiser l'état des cellule à la fin de la boucle

    FOR_YX { univ[y][x] = next_univ[y][x]; }    //update universe

## Question 4
La fonction **check_neighbors** est constituer de deux boucle for pour tester chaque cellule voisine. Après avoir vérifier que l'ont teste pas sa propre cellule, on retourne **fire** si le voisin l'est aussi.

    for (int x_neighbors = -1; x_neighbors <= 1; x_neighbors++)
    {
        for (int y_neighbors = -1; y_neighbors < 1; y_neighbors++)
        {
            if (!(y_neighbors == 0 && x_neighbors == 0))
            {
                if (univ[y + y_neighbors][x + x_neighbors] == fire)
                {
                    return fire;
                }
            } 
        } 
    }
<img src="./Question4.png" alt="Question 4" width="600">


## Question 5
l'ajout de la cendre peut être observer sur l'image avec les @ qui ne sont pas à fond rouge

    FOR_YX {        //loop through each cell
    switch (univ[y][x]) {
        case fire:
            next_univ[y][x] = cendre;
            break;
        case empty:
            if (CHANCE(TREE_PROB)) next_univ[y][x] = tree;
            break;
        case cendre:
            next_univ[y][x] = empty;
            break;
<img src="./Question5.png" alt="Question 5" width="600">