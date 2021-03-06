// Naive implementation of find

/*
element i has a parent stored in parent[i]
the root element of the set tree has parent[i]=-1
find returns the root of the set tree
union(x,y) changes x's root to the root of y

linear time complexity

Let there be 4 elements in the array0, 1, 2, 3

Initially all elements are single element subsets.
0 1 2 3

Do Union(0, 1)
   1   2   3
  /
 0

Do Union(1, 2)
     2   3
    /
   1
 /
0

Do Union(2, 3)
         3
        /
      2
     /
   1
 /
0

*/
//note that in the array of elements we have initially, value of elements is equal to their index
//only then find operation is supported
//Otherwise, first we will have to find the index of the element whose set no. we want, then pass the index to find function, not the value

void makeSet(int parent[],int size)
{
	for(int i=0;i<size;i++)
	{
		parent[i]=-1;
	}
}


//find takes O(n) time
//returns the set in which the element is present
int find(int parent[], int i)
{
	//also include the condition if i is not in any set if required
	//not included here

    if (parent[i] == -1)
        return i;

    return find(parent, parent[i]);
}

// Naive implementation of union()
//union merges the set of first element into the set of second one
void Union(int parent[], int x, int y)
{
    int xset = find(parent, x);
    int yset = find(parent, y);

	if(!(xset==yset))
    parent[xset] = yset;
}
