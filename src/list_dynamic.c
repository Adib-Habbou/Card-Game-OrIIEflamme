
#include "../headers/list_dynamic.h"

struct listD {
    element* list;
    int size_list;
    int capacite_max;
};


listD listD_vide(){
    listD list = malloc(sizeof(listD));
    list->list = (element*) malloc(INITSIZE*sizeof(element));
    list->size_list = 0;
    list->capacite_max = INITSIZE;
    return list;
}

int listD_est_vide(listD _listD){
    return _listD->size_list == 0;
}

element get(listD _listD, int index){
    if(index >= _listD->size_list || index < 0){
        printf("ERROR : indice incorrect\n");
        exit(1);
    }
    element e = (element) _listD->list[index];
    return e;
}

element set(listD* _listD, int index, element _element){
    if(index < 0){
        printf("ERROR : indice incorrect\n");
        exit(1);
    }
    if((*_listD)->capacite_max <= index){
        listD tmp = malloc(sizeof(listD));
        tmp->size_list = index;
        int newcapacite = (index - (*_listD)->capacite_max < ADDSIZE)?((*_listD)->capacite_max + ADDSIZE) : (index + ADDSIZE);
        tmp->list = (element*) malloc((newcapacite)*sizeof(element));
        tmp->capacite_max = newcapacite;
        for(int i = 0; i < (*_listD)->size_list; i++){
            tmp->list[i] = (*_listD)->list[i];
        }
        for(int i = (*_listD)->size_list; i < tmp->capacite_max; i++){
            tmp->list[i] = (int*) -1;
        }
        tmp->list[index] = _element;
        element e = (*_listD)->list[index];
        *_listD = tmp;
        (*_listD)->size_list = index+1;
        return e;
    }else{
        if((*_listD)->size_list <= index){
            for(int i = (*_listD)->size_list; i < index; i++){
                (*_listD)->list[i] = (int*) -1;
            }
            (*_listD)->size_list = index+1;
        }
        element e = (*_listD)->list[index];
        (*_listD)->list[index] = _element;
        return e;
    }
}

element remove_byindex(listD* _listD, int index){
    if(index >= (*_listD)->size_list){
        printf("ERROR : indice incorrect\n");
        exit(1);
    }
    element e = (*_listD)->list[index];
    for(int i = index+1; i < (*_listD)->size_list; i++){
        (*_listD)->list[i-1] = (*_listD)->list[i];
    }
    (*_listD)->size_list--;
    return e;
}

int taille_listD(listD _listD){
    return _listD->size_list;
}

void add_list(listD* _listD, element _element){
    set(_listD, taille_listD(*_listD), _element);
}

element pop_list(listD* _listD){
    element e = (element) (*_listD)->list[(*_listD)->size_list-1];
    (*_listD)->size_list--;
    return e;
}

void affiche_liste(listD _listD){
    printf("[");
    for(int i = 0; i < _listD->size_list-1; i++){
        printf(" %p,", _listD->list[i]);
    }
    printf(" %p]\n", _listD->list[_listD->size_list-1]);
}