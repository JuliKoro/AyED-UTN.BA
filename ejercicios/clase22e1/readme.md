# Clase 22 Plantillas - Ejericio 1:
Modificar la siguiente función para que realice búsquedas en listas de estructura de tipo **Nodo** definido como plantilla:
`Nodo* buscarEnLista(Nodo *l, int v){
Nodo* aux = l;
while(aux!=NULL&&aux->info != v){
aux=aux->sig;
}
return aux;
}`
La plantilla de función deberá recibir un puntero a una función con el criterio de ordenamiento (compatible con **T**) que evaluará si algún nodo de la lista **l** y el parámetro de búsqueda (**v**) coinciden. La firma de la nueva función:
`Nodo<T>* buscarEnLista(Nodo<T>*l, T v, int(*criterio)(T,T) )`