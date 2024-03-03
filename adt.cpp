#include <iostream>
#include <cstdlib>

struct something{
    int total;
    int used;
    int *ptr;
};

void createarr(struct something *a, int t, int u){
    a->total=t;
    a->used=u;
    a->ptr=(int *)malloc(t*sizeof(int));

}

void setvalue(struct something *a){
    for (int i = 0; i<a->used; i++){
        std::cout << "Enter the number" << std::endl;
        std::cin >> (a->ptr)[i];
    }
}

void throwvalue(struct something *a){
    for (int i = 0; i<a->used; i++){
        std::cout << (a->ptr)[i] << std::endl;
    }
}


int main(){
    struct something world;
    createarr(&world,20,2);
    setvalue(&world);
    throwvalue(&world);
    free(world.ptr);
    return 0;
}