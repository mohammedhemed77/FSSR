    #include "List.h"

    template <class dataType , class keyType>
    /* constructor */
	List<dataType,keyType> :: List(){
		head = NULL ;   cursor =  NULL;    prev = NULL ;
	}
	/* destructor */
	template <class dataType , class keyType>
	List<dataType,keyType> ::~List()
	{
		makeListEmpty();   /* deallocate all linked nodes in heap */
	}

    template <class dataType , class keyType>
	bool List<dataType,keyType>:: isListEmpty ()const{ return head   == NULL ;  }
	template <class dataType , class keyType>
	bool List<dataType,keyType>:: isCurEmpty ()const{ return cursor == NULL ;  }


    /* check if cursor point to head node ? */
    template <class dataType , class keyType>
    bool List<dataType,keyType>:: atFirst() const{return cursor == head; }
    template <class dataType , class keyType>
    void List<dataType,keyType>:: toFirst()  {cursor = head ; 	prev = NULL;}
    template <class dataType , class keyType>
    int List<dataType,keyType>::listSize () const { return NodesCounter ; }


    /* check if cursor at tail or if list is empty */
    template <class dataType , class keyType>
    bool List<dataType,keyType>:: atEnd() const
    {
        if (isListEmpty())
            return true;
        else
            return (cursor->next == NULL) ;
    }

    template <class dataType , class keyType>
    void List<dataType,keyType>::toEnd ()
    { if (!isListEmpty())
      {
      	cursor = head ;
    	while(cursor->next != NULL) cursor = cursor->next;
      }
    }

    template <class dataType , class keyType>
    void List<dataType,keyType>:: traverse ()
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
    void List<dataType,keyType>::deleteNode(){
    if (isListEmpty())
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
    void List<dataType,keyType>::deleteFirst()
    {
    if (isListEmpty())
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
    void List<dataType,keyType>::retrieveData(dataType &myData) const
    {
    	if (!isCurEmpty()) myData = cursor->data ;
    }

    template <class dataType , class keyType>
	void List<dataType,keyType>::updateData (const dataType & myData) {
    if (!isCurEmpty()) cursor->data = myData ;
	}

	template <class dataType , class keyType>
	void List<dataType,keyType>::advance () { cursor = cursor->next ; }

	template <class dataType , class keyType>
	void List<dataType,keyType>::insertFirst (const keyType & myKey, const dataType & myData)
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
	void List<dataType,keyType>::insertAfter (const keyType &myKey, const dataType & myData)
	{
	NodesCounter ++ ;
	if (isListEmpty()) insertFirst(&myKey,&myData);
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
	void List<dataType,keyType>:: insertBefore (const keyType &myKey, const dataType & myData)
	{
	NodesCounter ++ ;
	if (isListEmpty()) insertFirst(&myKey,&myData);
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
	void List<dataType,keyType>::insertEnd (const keyType &myKey, const dataType & myData)
	{
		NodesCounter ++ ;
		ptrToNode temp = new Node();
        temp->data = myData ;
        temp->key =  myKey ;
        temp->next = NULL ;
		if (isListEmpty()) head = cursor = temp ;
		else {
		cursor = head ;
    	while(cursor->next != NULL)  advance();
    	prev = cursor ;
    	cursor->next = temp ;
    	cursor = temp ;  	/* make the cursor point to the new node */
		}

	}

    template <class dataType , class keyType>
    void List<dataType,keyType>::makeListEmpty()
    {
    	if(!isListEmpty())
    	while (cursor != NULL ) {delete cursor ; advance();}
    }


    template <class dataType , class keyType>
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
