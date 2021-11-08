<h1>Binary Tree :</h1>
<h2>In computer science, a binary tree is a tree data structure in which each node has at most two children, which are referred to as the left child and the right child. ... It is also possible to interpret a binary tree as an undirected, rather than a directed graph, in which case a binary tree is an ordered, rooted tree.</h2>

<img src="https://cdn.shortpixel.ai/client/to_avif,q_glossy,ret_img,w_1880/https://simplesnippets.tech/wp-content/uploads/2020/10/binary-tree-vs-binary-search-tree-diagram.png">

<h1>Height of Binary Tree = 2^(h+1)-1</h1>
<h1>Balance Binary Tree :</h1>
<h2>Height-balanced binary tree : is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. Example : Input : 1 / \ 2 3 Return : True or 1 Input 2 : 3 / 2 / 1 Return : False or 0 Because for the root node, left subtree has depth 2 and right subtree has depth 0.</h2>
<h1>Dense Tree and Sparse Tree:</h1>
<h2>A dense binary tree is close to perfect (it has close to 2^(h + 1) - 1 nodes) . A sparse tree is closer to a linked list (it has close to h nodes). h is the height of the tree where a single root node has height 0.</h2>
<h2>Note : In Sparse tree the time required should be high.</h2>
<h1>How we Implement Binary Tree data Structure :</h1>
<h2>Binary trees can be implemented using pointers. A tree is represented by a pointer to the top-most node in the tree. If the tree is empty, then the value of the root is NULL. ... Pointer to the left child.</h2>
<h2>1. Binary Tree as dynamic nodes in Memory be: </h2>
<h3>Node(*left,data,*right)</h3>
<h2>2. Binary tree as Conventional Arrays:</h2>
<h3>For node at index i:</h3>
<h3>Left Child Index = 2i+1 and Right child index= 2i+2</h3>