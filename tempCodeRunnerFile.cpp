Node* root = newNode('a');
    root->subtrees = {newNode('b'),newNode('c'),newNode('d')};
    root->subtrees[0]->subtrees = {newNode('e'),newNode('f'),newNode('g')};
    root->subtrees[1]->subtrees = {newNode('h'),newNode('i'),newNode('j')};
    root->subtrees[2]->subtrees = {newNode('k'),newNode('l')};