#include "AB.h"

int main(){
    nodo *tree;
    tree = NULL;

    tree = grow(tree, 1);
    tree = grow(tree, 5);
    tree = grow(tree, 2);
    tree = grow(tree, 6);
    tree = grow(tree, 12);
    tree = grow(tree, 15);
    tree = grow(tree, 9);

    ver(tree,"pre");
    ver(tree,"in");
    ver(tree,"post");

    trim(&tree, 2);

    ver(tree,"pre");
    ver(tree,"in");
    ver(tree,"post");
}