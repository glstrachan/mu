/* Generates a compressed trie in the form of a 1D integer array */
/* First node is head node */
/* Next element denotes whether reaching that node is an identifier */
/* Next element is the number of children N that node has */
/* Next N * 2 elements are number pairs */
/* The first number in the pair is the child character as an int */
/* The second number in the pair is the corresponding index in the array for that child character */