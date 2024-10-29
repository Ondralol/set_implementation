#include <iostream>
#include <iomanip>

/* Custom template set implementation as Binary Search Tree (BST) */
template <typename T_>
class  CSet
{
  public:
		/* Constructor */
    CSet ( void )
    : m_Root (nullptr), m_Size (0)
    {};
   
	 /* Desctrucor */
   ~CSet( void )
    {
      /* Deletes recursively */
			delete m_Root;
    };
    
		/* Copy constructor */
    CSet ( const CSet<T_> & src )
    : m_Root ( src.m_Root ? src.m_Root -> clone() : nullptr ), 
      m_Size ( src.m_Size )
    {};
    
		/* Copy assignment operator */
    CSet & operator = ( CSet<T_> src) 
		{
      std::swap ( m_Root, src.m_Root );
      std::swap ( m_Size, src.m_Size);
      return *this;
    }

		/* Inserts element if element doesn't exist yet, returns true if element was inserted and false if it already existed in the set */
    bool Insert ( T_ x )
    {
			CNode * n = m_Root;
      CNode * p = nullptr;
      
			/* Finds the position where the new element should be placed */
			while ( n )
      {
        p = n;
				
				/* Element already exists in the set */
        if ( n -> m_Val == x )
          return false;
				
				/* Travel to left side of the tree */
        else if ( x < n -> m_Val )
          n = n-> m_L;
        
				/* Travel to right side of the tree*/
				else
          n = n -> m_R;
      }
      
			/* Creates new node */
      n = new CNode ( std::move(x) );
      
			/* If there is no root */
      if ( !p )
        m_Root = n;
      
			/* If its the left child of the node p */
      else if ( x < p -> m_Val )
        p -> m_L = n;
      
			/* If its the right child of node p */
      else 
        p -> m_R = n;

      m_Size ++;
      return true;
    }

    /* Deletes node, returns true if the node exists and false if it doesn't */
    bool Delete ( const T_ & x )
    {
      CNode ** n = &m_Root;
			
			/* Finds the node that needs to me removed and uses BST remove element algorithm to remove the node without breaking the tree */
      while ( *n )
      {
        /* If node was found */
				if ( (*n) -> m_Val == x )
        {
          CNode * toDel = *n;
					
					/* If node to be deleted has both left and right children */
          if ( toDel -> m_L && toDel -> m_R )
          {
            /* Finds rightmost leaf of the left subtree and replaces, this node will then replace the node that should be deleted */
						n = &(*n) -> m_L;
            while ( (*n) -> m_R )
              n = &(*n) -> m_R;
            
            toDel -> m_Val = (*n) -> m_Val;
            toDel = *n;
          }
					
					/* If node to be deleted only has left child */
          if ( toDel -> m_L )
            *n = toDel -> m_L;
          /* If node to be deleted only has right child */
					else
            *n = toDel -> m_R;
					
					/* Deleting node that is to be deleted */
          toDel -> m_R = toDel -> m_L = nullptr;
          delete toDel;
          m_Size --;

          return true;
        }
				
				/* Moves to the right subtree */
        if ( (*n) -> m_Val < x )
          n = &(*n) -> m_R;
        
				/* Moves to the left subtree */
				else
          n = &(*n) -> m_L;
      }
			
			/* No node found */
      return false;

    }
	
		/* Checks if element is in set, return true if the element is in the set and false if it isn't */
    bool isSet  ( const T_ & x ) const
    {
      CNode * n = m_Root;
      
			/* Simple traversal of binary tree */
      while ( n )
      { 
        if ( n -> m_Val == x )
          return true;
        else if ( x < n -> m_Val )
          n = n -> m_L;
        else
          n = n -> m_R;
      }

      return false;
    }

		/* Returns size */
    size_t Size ( void ) const
    {
      return m_Size;
    }
    
		/* Operator << */
    friend std::ostream & operator << ( std::ostream & os, const CSet<T_> & x )
    {
      os << '{';
      if ( x.  m_Root )
        x.m_Root -> Print ( os, 1 );
      os << '}';
      return os;
    }
  
  private:

    class CNode
    {
      public:
        /* Constructor */
				CNode ( T_ x )
        : m_Val (std::move(x)), m_L ( nullptr ), m_R (nullptr)
        {};
				
				/* Copy constructor */
        CNode ( const CNode & src )
        : m_Val ( src.m_Val ), 
        m_L ( src. m_L ? src.m_L -> clone () : nullptr ), 
        m_R ( src.m_R ?  src.m_R -> clone () : nullptr )
        {};
				
				/* Desctuor using recursion */
        ~CNode ( void )
        {
          delete m_L;
          delete m_R;
        }
				
				/* Returns clone of Node */
        CNode * clone ( void ) const
        {
          return new CNode(*this);

        }

				/* Prints the values of set in ascending order */
        void Print ( std::ostream & os, bool isFirst ) const
        {
          if ( m_L )
          {
            m_L -> Print ( os, isFirst );
            isFirst = false;
          }

          if ( !isFirst )
            os << ',';
          
          os << m_Val;

          if ( m_R )
            m_R -> Print ( os, 0 );
        }

        T_ m_Val;
        CNode * m_L;
        CNode * m_R;
    };

    CNode * m_Root;
    size_t m_Size;
};


