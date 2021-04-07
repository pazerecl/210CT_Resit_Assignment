#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int TrailZeros(int x)			//First Task
{
	int c = 0;
	for (int i = 5; x / i >= 1; i *= 5) //dividing the number by powers of 5
		c += x / i;

	return c;

}//BigO for this funcion is O(2Log n)

//Matrix addition				//Second Task
//Declare:					
//	matrix A(r)(c);
//	matrix B(r)(c);
//	matrix C(r)(c);
//	r = rows, c = colluns;
//
//Start read  r, c, A()() and B()()
//declare x = 0,y = 0
//
//loop until x<r
//	loop until y<c
//		C(x)(y)=A(x)(y)+B(x)(y)
//		set  y=y+1
//	set x=x+1
//
//return C
// BigO = O(n^2)

//Matrix subtraction
//Declare:					
//	matrix A(r)(c);
//	matrix B(r)(c);
//	matrix C(r)(c);
//	r = rows, c = colluns;
//
//Start read r, c, A()() and B()()
//declare x = 0 ,y = 0
//
//loop until x<r
//	loop until y<c
//		C(x)(y)=A(x)(y)-B(x)(y)
//		set y=y+1
//	set x=x+1
//
//return C
// BigO = O(n^2)

//Matrix multiplication
//Declare:					
//	matrix A(a)(b);
//	matrix B(c)(d);
//	matrix C(a)(d);
//	
//Start read a,b,c,d;
//Check if multiplication can be done, if b is not equal to d matrix can not be multiplied, generate an error message 
//Start read A()(),B()();
//declare x=0 , y=0 , z=0 , total=0;
//Repeat until x < a
//		Repeat until y < d
//				Repeat until z < c;
//							Set total = total + A(x)(z) * B(z)(y);
//							Set multiply(x)(y) = total;
//							Set total = 0 and z = z +1;
//							Set y= y+1;
//				Set x=x+1;
//return C
//BigO = O(n^2)

//A=B*C-2*(B+C)

//BigO for A=B*C-2*(B+C) is O(n^2)+(O(n^2))

//						Third Task
void revOrder(string word)
{
	if (word.size() == 0)
	{
		return;
	}
	revOrder(word.substr(1));
	cout << word[0];
}

//						Fourth Task
int RecLinSearch(int X[], int y, int nr)
{
	if (y < 0)
	{
		return -1;
	}
	if (X[y] == nr)
	{
		return y;
	}
	return RecLinSearch(X, y - 1, nr);
}
//						Fifth Task

void showstep(int A[], int x)
{
	int I;
	for (I = 0; I < x; I++)
	{
		cout << A[I] << " ";
	}
}
//Insertion sort
void insSort(int A[], int x)
{
	int I;
	int Nr;
	int J;
	for (I = 1; I < x; I++)
	{
		Nr = A[I];
		J = I - 1;
		
		cout << "STEP" << endl;
		showstep(A, x);
		cout << endl;

		while (J >= 0 && A[J] > Nr)
		{
			A[J + 1] = A[J];
			J = J - 1;
		}
		A[J + 1] = Nr;
	}
}
//Bubble sort;
void Switch(int* nr1, int* nr2)
{
	int t = *nr1;
	*nr1 = *nr2;
	*nr2 = t;
}
void bubSort(int A[],int x)
{
	int I;
	int J;
	for (I = 0; I < x - 1; I++)
	{
		
		for (J = 0; J < x - I - 1; J++)
		{
			cout << "STEP" << endl;
			showstep(A, x);
			cout << endl;
			if (A[J] > A[J + 1])
			{
				Switch(&A[J], &A[J + 1]);
			}
				
		}
	}	
}

//Selection sort;
void selSort(int A[], int x)
{
	int I;
	int J;
	int mini;

	for (I = 0; I < x - 1; I++)
	{
		mini = I;

		cout << "STEP" << endl;
		showstep(A, x);
		cout << endl;

		for (J = I + 1; J < x; J++)
		if (A[J] < A[mini])
		{
			mini = J;
		}
			
		Switch(&A[mini], &A[I]);

		
	}
}

//						Seventh task
class TreeNode
{
public:
	int item;

	TreeNode* left;
	TreeNode* right;
	TreeNode(int item)
	{
		this->item =item;
		this->left =NULL;
		this->right =NULL;
	}
};

TreeNode* TreeInsert(TreeNode* tree,int item)
{
	if(tree==NULL)
	{
		TreeNode* newtree =new TreeNode(item);
		tree =newtree;
		return tree;
	}
	
	if(tree->item >item)
	{
		tree-> left =TreeInsert(tree-> left , item);
	}

	else
	{
		tree-> right = TreeInsert(tree-> right , item);
	}
	return tree;
}

void TreeStore(TreeNode* tree, int A[], int &x)
{
	if (tree == NULL)
	{
		return;
	}

	TreeStore(tree->left,A, x);
	A[x] =tree-> item;
	x++;
	TreeStore(tree-> right,A, x);
}

void TreeSort(int A[], int SizeOf)
{
	TreeNode* tree =NULL;
	tree = TreeInsert(tree, A[0]);
	for (int i =1; i <SizeOf; i++)
	{
		TreeInsert(tree, A[i]);
	}
	int i = 0;
	TreeStore(tree, A,i);
}


int main(void)
{
	//FIRST TASK
	int x;
	cout << "Enter factorial number" << endl;
	cin >> x;
	cout << "Trailing 0s in " << TrailZeros(x) << endl;

	//THIRD TASK
	string words;
	cout << "Enter a sentence: "<< endl;
	getline(cin, words);
	revOrder(words);

	//FOURTH TASK
	int X[5] = {15,20,40,3,68};
	int position = RecLinSearch(X, 4, 68);

	if (position == -1)
		cout << "Number not found in array" << endl;
	else
		cout << "Number found at " << position << endl;

	//FIFTH TASK
	int A[] = { 2,7,9,4,1,5,3,6,0,8 };
	int B[] = { 2,7,9,4,1,5,3,6,0,8 };
	int C[] = { 2,7,9,4,1,5,3,6,0,8 };
	int x = sizeof(A) / sizeof(A[0]);
	int y = sizeof(B) / sizeof(B[0]);
	int z = sizeof(C) / sizeof(C[0]);

	insSort(A, x);	//3 comparison steps, 6 element move steps.
	cout << " Final Insertionsort: "; // Worst arrangement is reverse sorted;
	showstep(A, x);	
	cout << endl; 

	bubSort(B, y);  //3 comparison steps, 42 element move steps
	cout << " Final Bubblesort: ";	// Worst arrangement is reverse sorted;
	showstep(B, y);
	cout << endl;

	selSort(C, z);  //1 comparison steps, 8 element move steps
	cout << " Final Selectionsort: " << endl;	// Best performing method for sorting this array.
	showstep(C, z);					// Worst arrangement is reverse sorted;
	cout << endl;
	
	int array[]={2,4,1,3,5};
	int size = sizeof(array) / sizeof(int);
	TreeSort(array, size);

	//Binary Tree_Sort test
	cout << "sorted array: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}

	return 0;
}