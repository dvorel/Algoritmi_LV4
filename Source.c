#include<stdio.h>
#include<stdlib.h>
typedef struct CVOR {
	char d;
	struct CVOR* left;
	struct CVOR* right;
}cvor;

int nadjip(char d);
void dodajp(char d);
void preOrder(cvor* root);
void inOrder(cvor* root);
void postOrder(cvor* root);
void tablica(cvor*);
cvor* root = NULL, * nadred = NULL;


int count = 0;

int main(void) {
	char polje[] = { 'D','A','V','I','D','V','O','R','E','L', '\0' };
	for (int i = 0; polje[i] != '\0'; i++) {
		dodajp(polje[i]);
	}
	tablica(root);
	preOrder(root);
	printf("\n");
	inOrder(root);
	printf("\n");
	postOrder(root);
	printf("\n");
}

int nadjip(char d) {
	int br = 0; //nadjen
	cvor* temp = root;
	nadred = NULL;
	if (temp == NULL) {
		return -1;
	}
	while (1) {
		if (temp->d == d) {
			br = 1;
		}
		else {
			nadred = temp;
			if (temp->d > d) {
				if (temp->left != NULL)temp = temp->left;
				else br = -1;
			}
			else
				if (temp->right != NULL)temp = temp->right;
				else br = -1;
		}
		if (br == 1 || br == -1)break;


	}
	return br;
}


void dodajp(char d) {

	int br = 0;
	br = nadjip(d);
	if (br == 1) {
		return;
	}
	else {
		cvor* n = (cvor*)malloc(sizeof(cvor));
		n->d = d;
		n->left = n->right = NULL;
		if (nadred == NULL) {
			root = n;
		}
		else {
			if (nadred->d > n->d)nadred->left = n;
			else nadred->right = n;
		}
		count++;
	}
}
void preOrder(cvor* root) {
	if (root == NULL) return;
	else {
		printf("%c", root->d);
		preOrder(root->left);
		preOrder(root->right);
	}
}
void inOrder(cvor* root) {

	if (root == NULL) {

		return;
	}
	else {

		inOrder(root->left);
		printf("%c", root->d);
		inOrder(root->right);
	}

}
void postOrder(cvor* root) {

	if (root == NULL) {

		return;
	}
	else {

		postOrder(root->left);
		postOrder(root->right);
		printf("%c", root->d);
	}

}
 
void tablica(cvor* root)
{
	cvor* R;
	cvor* L;

	if (root == NULL) {
		return;
	}
	else{
		R = root->right;
		L = root->left;

		printf("\n%c\t", root->d);
		if (L != NULL) {
			printf("L = %c\t", L->d);
		}
		else {
			printf("L = nan\t");
		}

		if (R != NULL) {
			printf("R = %c\n", R->d);
		}
		else {
			printf("R = nan\n");
		}

		if (R != NULL) {
			tablica(R);
		}
		if (L != NULL) {
			tablica(L);
		}
	}
}
