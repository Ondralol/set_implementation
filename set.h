#include <iostream>
#include <iomanip>

/* Custom template set implementation as Binary Search Tree (BST) */
template <typename T_>
class  CSet
{
   /* Constructor */
	 CSet ( void );
   
	 /* Desctrucor */
   ~CSet( void );
    
		/* Copy constructor */
    CSet ( const CSet<T_> & src );

		/* Copy assignment operator */
    CSet & operator = ( CSet<T_> src) ;

		/* Inserts element if element doesn't exist yet, returns true if element was inserted and false if it already existed in the set */
    bool Insert ( T_ x );

    /* Deletes node, returns true if the node exists and false if it doesn't */
    bool Delete ( const T_ & x );

		/* Checks if element is in set, return true if the element is in the set and false if it isn't */
    bool isSet  ( const T_ & x ) const;

		/* Returns size */
    size_t Size ( void ) const;

		/* Operator << */
    friend std::ostream & operator << ( std::ostream & os, const CSet<T_> & x );
  
    class CNode
    {
      public:
        /* Constructor */
				CNode ( T_ x );

				/* Copy constructor */
        CNode ( const CNode & src );

				/* Desctuor using recursion */
        ~CNode ( void );

				/* Returns clone of Node */
        CNode * clone ( void ) const;

				/* Prints the values of set in ascending order */
        void Print ( std::ostream & os, bool isFirst ) const;

        T_ m_Val;
        CNode * m_L;
        CNode * m_R;
    };

    CNode * m_Root;
    size_t m_Size;
};

