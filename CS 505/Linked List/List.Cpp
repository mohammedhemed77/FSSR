    #include "List.h"

    template <class dataType , class keyType>
    /* constructor */
	List::List(){
		head = cursor = prev = NULL; 
	}
	/* destructor */
	template <class dataType , class keyType>
	List::~List(){
		makeListEmpty();   /* deallocate all linked nodes in heap */
	}
    
    template <class dataType , class keyType>
	bool isListEmty (){ return head   == NULL ;  }
	
	template <class dataType , class keyType>
	bool isCurEmpty (){ return cursor == NULL ;  }    
    
    template <class dataType , class keyType>
    /* check if cursor point to head node ? */
    bool atFirst() {return cursor == head; }

	template <class dataType , class keyType>
    void toFirst()  {cursor = head ; 	prev = NULL;}

    template <class dataType , class keyType>
    int listSize () const { return NodesCounter ; }

    template <class dataType , class keyType>
    /* check if cursor at tail or if list is empty */
    bool atEnd() const 
    { isListEmty() ? return true : return (cursor->next == NULL) ;  }

    template <class dataType , class keyType>
    void toEnd () 
    { if (!isListEmty()) 
      {
      	cursor = head ; 
    	while(cursor->next != NULL) cursor = cursor->next;
      }
    }

    template <class dataType , class keyType>
    void traverse ()
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
    template <class dataType , class keyType>
    void deleteNode(){
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

    template <class dataType , class keyType>
    void deleteFirst()
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
   

    template <class dataType , class keyType>
    void retrieveData(dataType &myData)
    {
    	if (!isCurEmpty()) myData = cursor->data ;  
    }

    template <class dataType , class keyType>
	void updateData (const dataType & myData) {
    if (!isCurEmpty()) cursor->data = myData ;  
	}    

	template <class dataType , class keyType>
	void advance () { cursor = cursor->next ; }

	template <class dataType , class keyType>
	void insertFirst (const keyType & myKey, const dataType & myData) 
		{   
			NodesCounter ++ ; 
			ptrToNode temp = new Node();	
            temp->data = myData ; 
            temp->key = myKey ; 
            temp->next = head ;    
            cursor = head = temp ; 
            prev = NULL; 
	    }


	template <class dataType , class keyType>    
	void insertAfter (const keyType &myKey, const dataType & myData)
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





	template <class dataType , class keyType>    
	void insertBefore (const keyType &myKey, const dataType & myData)
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

	template <class dataType , class keyType>    
	void insertEnd (const keyType &myKey, const dataType & myData)
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

	template <class dataType , class keyType>
    void mskeListEmpty()
    {
    	if(!isListEmty())
    	while (cursor != NULL ) {delete cursor ; advance();}
    }
	
	template <class dataType , class keyType>
    bool search (const keyType & myKey) 
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
