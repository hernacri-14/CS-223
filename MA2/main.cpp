/*
 * Part A: Conceptual Questions
 * 1. What is a move constructor?
 *    - A move constructor is a special constructor that transfers ownership of resources from a temporary object (rvalue) to a new object. Instead of deep copying, it efficiently moves data by transferring pointers, leaving the source object in a valid but empty state.
 *
 * 2. What is a move assignment operator?
 *    - A move assignment operator transfers ownership of resources from an rvalue object to an existing object. It first deallocates the current object's resources, then moves the data from the source object, ensuring efficient assignment operations.
 *
 * Part B: Big-O Analysis
 * 1. BST::empty() - O(1) 
 *    - Checking if the root is null is a constant-time operation.
 * 2. BST::add() - O(log n) on average, O(n) worst-case (unbalanced tree)
 *    - Inserting an element requires traversing the tree, which is logarithmic in a balanced BST.
 * 3. BST::makeEmpty() - O(n)
 *    - Recursively deletes all nodes, visiting each once.
 * 4. BST::printLevelOrder() - O(n)
 *    - Uses a queue to visit each node once, making it linear.
 * 5. BST::cloneTree() - O(n)
 *    - Recursively copies all nodes, visiting each exactly once.
 */





#include <iostream>
#include "BST.h" 

int main(){

	/* MA TODO: Implement */
	/* Create a BST string tree (bst_test) ; add the following string values to the bst_test in order: "C", "p", "t", "s", "2", "3" , "B", "S", "T"*/

	BST<std::string> bst_test;
    bst_test.add("C");
    bst_test.add("p");
    bst_test.add("t");
    bst_test.add("s");
    bst_test.add("2");
    bst_test.add("3");
    bst_test.add("B");
    bst_test.add("S");
    bst_test.add("T");

	/* MA TODO: Implement */
	// Test1: Test printLevelOrder()
	/* Print the tree you created using
	    a. In-order print
	    a. Level-order print
	    a. Post-order print
	    a. Pre-order print */

	cout << "In-Order: ";
	bst_test.printInOrder();
	cout << "\nLevel-Order: ";
	bst_test.printLevelOrder();
	cout << "\nPost-Order: ";
	bst_test.printPostOrder();
	cout << "\nPre-Order: ";
	bst_test.printPreOrder();
	cout << "\n";

	/* MA TODO: Implement */
	// Test2: Test copy constructor -1
	/* Create a new BST tree (bst_copy1) ; initialize bst_copy1 with 'bst_test's data, using the copy constructor */
	/* Test condition: Check if the size of bst_copy1 is same as bst_test; and  bst_copy1 contains the values "B", "S", "T" 
	    * if so, print the mesaage: "Copy constructor test-1 passed!"";
		* else *print the message: "Copy constructor test-1 failed!"" and print both bst_test and bst_copy1 using level order print.*/

	BST<std::string> bst_copy1 = bst_test;
    if (bst_copy1.size() == bst_test.size() && bst_copy1.contains("B") && bst_copy1.contains("S") && bst_copy1.contains("T")) {
        cout << "Copy constructor test-1 passed!\n";
    } else {
        cout << "Copy constructor test-1 failed!\n";
        bst_test.printLevelOrder();
        bst_copy1.printLevelOrder();
    }

	/* MA TODO: Implement */
	// Test3: Test copy constructor - 2
	/* Update one of the strings in bst_copy1 tree using the following statement:  */
	   // bst_copy1.getNode("B")->setValue("A");
	/* Assuming copy constructor does a deep copy, the above statement should update bst_copy1 only, and not bst_test. */
	/* Test condition: 
	    * if bst_test contains "B" and it doesn't contain "A", test passes. Print the message: "Copy constructor test-2 passed!"";
		* else *print the message: "Copy constructor test-2 failed!"" and print bst_test using level order print.*/
	
	bst_copy1.getNode("B")->setValue("A");
	if (bst_test.contains("B") && !bst_test.contains("A")) {
		cout << "Copy constructor test-2 passed!\n";
	} else {
		cout << "Copy constructor test-2 failed!\n";
			bst_test.printLevelOrder();
	}

	/* MA TODO: Implement */
	// Test4: Test copy assignment
	/* Create a new BST tree (bst_copy2) ; initialize bst_copy2 with 'bst_test's data, using the copy assignment operator. */
	/* Test condition: Check if the size of bst_copy2 is same as bst_test and  bst_copy2 contains the values "B", "S", "T" 
	    * if so, print the mesaage: "Copy assignment operator test passed!"";
		* else *print the message: "Copy assignment operator test failed!"" and print both bst_test and bst_copy2 using level order print.*/

	BST<std::string> bst_copy2;
	bst_copy2 = bst_test;
	if (bst_copy2.size() == bst_test.size() && bst_copy2.contains("B") && bst_copy2.contains("S") && bst_copy2.contains("T")) {
		cout << "Copy assignment operator test passed!\n";
	} else {
		cout << "Copy assignment operator test failed!\n";
		bst_test.printLevelOrder();
		bst_copy2.printLevelOrder();
	}

	/* MA TODO: Implement */
	// Test5: Test move constructor
	/* Create a new BST tree (bst_move1) ; initialize bst_move1 with 'bst_test's data, using the move constructor */
	/* Test condition: Check if the size of bst_move1 is 9 and  bst_move1 contains the values "B", "S", "T", and bst_test is empty (use the empty() function of BST to check if bst_test is empty.).  
	    * if so, print the mesaage: "Move constructor test passed!"";
		* else *print the message: "Move constructor test failed!"" and print bst_move1 using level order print.*/

	BST<std::string> bst_move1 = std::move(bst_test);

	if (bst_move1.size() == 9 && bst_move1.contains("B") &&
		bst_move1.contains("S") && bst_move1.contains("T") &&
		bst_test.empty()) {
		cout << "Move constructor test passed!\n";
	} else {
		cout << "Move constructor test failed!\n";
		bst_move1.printLevelOrder();
	}

	/* MA TODO: Implement */
	// Test6: Test move assignment 
	/* Create a new BST tree (bst_move2) ; initialize bst_move2 with rvalue BST<string>({"B","S","T"}), using the move assignment operator */
	/* Test condition: Check if the size of bst_move2 is 3 and  bst_move2 contains the values "B", "S", "T". 
	    * if so, print the mesaage: "Move assignment operator test passed!"";
		* else *print the message: "Move assignment operator test failed!"" and print  bst_move2  using level order print.*/

	BST<std::string> bst_move2;
	bst_move2 = BST<std::string>({"B", "S", "T"});
	if (bst_move2.size() == 3 && bst_move2.contains("B") && bst_move2.contains("S") && bst_move2.contains("T")) {
		cout << "Move assignment operator test passed!\n";
	} else {
		cout << "Move assignment operator test failed!\n";
		bst_move2.printLevelOrder();
	}

	return 0;
}