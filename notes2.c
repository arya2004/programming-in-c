//Sem 2
abstract data struct: format/blueprint of data struct upon which operation can be performd

stach:
push- add to last
pop- delete last
isEmpty- true if stach is empty. used before pop to check uderflow
isFull()- true if stach is full. used before push to check overflow
peek()- returns top most element of stackass
associtivity of exponent is right ot left
operatio precedence: () >  '^' >  '*/'  > '+-'

infix to Postfix:
1]Print the operand as they arrive.
2]If the stack is empty or contains a left parenthesis on top, push the incoming operator on to the stack.
3]If the incoming symbol is '(', push it on to the stack.
4]If the incoming symbol is ')', pop the stack and print the operators until the left parenthesis is found.
5]If the incoming symbol has higher precedence than the top of the stack, push it on the stack.
6]If the incoming symbol has lower precedence than the top of the stack, pop and print the top of the stack. Then test the incoming operator against the new top of the stack.
7]If the incoming operator has the same precedence with the top of the stack then use the associativity rules. 
    If the associativity is from left to right then pop and print the top of the stack then push the incoming operator. If the associativity is from right to left then push the incoming operator.
8]At the end of the expression, pop and print all the operators of the stack

infix to Prefix:
1]Print the operand as they arrive right to left.
2]If the stack is empty or contains a left parenthesis on top, push the incoming operator on to the stack.
3]If the incoming symbol is '(', push it on to the stack.
4]If the incoming symbol is ')', pop the stack and print the operators until the left parenthesis is found.
5]If the incoming symbol has higher precedence than the top of the stack, push it on top of the stack.
6]If the incoming symbol has lower precedence than the top of the stack, pop and print the top of the stack. Then test the incoming operator against the new top of the stack.
7]If the incoming operator has the same precedence with the top of the stack then push directly
8]At the end of the expression, pop and print all the operators of the stack
9] Reverse the output


Queue: 
isFull()//rare == size-1
 isEmppty() //fornt > rare or front == -1
enqueue() //insert element
dequeue()  //delete from front
front()  //returns front element.-1 initialized  [front,,,,,,rare]
rare() //returns rare eleent. -1 initialized
size()  //returns no of elements. rare-front + 1
display() // from front to rare printf

double ended queue:
    elements can be deleted from both front and rare;
    circular array used to represent this
    enqueue_front();
    enqueue_rare();//normie
    dequeue_front();//normie
    dequeue_rare();
    display();
    fonrt();
    rare();

input restricted double neded queue: enqueue one, dequeue both
output restricted double neded queue: dequeue one, enqueue both

linked list:

[data, link]
end node contains null pointer

insertion & deletion:       
    
types:
simple  [data, ptr]
doubly  [ptr prev address, data, ptr next address]
circular  ptr of last element points at first element
//In C, not manditory to typecast void pointer
//LL is stored in heap memory
insert beginning:
    temp->link = head;
    head = ptr;
//HW 19-04-2023 