    #include "List.h"

    template <class dataType , class keyType>
    /* constructor */
	List<keyType,dataType> :: List(){
		head = cursor = prev = NULL; 
	}
	/* destructor */
	
	List<keyType,dataType> ::~List()
	{
		makeListEmpty();   /* deallocate all linked nodes in heap */
	}
    
  
	bool List<keyType,dataType>:: isListEmty (){ return head   == NULL ;  }
	
	bool List<keyType,dataType>:: isCurEmpty (){ return cursor == NULL ;  }    
    
   
    /* check if cursor point to head node ? */
    bool List<keyType,dataType>:: atFirst() {return cursor == head; }

    void List<keyType,dataType>:: toFirst()  {cursor = head ; 	prev = NULL;}
    
    int List<keyType,dataType>::listSize () const { return NodesCounter ; }

   
    /* check if cursor at tail or if list is empty */
    bool List<keyType,dataType>:: atEnd() const 
    { isListEmty() ? return true : return (cursor->next == NULL) ;  }

    
    void List<keyType,dataType>::toEnd () 
    { if (!isListEmty()) 
      {
      	cursor = head ; 
    	while(cursor->next != NULL) cursor = cursor->next;
      }
    }

    
    void List<keyType,dataType>:: traverse ()
    {
    	cursor = head ;
    	cout << "List is : " ;  
    	while(cursor->next != NULL) 
    		{
    			cout << cursor->data ; 
    			advance();
    		}
    	cout << endl ; 
    }
    
    /* delete current node */
    
    void List<keyType,dataType>::deleteNode(){
    if (isListEmty()) 
    { 
   	cout << "Error : not allowed to delete from empty list " << endl ;
    }	
    
    else if (!isCurEmpty()) { 
     	
    		ptrToNode temp = cursor ; /* temp to keep wanted node */ 
    		advance();
    		delete temp;       		  /* delete wanted node */
      	}	 
    }

    
    void List<keyType,dataType>::deleteFirst()
    {
    if (isListEmty()) 
    { 
   	cout << "Error : not allowed to delete from empty list " << endl ;
    }	
    else 
    {
    cursor = head ; 
    head = head ->next ; 
    delete cursor ;  
    }	
    }
   

    
    void List::<keyType,dataType>retrieveData(dataType &myData)
    {
    	if (!isCurEmpty()) myData = cursor->data ;  
    }

    
	void List<keyType,dataType>::updateData (const dataType & myData) {
    if (!isCurEmpty()) cursor->data = myData ;  
	}    

	
	void List<keyType,dataType>::advance () { cursor = cursor->next ; }

	
	void List<keyType,dataType>::insertFirst (const keyType & myKey, const dataType & myData) 
		{   
			NodesCounter ++ ; 
			ptrToNode temp = new Node();	
            temp->data = myData ; 
            temp->key = myKey ; 
            temp->next = head ;    
            cursor = head = temp ; 
            prev = NULL; 
	    }


    
	void List<keyType,dataType>::insertAfter (const keyType &myKey, const dataType & myData)
	{
	NodesCounter ++ ; 	
	if (isListEmty()) insertFirst(&myKey,&myData);
	else 
	{	
		ptrToNode temp = new Node();	
        temp->data = myData ; 
        temp->key =  myKey ; 
		cursor = head ;
		while (cursor->key <= myKey)  advance();
		prev = cursor ; 
		temp->next = cursor->next ; 
		cursor->next = temp ; 
	}

	}





	
	void List<keyType,dataType>:: insertBefore (const keyType &myKey, const dataType & myData)
	{
	NodesCounter ++ ; 	
	if (isListEmty()) insertFirst(&myKey,&myData);
	else 
	{	
		ptrToNode temp = new Node();	
        temp->data = myData ; 
        temp->key =  myKey ;

		while (cursor->key > myKey)  advance();
		cursor->prev = temp;   
		temp->next = cursor; 
		
	}


	}

	void List<keyType,dataType>::insertEnd (const keyType &myKey, const dataType & myData)
	{
		NodesCounter ++ ; 
		ptrToNode temp = new Node();	
        temp->data = myData ; 
        temp->key =  myKey ; 
        temp->next = NULL ;
		if (isListEmty()) head = cursor = temp ; 
		else { 
		cursor = head ; 
    	while(cursor->next != NULL)  advance();
    	prev = cursor ; 
    	cursor->next = temp ; 	
    	cursor = temp ;  	/* make the cursor point to the new node */
		}

	}


    void List<keyType,dataType>::mskeListEmpty()
    {
    	if(!isListEmty())
    	while (cursor != NULL ) {delete cursor ; advance();}
    }
	

    bool List<dataType,keyType>::searchElement (const keyType & myKey) 
    {
    	toFirst(); 
    	while(cursor != NULL) 
    		{
    			if(cursor->key == myKey) { return true ;} 
    			advance();
    		}
    	return false ; 
    }





};
