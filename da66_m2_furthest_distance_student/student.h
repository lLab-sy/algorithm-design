#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node* n, int &aux){
	// You MAY use this function
	if(n == NULL) return -1;
    int mxL = 0, mxR = 0;
    int res = std::max(my_recur(n->left, mxL), my_recur(n->right, mxR));
    aux = 1+(std::max(mxL, mxR));
    return std::max(mxL+mxR, res);
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::furthest_distance() {
	// write your code here
	int mxd = 0;
    return my_recur(mRoot, mxd);
}

#endif
