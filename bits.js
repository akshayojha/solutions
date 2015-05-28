/*
  bits.js
  Problem Statement: http://codeforces.com/problemset/problem/484/A
  Using Google's v8 engine
*/
// Take input- the number of test cases
var test_cases = parseInt(readline());
while(test_cases>0) {
    // Take inputs from same line
    var numbers = readline().split(" ").map(function(x) { return parseInt(x); });
    var left = numbers[0];
    var right = numbers[1];
    var index = 0;
    // Start with left number and set its bits to 1 from LSB
    while ((left | 1<< index) <= right) {
	    left |= (1 << index);
	    index++;
    }
    // Print answer in console
    print(left);
    test_cases--;
}
