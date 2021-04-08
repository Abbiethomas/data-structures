Abbie Thomas
811846546
agt96353@uga.edu

To compile code:
   $ make main

To run program:
   $ ./main input.txt

Merge function:
      Set position to given list's head
      set moreToSearch to (position != NULL)
      Print both lists
      while moreToSearch
      	    if(position item isDuplicate) {
	    	print "cannot insert duplicate item"
		return
	    }
	    insertItem at position
	    Set position equal to position->next
	    set moreToSearch to (position != NULL)
      print new list

      
      big O = O(n)
      The while loop iterates through the list to be merged and all the other
      	  lines are constant.
      In order to compare the values of two lists, the function must loop through
      	  at least the length of the list, making this the most efficient big O.
	  A less efficient way to do this would be a nested loop.

Find Common Elements:
     Print both lists
     Set position to calling list's head
     set moreToSearch to (position != NULL)
     while moreToSearch
     	   Set location to given list's head
	   set more to (location != NULL)
	   set common to false
	   while more
		 switch position's item compared to location's item
		 case GREATER
		      set location to location->next
		      set more to (location != NULL)
		 case EQUAL
		      set common to true
		      set more to false
		 case LESS	
  		      set more to false
	  if common is false
	     	delete position's item
	  set position to position->next
	  set moreToSearch to (position != NULL)
     print new list

     
     big O = O(n^2)
     The while loops are nested. The first loop iterates the length of the calling list 
     	 while the second loop iterates up to the length of the given list.
     Since each element of the calling loop must be compared to elements of the given list,
     	 there is a posiblity that it must be compare to each one. This means that 
	 n^2 is the most efficient this function can be.
		
