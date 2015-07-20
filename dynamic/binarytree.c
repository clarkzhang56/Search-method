#include <stdio.h>
#include <malloc.h>

typedef struct Node{
	int value;
	struct Node *lNode;
	struct Node *rNode;
}BinaryTree;
void InsertNode(BinaryTree *root, BinaryTree *node){
 	if(root->value < node->value){
   		if(root->rNode == NULL) root->rNode = node;
   		else InsertNode(root->rNode, node);
   		return ;
  	}else if(root->value > node->value){
  		if(root->lNode == NULL) root->lNode = node;
  		else InsertNode(root->lNode, node);
		return ;
  	}else return ;
}
void CreateTree(BinaryTree **root, int a[], int n){
	if(n<1)  return ;
	*root = (BinaryTree*)malloc(sizeof(BinaryTree));
	(*root)->value = a[0];
	(*root)->lNode = NULL;
	(*root)->rNode = NULL;
	int i;
	for(i=1; i<n; i++){
		BinaryTree *node = (BinaryTree*)malloc(sizeof(BinaryTree));
		node->value = a[i];
		node->lNode = NULL;
		node->rNode = NULL;
		InsertNode(*root, node);
	}
}
BinaryTree *SearchNode(BinaryTree *root, BinaryTree **parent, int key){
 	if(root == NULL) return NULL;
 	if(root->value == key){
		 return root;
	} 
 	else if(root->value > key){
		 *parent = root;
 		 return SearchNode(root->lNode,parent,key);
 	}
	else if(root->value < key){
		 *parent = root;
 		 return SearchNode(root->rNode,parent,key);
	}
 	return NULL;
}
void ShowTree(BinaryTree *root){
 	 if(root->lNode != NULL){
  		 ShowTree(root->lNode);
 	 }
 	 printf("%3d ",root->value);
 	 if(root->rNode != NULL){
 		 ShowTree(root->rNode);
	 }
}
void DeleteTree(BinaryTree *root, int key){
	BinaryTree *parent = NULL;
 	BinaryTree *deletenode = SearchNode(root,&parent,key);
	if(deletenode == NULL){
  		printf("\nIt's not here!\n");
  		return ;
 	}
	if((deletenode->lNode == NULL) && (deletenode->rNode == NULL)){
		if(parent == NULL){
			root = NULL;
		} 
		else if(parent->lNode == deletenode) {
			parent->lNode = NULL;
		}
		else if(parent->rNode == deletenode) {
			parent->rNode = NULL;
		}
		free(deletenode);
 	}else if((deletenode->rNode == NULL) && (deletenode->lNode != NULL)){
  		BinaryTree *tmp = deletenode->lNode;
  		deletenode->value = tmp->value;
  		deletenode->rNode = tmp->rNode;
		deletenode->lNode = tmp->lNode;
  		free(tmp);
 	}else if(deletenode->lNode == NULL && deletenode->rNode != NULL){
  		BinaryTree *tmp = deletenode->rNode;
  		deletenode->value = tmp->value;
  		deletenode->rNode = tmp->rNode;
		deletenode->lNode = tmp->lNode;
  		free(tmp);
 	}else{
  		BinaryTree *tmp = deletenode;
  		BinaryTree *child = deletenode->lNode;
  		while(child->rNode){
			tmp = child;
   		child = child->rNode;
  		}
  		deletenode->value = child->value;
  		if(tmp!=deletenode) tmp->rNode=child->lNode;
  		else tmp->lNode=child->lNode;
  		free(child);
 	}
}
void DestoryTree(BinaryTree *root){
	if(root == NULL) 	return ;
	if(!root->lNode)	DestoryTree(root->lNode);
	if(!root->rNode)	DestoryTree(root->rNode);
	if(root->lNode == NULL && root->rNode == NULL){
		free(root);
		root = NULL;
	}
}
int main(int argc, char **argv)
{
	int a[] = {8,11,6,7,19,9,22,20};
	int n = sizeof(a)/sizeof(int);
	BinaryTree *root = NULL;
 	CreateTree(&root, a, n);
	ShowTree(root);

 	int del = 20;
	DeleteTree(root,del);
	printf("\n:::\n");
 	ShowTree(root);
	DestoryTree(root);
 	return 0;
}

