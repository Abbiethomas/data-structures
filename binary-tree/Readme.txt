Abbie Thomas
811846546
agt96353@uga.edu

To compile code:
   $make main

To run program:
   $ ./main [input.txt file]

-------getNumSingleParent function
   set int total to 0
   call isSingle(root, total)
   return total

   ---isSingle(tree, total)
      if the tree is not NULL
      	 if tree->left is NULL and tree->right is not NULL or
	  tree->left is not NULL and tree->right is NULL
	      add 1 to total
	 call isSingle on tree->right and total
	 call isSingle on tree->left and total     

Since isSingle is a recursive function that checks each node of the tree,
the complexity of getNumSingleParent is O(N).

-------getNumLeafNodes function
   set leaf to 0
   call isLeaf(root, leaf)
   return leaf

   ---isLeaf(tree, leaf)
      if tree is not NULL
      	 if tree->left and tree->right are NULL
	    add 1 to leaf
	 call isLeaf on tree->right and leaf
	 call isLeaf on tree->left and leaf
	 
Since ifLeaf is a recursive function that checks each node of the tree,
the complexity of getNumLeafNodes is O(N).

-------getSumOfSubtrees function
   set sum to 0
   set tempNode to root
   set found to false
   call find(tempNode, item, found)
   if(found)
      call sumSub(tempNode->right, sum)
      call sumSub(tempNode->left, sum)
   else 
      set sum to -1
   return sub

   ---find(&tree, item, &found)
      if tree is NULL
      	 set found to false
      else if item > tree->key
         set tree to tree->right
	 find(tree, item, found)
      else if item < tree->key
      	 set tree to tree->left
	 find(tree, item, found
      else
         set found to true			

   ---sumSub(tree, sum)
      call sumSub(tree->right, sum)
      call sumSub(tree->left, sum)
      add tree->key's value to sum


Find has a complexity of O(N) in the worst case scenario and sumSub has a
complexity of O(N) in the worst case scenario. Therefore, getSumOfSubtrees 
has a complexity of O(N).	  
