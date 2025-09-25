# TP Simulationdefeudeforêt
## Question 2
j'ai modfier les probabiltié d'apparition, ducou les arbres apparaisse beaucoup moins vite

    #define TREE_PROB   0.006 -> #define TREE_PROB   0.001 
    #define BURN_PROB   0.00001 -> #define BURN_PROB   0.0001

## Question 3
La variable utiliser pour stocker l'état des cellules est **univ[y][x]**, in peut voir ci dessous la ligne qui permet d'actualier l'état des cellule à la fin de la boucle

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
