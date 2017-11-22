#ifndef __ArrayList
#define __ArrayList
struct ArrayList{

    void** pElements;
    int size;
    int reservedSize;

    int     (*add)();
    int     (*len)();
    int     (*contains)();
    int     (*set)();
    int     (*remove)();
    int     (*clear)();
    int     (*push)();
    int     (*indexOf)();
    int     (*isEmpty)();
    void*   (*get)();
    void*   (*pop)();
    int     (*containsAll)();
    int     (*sort)();
    struct ArrayList* (* clone)();
    struct ArrayList* (*subList)();
    int     (*deleteArrayList)();

}typedef ArrayList;
#endif

// FUNCIONES PRIVADAS
int resizeUp(ArrayList* this);
int resizeDown(ArrayList* this);
int expand(ArrayList* this, int index);
int contract(ArrayList* this, int index);


/** \brief Allocate a new ArrayList with AL_INITIAL_VALUE elements.
 * \param Void.
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new ArrayList) if ok
 */
ArrayList* al_newArrayList(void);


/** \brief  Add an element to ArrayList and if is
 *          nessesary resize the array
 * \param this ArrayList* Pointer to ArrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [this or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* this,void* pElement);


/** \brief  Delete ArrayList
 * \param this ArrayList* Pointer to ArrayList
 * \return int Return (-1) if Error [this is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* this);


/** \brief  Measure ArrayList
 * \param this ArrayList* Pointer to ArrayList
 * \return int Return length of array or (-1) if Error [this is NULL pointer]
 *
 */
int al_len(ArrayList* this);


/** \brief  Get an element by index
 * \param this ArrayList* Pointer to ArrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [this is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* this , int index);


/** \brief  Find if this contains at least one element pElement
 * \param this ArrayList* Pointer to ArrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [this or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* this, void* pElement);


/** \brief  Set a element in this at index position
 * \param this ArrayList* Pointer to ArrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [this or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* this, int index,void* pElement);


/** \brief  Remove an element by index
 * \param this ArrayList* Pointer to ArrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [this is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* this,int index);



/** \brief Removes all of the elements from this list
 * \param this ArrayList* Pointer to ArrayList
 * \return int Return (-1) if Error [this is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* this);


/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param this ArrayList* Pointer to ArrayList
 * \return ArrayList* Return  (NULL) if Error [this is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* this);


/** \brief Inserts the element at the specified position
 * \param this ArrayList* Pointer to ArrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [this or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* this, int index, void* pElement);



/** \brief Returns the index of the first occurrence of the specified element
 * \param this ArrayList* Pointer to ArrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [this or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* this, void* pElement);



/** \brief Returns true if this list contains no elements.
 * \param this ArrayList* Pointer to ArrayList
 * \return int Return (-1) if Error [this is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* this);



/** \brief Remove the item at the given position in the list, and return it.
 * \param this ArrayList* Pointer to ArrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [this is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* this,int index);



/** \brief Returns a new ArrayList with a portion of this between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param this ArrayList* Pointer to ArrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [this is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* this,int from,int to);



/** \brief Returns true if this list contains all of the elements of this2
 * \param this ArrayList* Pointer to ArrayList
 * \param this2 ArrayList* Pointer to ArrayList
 * \return int Return (-1) if Error [this or this2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* this,ArrayList* this2);


/** \brief Sorts objects of list, use compare pFunc
 * \param this ArrayList* Pointer to ArrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of ArrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [this or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* this, int (*pFunc)(void* ,void*), int order);



/** \brief Increment the number of elements in this in AL_INCREMENT elements.
 * \param this ArrayList* Pointer to ArrayList
 * \return int Return (-1) if Error [this is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* this);


/** \brief  Expand an array list
 * \param this ArrayList* Pointer to ArrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [this is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* this,int index);


/** \brief  Contract an array list
 * \param this ArrayList* Pointer to ArrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [this is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* this,int index);


//___________________
