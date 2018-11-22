
1. code implementation

Method 1: Violence traversal method, Time complexity O(n^2), Space complexity O(0)

traverse array twice. Summed, compared, and output is equal.


Method 2: Hash Map, Time Complexity O(n), Space Complexity O(n)

Traverse array once.

Use a hash map in the loop, and store the difference as a hash key and an array subscript as a hash value in the map. When the hash value is equal to a value of the array afterwards, the purpose is reached. Return the hash value and array subscript at the moment.

Method 2 uses "auto" to simplify the form of the iterator, so it takes twice the time (8ms) to dynamically judge.

Methord 3 is directly using the subscript operation, thus reducing the time (4ms).

The two methods have the same idea, and the emplace function is used to reduce the number of constructions, saving space and time.


2. new knowledge points

2.1 unordered_map hash map

Replace the hash_map with unordered_map, as recommended by the C++ 11 STL standard.

A hash table is a data structure that is accessed directly based on a key value. That is, it accesses the record by mapping the key value to a location in the map to speed up the lookup. This mapping function is called a hash function.

In STL, the data structure corresponding to map is a red-black tree. The red-black tree is a binary search tree that approximates equilibrium. The data inside is ordered. The time complexity for doing a lookup operation on a red-black tree is O(logN). The unordered_map corresponds to the hash table. The hash table is characterized by high efficiency, time complexity is constant level O(1), and extra space complexity is much higher. So for situations that require efficient queries, use the unordered_map container. If you are sensitive to memory size or data storage is required, you can use the map container.


2.2 emplace function features

The push_back of the vector, the insert of the map, and the insert of the set all involve two constructs. The first is the initial construct of the object, which is then copied once during the insert, triggering the copy construct. But many times we don't need two constructions to waste efficiency. If we can construct directly when inserting, we only need to construct once.

The C++11 standard already has such a syntax that can be used directly, and that is emplace.

The vector.push_back() statement executes the constructor first, then the copy construct is copied to the vector, and the temporary object is destroyed. Both emplace_back() and emplace() call the constructor only once.

The set.insert() statement performs two constructions, one destructor. The emplace() statement only performs one construction.

Through the above analysis, in the development process, if you use emplace to achieve results, you should try to use emplace. In particular, the use of a large number of statements such as push_back and insert can improve the efficiency of the program as a whole.

The relevant grammar is summarized as follows:

Vector:

Emplace <-> insert

Emplace_back <-> push_back


Set

Emplcace <-> insert


Map

Emplace <-> insert


2.3 Dynamic declaration of auto variables

Auto is a keyword for the C++ programming language. Used in two cases:

1) When declaring a variable, the type of the variable is automatically inferred based on the initialization expression.
2) A placeholder for the function return value when the function is declared.

Simple variable declaration type, it is not recommended to use the auto keyword, but should write its type directly more clearly. The auto keyword is more suitable for types of verbose and complex, and the scope of use of variables is more specific, making the program clearer and easier to read.

Advantage:

1) Simplify the code when you have a complex type variable declaration with an initialization expression.

#include <string>
#include <vector>
Void loopover(std::vector<std::string>&vs) {
    Std::vector<std::string>::iterator i=vs.begin();
    For(;i<vs.end();i++) { }
  
}

#include <string>
#include <vector>
Void loopover(std::vector<std::string>&vs) {
    For( auto i=vs.begin();;i<vs.end();i++) { }
  
}

Using std::vector<std::string>::iterator to define i is a good habit for C++, but such long declarations make it difficult to read the code, so introducing auto makes the code more readable. . And using STL will be easier

2) You can avoid the trouble of type declaration and avoid errors when type declaration.


note:

1) auto can't solve all the precision problems, such as large integers. This feature is not the same as the automatic expansion of data hi in dynamic type languages.

2) You can decorate auto with valatile, pointer(*), reference(&), rvalue reference(&&).

Auto k = 5;
Auto* pK = new auto(k);
Auto** ppK = new auto(&k);
Const auto n = 6;

3) Variables declared with auto must be initialized

Int* p = new auto(0); //Fine
Int* pp = new auto(); // Should be initialized
Auto x = new auto(); // Hmmm ... no intializer
Auto* y = new auto(9); // Fine. Here y is a int*
Auto z = new auto(9); //Fine. Here z is a int* (It is not just an int)
4) auto cannot be combined with other types of combinations
5) Function and template parameters cannot be declared as auto
6) Variables defined on the heap, expressions using auto must be initialized

7) Variables defined in an auto sequence must always be derived into the same type

Auto x1 = 5, x2 = 5.0, x3='r’;
 /<span style="font-family: Arial, Helvetica, sans-serif;">/error, must be initialized to the same type</span>

8) auto cannot be automatically derived into CV-qualifiers (constant & volatile qualifiers)

9) auto will degenerate into a pointer to an array unless it is declared as a reference
