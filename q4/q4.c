#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h> 

int main() {

    int a,b;
    void* lib=NULL;
    char str[10];
    char end[6]="";
    while(1){
        scanf("%s %d %d",str,&a,&b);
        if(lib)
        {
            dlclose(lib);
            lib=NULL;
        }

        char name[30];
        strcpy(name,"./lib");
        strcat(name,str);
        strcat(name,".so");
        // so its [name]=./lib[str].so
        lib=dlopen(name,RTLD_LAZY);
        typedef int (*func)(int,int); //function definition
        func f1=(func)(dlsym(lib,str));
        printf("%d\n",f1(a,b));
    }
    if (lib) dlclose(lib);
    return 0;
}
