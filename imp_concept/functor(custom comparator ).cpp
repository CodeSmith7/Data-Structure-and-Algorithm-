struct Compare {
    bool operator()(const mark &a, const mark &b) const {
        if (a.phy != b.phy) {
            return a.phy < b.phy;
        } else if (a.chem != b.chem) {
            return a.chem > b.chem;
        } else {
            return a.math < b.math;
        }
    }
};

// In this code, Compare is a struct that overloads the operator(). The overloaded operator takes two mark objects as parameters and compares them based on certain conditions.
//The const keyword at the end of the function declaration means that this function does not modify any member variables of the Compare struct.

// Now, let’s look at how this functor is used:

sort(ans.begin(), ans.end(), Compare());

// In this line, std::sort is a function from the Standard Template Library (STL) that sorts a range of elements.
//It takes three arguments: two iterators representing the range to sort, and a comparison function to determine the order of the elements.

// In this case, ans.begin() and ans.end() represent the range of elements to sort, and Compare() is an instance of the Compare functor, which is used as the comparison function.
//When std::sort needs to compare two elements, it calls the Compare functor, which in turn calls the overloaded operator().

// So, in essence, a functor allows you to create objects that “act like” functions.
//These are particularly useful when you want to maintain state across several invocations of a function-like object, or when you want to parameterize the behavior of a function-like object at its creation, among other things. 
