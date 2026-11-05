typedef struct{
    char caracter;   
} Elem;

typedef struct Nodo{
    Elem elem;
    struct Nodo *prox;
} Nodo;

typedef struct{
    Nodo *topo;
} Pilha;

void push(Pilha *pilha, Elem elem){
    Nodo *novo = malloc(sizeof(Nodo));

    if(novo == NULL){
        return;
    }

    novo->elem = elem;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

void pop(Pilha *pilha){
    Nodo *remove;
    
    if(pilha->topo == NULL){
        return;
    }

    remove = pilha->topo;
    pilha->topo = remove->prox;
    free(remove);
}

bool isValid(char* s) {
    Pilha pilha;
    Elem elem;

    pilha.topo = NULL;

    int i = 0;
    while(s[i] != '\0'){

    if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
        elem.caracter = s[i];
        push(&pilha, elem);
    }

    else if(s[i] == ')' || s[i] == '}' || s[i] == ']'){

        if(pilha.topo == NULL){
            return false;
        }

        if((s[i] == ')' && pilha.topo->elem.caracter != '(') ||
           (s[i] == ']' && pilha.topo->elem.caracter != '[') ||
           (s[i] == '}' && pilha.topo->elem.caracter != '{')){

            return false;
        }

        pop(&pilha);
    }

    i++;
}
    if (pilha.topo == NULL){
        return true;
    }
    return false;
}
