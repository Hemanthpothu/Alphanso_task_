# Alphanso_task
Tree Coloring
Signature
static void TreeColor(Node tree)
class Node
{
public Node Left;
public Node Right;
public char Color;
}

Color up the nodes of the tree in the following way:
● Inner nodes: Colored green (set the value of Color to ‘G’)
● Outer nodes: Starting from the root, moving anticlockwise, color the outer nodes in
alternating fashion (Blue ‘B’ followed by Red ‘R’)
Requirements
● Working code that passes the given test cases. Any programming language is fine.
● Unit tests, including corner cases and at least one additional case not provided in this
document.
● Basic explanation of the algorithm including its space and runtime complexity plus any
assumptions made about the input.

# Solution Approach:


# Constructing the Binary Tree: 
Taken 't' test cases :
The input array is used to construct the binary tree. Nodes are created according to the array values. Nodes that should be NULL (0 in the array) are skipped during construction. All nodes are initially colored green ('G').

# Coloring Outer Nodes: 
The goal is to color the outer nodes of the tree in an anticlockwise manner with Blue ('B') and Red ('R') alternately.

# Handling Right Outer Nodes: 
To prevent issues with the right view traversal, right outer nodes (nodes in the rightmost path) are stored in a set. This ensures that a single rightmost node is considered in the left traversal.

# Coloring Left View: 
Left side traversal starts by coloring nodes with alternating blue and red, ensuring the last node of the left view is the first node of the bottom view.

# Coloring Bottom View: 
Leaf nodes (bottom view) are collected from left to right and colored alternately with Blue('B') and Red('R').

# Coloring Right View: 
Finally, the right view is traversed, and nodes are colored alternately with Blue('B') and Red('R')., starting from the last node of the bottom view.

# Remaining Inner Nodes: 
All remaining internal nodes of the tree are left in their default green color.

This approach ensures that the binary tree is colored as specified, with outer nodes following an anticlockwise pattern of blue and red, while inner nodes remain green.

# Output Format:
Printing the respective color of Nodes of the Binary tree

# Attached the some corner sample test cases with the respective output



