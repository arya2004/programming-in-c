    int a = 05312; //base 8 %o
    int a = 332u, 01234U //unsigned
    int b = 0xA;//base 16 %x,  %p also works
    float z = 3.4e4; //exponent %g 
    int c = 0b1011; // binary
    // %u prints unsigned integer
    printf("%2i",n);//change field width specification.right justification. %3i,%6f,etc can be used
    // %-2i means left justified
    //%.3i Displays zeros in blank space. usefull for cashier related shit
    %.3f // prints only 3 decimal places
    %15.5f //15 place resered for float. 5 place for decimal,1 for point and 9 for int part
    for (; i < count; i++,j = j - 10)//any field in for loop can be kept blank or even multiple variables can be defined
    (float) a // temporarily makes 'a' a float.'a' becomes its original data type after this.(int) (double)
    == //Equality test// 
    = // assignment operator
    && // AND operator
    || // INCLUSIVE OR operator
    '1', '0','4' are characters not numbers
    //use break in every switch case. No two case value should be sAME
    (condition ? expression_1 : expression_2)//(condition ? then execute this : else execute this)tERNARY OPERATOR. Can be nested
    int size = sizeof(arr) / sizeof(arr[0]); // size of array whose size isnt defined by default
    puts(string) //prints the string inside bracket
    //There is no bound checking in C.
    strcpy(name1,name2)//copies string name2 to name1. From #include<string.h>
    strcat(destination,source)//concatinates string name2 to name1. From #include<string.h>
    int min(int val[100]){      minimum(grade_score) //grade score is defined as array in main. To pass an array in funciton
        return(min_value);
    }
    //global cariables have default initial vaue zero. local variables dont have it zero and is set to garbage value.
    // to define global variable, define variable below #include<>
    scanf("%50s", s1) //Reads string of size under 50 only
    //Every programmee you write, execution starts at main function. usefull for structure programming, reusability,necessity to work in group
    //Implicit conversion: C converts int to float if int is input for float
    //pass by value: unless used pointers, local variable in function gets equated to variables in main. 
    gets(string) // like scanf("%s", string), but includes words with spaces in one string
    //in C, local variables are prioritized over global. eg: a local k and global k in main, all operations are performed in main after local decelaration are performed on local variablle.
    //variable is global is to all function beow it
    //static var are local, if declared in for loop, its undegined outside loop
//logical and & requires binary operator, addres wala is unary operator
    fflush(stdin) //cleans input buffer. before gets and after scanf
    1)what is a pointer? it is a variable that stores address of some other variale
    declaration: <data type> *<varname>
    char *c, float *f;   
    int x;
    int *ii = &i;
    '*' means value at address.
    * should be used only time of declaration. 
    print(*p) prints value at address
    *p = *p + 5  adds 5 to x
    

pointer operations
1) pointer variables do not behave as normal variables when operated by various operatios
2) only few are allowed. they also have their own behaviour

assignment operation
int x,*p,*q
p = &x;
q = p;

add/sub
int x,*p,*q
p = &x;
q = p + 5;  //it jumps by five*(4 bit) = 20byte address
//new address = old address +/- (size of pointer)*no. of steps
// add to pointer is pointer
// sub of 2 pointer is integer
int *p - int * q == (value of p - value of q ) / 4
//with pointers, the called function can change the value of variables in caling function
//for this it is necssary to pass address of that cariable to called function
//comparison of pointers is allowed
printf("%p")  //for pointers

//Difference btwn array and pointer
1) There is a memory associated with an array. no memory assiciated with pointer
2) p1,p2,p3 are pointer variables. whereas array name 'A' is pointer constant
a++ doesnt work whereas p++ doesnt give error. 'a' points at a[0] 

//while passing array to function, int l[10] is same as int l[9] as int l[5] as int l[] as int l[200]
//it only takes a pointer to address of a[0] aka int *x
//pointer version work faster than non pointer.


Dynamic Memory Allocation
malloc()
exit(0) //normal programme terminaton
exit(1)  //programme failled


//struct
&student.marks //address
//      .  has higher precedence than &
& Bitwise AND
| Bitwise OR
^ Bitwise XOR
~ ones compliment
<< left shift
>> right  shift

if (a & 1)//tells odd/even. ONly for unsigned bits
files

fopen("", "")
first papameter is name of file with relative address by default
second parameter is "r" for read, "w" for write(clears prev input) and "a" for append(doesnt clears prev input)
fopen() returns file pointer if connection is est. returns NULL if connection isnt established
if file doenst exists and is in read mode, fopens() returns NULL
feof() if end of file reached returns true
text files end with -1
//storing to .bin is easier than .txt
only two func for .bin
fread() 
fwrite()
struct sudent *s[1000] is array of pointer to structure

ieee format 1 bit for sign, 8 for exponent, 23 for base
23.982 is converted to binary
//any non integer constants are double by default

53
55
54
58
61
58
32
371
19
16
22
15
72
1157