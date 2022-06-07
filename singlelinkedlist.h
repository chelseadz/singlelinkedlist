struct node {
  int e;
  struct node* next;
};

/**
 * appends an element to the end of the list. For example, given the list 
 * [1,2,3], when this function is invoked as:
 *
 *   append(&l, 4);
 *
 * the list needs to have [1,2,3,4].
 *
 * This function runs in O(1).
 *
 * @return 0 on success, 1 if an error occurred
 */
int append(struct node* list, int e);


/**
 * removes the element at index i. For example, given the list [1,2,3], invoking 
 * this function as:
 *
 *    remove(&l, 1);
 *
 * causes the list to have [1,3]
 *
 * This function runs in O(1)
 *
 * @return 0 on success, 1 if the list is empty, 2 if there is any other error
 */
int remove_at(struct node** list, int i);


/**
 * inserts an element at index i. For example, given the list [1,3], invoking 
 * this function as:
 *
 *    insert(&l, 10, 1);
 *
 * causes the list to have [1,10,3]
 *
 * This function runs in O(1)
 *
 * @return 0 on success, 1 if there is an error
 */
int insert_at(struct node** list, int e, int i);


/**
 * inverts the order of the list. For example, if the list is [1,2,3], this 
 * function returns the list in the order [3,2,1].
 *
 * This function runs in O(n)
 *
 * @return 0 on success, 1 if there is an error
 */
int reverse(struct node** list);
