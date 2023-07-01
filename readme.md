#99 Problems
##Problem # 28(a)
Problem Statement: We suppose that a list contains elements that are lists themselves. The objective is to sort the elements of this list according to their length. E.g. short lists first, longer lists later, or vice versa. 
Solution approach: As sorting was involved so i can sort using multiple sorting algorithms and sort on bases of size of subarrays in the given array so I used insertion sort. 
Challenges/Problems: Only challenge was to change problem to sort on basis of size of subarra instead of sorting a 1D array

**##Problem # 28(b)**
**Problem Statement:** we suppose that a list contains elements that are lists themselves.  But this time the objective is to sort the elements according to their length frequency; i.e. in the default, sorting is done ascendingly, lists with rare lengths are placed, others with a more frequent length come later.
(lfsort '((a b c) (d e) (f g h) (d e) (i j k l) (m n) (o)))
returned ouput like: ((i j k l) (o) (a b c) (f g h) (d e) (d e) (m n))
**Solution approach:** Again sorting was involved but the process was not the same. Now it is length frequency. Also the length is of the row which has to be observed. Solution approach's initial process was like counting sort: I first intialised an array whose index is the available lengths and then value of that index will be the number of rows having those lengths. Then, I did not used counting sort further, as counting sort sorts by index value but I wanted to sort by occurances(length frequncy),    but instead I used max value from array to further solve the problem which can be viewed in code
**Challenges/Problems:** The code was quite challenging for me because I started as counting sort but left it the halfway and devised my own technique which would also solve the problem. There were a lot of difficulties in devising that strategy and after a lot of continuous errors, which were mainly due to negligence of minor things like what if two different lengths occur the same time etc., my strategy worked and was perfect


**##Problem # 35**
**Problem Statement:** Construct a flat list containing the prime factors in ascending order. 
**Solution approach:** I simply observed the mathematical approach and simply employed that into the program that is: start dividing the number from 2, if the number divides then again check that it divides by 2 and further and if at any point the number does not divide by 2, increment the divisor to 3 and repeat the steps but remember to increment it to another prime number 
**Challenges/Problems:** No such challenge instead of checking the math of the problem

**##Problem # 36**
**Problem Statement:** Construct a list containing the prime factors and their multiplicity.
**Solution approach:** Same approach as problem 35. Only change is to now return array of tuples for which only check is added so that if element is already present then, specific element counter updated
**Challenges/Problems:** No such challenge instead of checking the math of the problem