# Task

Ada the Ladybug has decided to do some "Spring Cleaning". As you might know, she keeps a TODO list. She is very sparing so she keeps all her activities as one string. You might get very confused while reading the string but she has a system - every activity has length exactly K characters. Sadly, as new activities were added to the list many duplicities appeared. Now it is time to find out how many unique activities are in her TODO list.

# Input

First line contains T, number of test-cases.

Each test-case begins with N, K, 1 ≤ K ≤ N ≤ 105, length of string and length of activites respectively.

Next line consists of string of length N, consisting of lowercase letters.

The sum of lengths of strings among all test-cases won't exceed 3 * 1e5

# Output

For each test-case, print the number of unique substrings of length K

# Examples

## Input

5
3 2
aaa
5 1
abcba
4 2
abac
10 2
abbaaaabba
7 3
dogodog

## Output

1
3
3
4
4
