// Pseudo code

// when we have to print all the subsequences ans update the parameter in main function
void recursion(parameters) {
    // base case
    if(base case is true) {
        if(condition is satisfied) {
            update the answer parameter;
        }
        return ;
    }

    // include wala call
    recursion(parameters);

    // exclude wala call
    recursion(parameters);
}

// when we have to find only 1 subsequence
bool recursion(parameters) {
    // base case
    if(base case is true) {
        if(condition is satisfied) return true;
        if(coondition is not satisfied) return false;
    } 

    // include wala call
    add something...
    if(recursion(paremeters) == true) return true;
    remeove what was added...

    // exclude wala call
    if(recursion(parameter) == true) return true;

    return false;
}

// when we have to count the number of subsequences
int recursion(paremeters) {
    // base case
    if(base case is true) {
        if(condition is satisfied) return 1;
        if(conditions is not satisfied) return 0;
    }

    // include wala call
    int left = recursion(parameters);
 
    // exclude wala call
    int right = recursion(parameters);

    return left + right;
}