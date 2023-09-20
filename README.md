# Alphanso_task_
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
