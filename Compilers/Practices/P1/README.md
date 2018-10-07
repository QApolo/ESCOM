# General Automaton
*Receives as input a file containing the description of the automata*

* Set of states separated by comma
* alphabet
* initial state
*  set of final states separated by comma
* desctiption of Delta function
    described by a list separated by a new line containing: 
        current_state, element_from_alphabet, next_state
    
## EXAMPLE
```
0,1,2
a,b
0
2
0,a,0
0,a,1
0,b,0
1,b,2
```
